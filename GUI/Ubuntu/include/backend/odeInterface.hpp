/*##############################################################################################
#                                                                                              #
#     #############       #############       #############       ####                ####     #
#    #             #     #             #     #             #     #    #              #    #    #
#    #    #####    #     #    #########      #    #####    #     #    #              #    #    #
#    #    #   #    #     #    #              #    #   #    #     #    #              #    #    #
#    #    #####    #     #    #              #    #####    #     #    #              #    #    #
#    #             #     #    #########      #             #     #    #              #    #    #
#    #             #     #             #     #             #     #    #              #    #    #
#    #    #####    #      #########    #     #    #####    #     #    #              #    #    #
#    #    #   #    #              #    #     #    #   #    #     #    #              #    #    #
#    #    #   #    #      #########    #     #    #   #    #     #    #########      #    #    #
#    #    #   #    #     #             #     #    #   #    #     #             #     #    #    #
#     ####     ####       #############       ####     ####       #############       ####     #
#                                                                                              #
#   Author: Stefano Rebughini <ste.rebu@outlook.it>                                            #
#                                                                                              #
################################################################################################
#                                                                                              #
#   License                                                                                    #
#                                                                                              #
#   This file is part of ASALI.                                                                #
#                                                                                              #
#   ASALI is free software you can redistribute it and/or modify                               #
#   it under the terms of the GNU General Public License as published by                       #
#   the Free Software Foundation, either version 3 of the License, or                          #
#   (at your option) any later version.                                                        #
#                                                                                              #
#   ASALI is distributed in the hope that it will be useful,                                   #
#   but WITHOUT ANY WARRANTY; without even the implied warranty of                             #
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #
#   GNU General Public License for more details.                                               #
#                                                                                              #
#   You should have received a copy of the GNU General Public License                          #
#   along with ASALI. If not, see <http://www.gnu.org/licenses/>.                              #
#                                                                                              #
##############################################################################################*/

#ifndef ODEINTERFACE_H
#define ODEINTERFACE_H

#include <gtkmm.h>
#include <string>
#include <iostream>
#include <math.h>
#include <ctime>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <random>

#include <cvodes/cvodes.h>
#include <sunmatrix/sunmatrix_dense.h>
#include <cvodes/cvodes_direct.h>
#include <nvector/nvector_serial.h>

#include <sunlinsol/sunlinsol_dense.h>
#include <sunlinsol/sunlinsol_band.h>
#include <sundials/sundials_dense.h>
#include <sundials/sundials_types.h>

namespace ASALI
{
    #define Ith(v, i) NV_Ith_S(v, i - 1)
    #define IJth(A, i, j) DENSE_ELEM(A, i - 1, j - 1)

    template <typename T>
    class odeInterface : public Gtk::Window
    {
    public:
        odeInterface();

        int solve(const double tf, std::vector<double> &yf);

        void setEquations(T *eq);

        void setInitialConditions(double t0, std::vector<double> y0);

        void setTollerance(const double absTol, const double relTol);

        void setBandDimensions(const double upperBand, const double lowerBand);

        void setConstraints(const bool constraints);

        bool check() { return check_; };
        void start() { check_ = true; };

        ~odeInterface(void);

    private:
        void *cvode_mem_;

        T *eq_;

        int NEQ_;

        double relTol_;
        double absTol_;
        double upperBand_;
        double lowerBand_;
        double t0_;

        bool constraints_;
        bool check_;

        N_Vector yCVODE_;
        N_Vector dyCVODE_;
        N_Vector y0CVODE_;
        N_Vector dy0CVODE_;

        SUNMatrix A_;

        SUNLinearSolver LS_;

        std::vector<double> y0_;
        std::vector<double> dy0_;

        std::vector<std::string> beer_;

        int checkFlag(void *flagvalue, int opt);

        void error();
        std::string getBeer();
    };

    template <typename T>
    odeInterface<T>::odeInterface()
    {
        #include "shared/Beer.H"

        yCVODE_ = NULL;
        dyCVODE_ = NULL;
        y0CVODE_ = NULL;
        dy0CVODE_ = NULL;
        cvode_mem_ = NULL;

        constraints_ = false;
        check_ = true;

        upperBand_ = 0.;
        lowerBand_ = 0.;
        relTol_ = 1.e-07;
        absTol_ = 1.e-12;
        t0_ = 0.;
    }

    template <typename T>
    void odeInterface<T>::setEquations(T *eq)
    {
        eq_ = eq;
        NEQ_ = eq_->NumberOfEquations();

        y0CVODE_ = N_VNew_Serial(NEQ_);
        if (checkFlag((void *)y0CVODE_, 0))
        {
            this->error();
        }

        dy0CVODE_ = N_VNew_Serial(NEQ_);
        if (checkFlag((void *)dy0CVODE_, 0))
        {
            this->error();
        }

        yCVODE_ = N_VNew_Serial(NEQ_);
        if (checkFlag((void *)yCVODE_, 0))
        {
            this->error();
        }

        dyCVODE_ = N_VNew_Serial(NEQ_);
        if (checkFlag((void *)dyCVODE_, 0))
        {
            this->error();
        }

        y0_.resize(NEQ_);
        dy0_.resize(NEQ_);
    }

    template <typename T>
    void odeInterface<T>::setBandDimensions(const double upperBand, const double lowerBand)
    {
        upperBand_ = upperBand;
        lowerBand_ = lowerBand;
    }

    template <typename T>
    void odeInterface<T>::setTollerance(const double absTol, const double relTol)
    {
        absTol_ = absTol;
        relTol_ = relTol;
    }

    template <typename T>
    void odeInterface<T>::setConstraints(const bool constraints)
    {
        constraints_ = constraints;
    }

    template <typename T>
    void odeInterface<T>::setInitialConditions(double t0, std::vector<double> y0)
    {
        eq_->Equations(t0, y0, dy0_);

        t0_ = t0;
        y0_ = y0;
    }

    template <typename T>
    int equations(double t, N_Vector y, N_Vector f, void *user_data)
    {
        T *data;
        data = (T *)user_data;

        double *ydata = N_VGetArrayPointer_Serial(y);
        double *fdata = N_VGetArrayPointer_Serial(f);

        unsigned int N = data->NumberOfEquations();

        std::vector<double> y_(N);
        std::vector<double> dy_(N);

        for (unsigned int i = 0; i < N; i++)
        {
            y_[i] = ydata[i];
        }

        int flag = data->Equations(t, y_, dy_);

        for (unsigned int i = 0; i < N; i++)
        {
            fdata[i] = dy_[i];
        }

        return (flag);
    }

    template <typename T>
    int odeInterface<T>::solve(const double tf, std::vector<double> &yf)
    {
        int flag;

        N_VSetArrayPointer_Serial(&dy0_[0], dy0CVODE_);
        N_VSetArrayPointer_Serial(&y0_[0], y0CVODE_);

        cvode_mem_ = CVodeCreate(CV_BDF);
        if (checkFlag((void *)cvode_mem_, 0))
        {
            this->error();
        }

        flag = CVodeSetMaxNumSteps(cvode_mem_, 5000000);
        if (checkFlag(&flag, 1))
        {
            this->error();
        }

        flag = CVodeSetUserData(cvode_mem_, eq_);
        if (checkFlag(&flag, 1))
        {
            this->error();
        }

        flag = CVodeInit(cvode_mem_, equations<T>, t0_, y0CVODE_);
        if (checkFlag(&flag, 1))
        {
            this->error();
        }

        flag = CVodeSStolerances(cvode_mem_, relTol_, absTol_);
        if (checkFlag(&flag, 1))
        {
            this->error();
        }

        if (upperBand_ == 0 && lowerBand_ == 0)
        {
            A_ = SUNDenseMatrix(NEQ_, NEQ_);
            if (checkFlag((void *)A_, 0))
            {
                this->error();
            }

            LS_ = SUNDenseLinearSolver(yCVODE_, A_);
            if (checkFlag((void *)LS_, 0))
            {
                this->error();
            }

            flag = CVDlsSetLinearSolver(cvode_mem_, LS_, A_);
            if (checkFlag(&flag, 1))
            {
                this->error();
            }
        }
        else
        {
            A_ = SUNBandMatrix(NEQ_, upperBand_, lowerBand_);
            if (checkFlag((void *)A_, 0))
            {
                this->error();
            }

            LS_ = SUNBandLinearSolver(yCVODE_, A_);
            if (checkFlag((void *)LS_, 0))
            {
                this->error();
            }

            flag = CVDlsSetLinearSolver(cvode_mem_, LS_, A_);
            if (checkFlag(&flag, 1))
            {
                this->error();
            }
        }

        flag = CVode(cvode_mem_, tf, yCVODE_, &t0_, CV_NORMAL);
        if (checkFlag(&flag, 1))
        {
            this->error();
        }

        yf.clear();
        yf.resize(NEQ_);
        double *sol = N_VGetArrayPointer_Serial(yCVODE_);
        if (constraints_ == true)
        {
            for (int i = 0; i < NEQ_; i++)
            {
                yf[i] = std::max(0., sol[i]);
            }
        }
        else
        {
            for (int i = 0; i < NEQ_; i++)
            {
                yf[i] = sol[i];
            }
        }

        return flag;
    }

    template <typename T>
    int odeInterface<T>::checkFlag(void *flagvalue, int opt)
    {
        int *errflag;

        if (opt == 0 && flagvalue == NULL)
        {
            return (1);
        }
        else if (opt == 1)
        {
            errflag = (int *)flagvalue;
            if (*errflag < 0)
            {
                return (1);
            }
        }
        else if (opt == 2 && flagvalue == NULL)
        {
            return (1);
        }

        return (0);
    }

    template <typename T>
    void odeInterface<T>::error()
    {
        check_ = false;
        Gtk::MessageDialog dialog(*this, "Ops, something wrong happend!", true, Gtk::MESSAGE_ERROR);
        dialog.set_secondary_text(this->getBeer(), true);
        dialog.run();
    }

    template <typename T>
    std::string odeInterface<T>::getBeer()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<const unsigned int> distribution(0, beer_.size()-1);
        int i = distribution(gen);
        return beer_[i];
    }

    template <typename T>
    odeInterface<T>::~odeInterface(void)
    {
        N_VDestroy_Serial(yCVODE_);
        N_VDestroy_Serial(dyCVODE_);
        CVodeFree(&cvode_mem_);
    }

}
#endif
