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

#ifndef BVPINTERFACE_H
#define BVPINTERFACE_H

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

#include "backend/beerQuote.hpp"

#include <ida/ida.h>
#include <sunmatrix/sunmatrix_dense.h>
#include <ida/ida_direct.h>
#include <nvector/nvector_serial.h>

#include <sunlinsol/sunlinsol_dense.h>
#include <sunlinsol/sunlinsol_band.h>
#include <sundials/sundials_math.h>
#include <sundials/sundials_dense.h>
#include <sundials/sundials_types.h>

namespace ASALI
{
#define Ith(v, i) NV_Ith_S(v, i - 1)
#define IJth(A, i, j) DENSE_ELEM(A, i - 1, j - 1)

    template <typename T>
    /// Class interface for SUNDIALS IDA solver (https://computation.llnl.gov/projects/sundials)
    class bvpInterface : public Gtk::Window
    {
    public:
        /// Class constructor
        bvpInterface();

        /// Solve equations
        int solve(const double tf, std::vector<double> &yf);

        /// Set system equations
        void setEquations(T *eq);

        /// Set system initial conditions
        void setInitialConditions(double t0, std::vector<double> y0);

        /// Set system algebraic equations flag
        void setAlgebraic(const std::vector<bool> &algebraic);

        /// Set solver tollerance
        void setTollerance(const double absTol, const double relTol);

        /// Set band matrix width
        void setBandDimensions(const double upperBand, const double lowerBand);

        /// Set solver contrains
        void setConstraints(const bool constraints);

        /// Return solver output
        bool check() { return check_; };

        /// Refresh solver resolution
        void start() { check_ = true; };

        /// Class destructor
        ~bvpInterface(void);

    private:
        void *ida_mem_; /// Pointer to the IDA solver

        T *eq_; /// Template variable that describe the system equation

        int NEQ_; /// Number of equations

        double relTol_;    /// Relative tollerance
        double absTol_;    /// Absolute tollerance
        double upperBand_; /// Upper matrix band width
        double lowerBand_; /// Lower matrix band width
        double t0_;        /// Integration variable initial conditions

        bool check_;       /// Flag that shows the solver output
        bool constraints_; /// Flag to enable/disable constraints

        N_Vector yIDA_;         /// SUNDIALS vector of integrated variables
        N_Vector dyIDA_;        /// SUNDIALS vector of residuals
        N_Vector y0IDA_;        /// SUNDIALS vector of initial conditions
        N_Vector dy0IDA_;       /// SUNDIALS vector of initial residuals
        N_Vector algebraicIDA_; /// SUNDIALS vector describing the algebraic equations

        SUNMatrix A_; /// SUNDIALS matrix

        SUNLinearSolver LS_; /// SUNDIALS linear solver

        std::vector<double> y0_;        /// std::vector of initial conditions
        std::vector<double> dy0_;       /// std::vector of initial residuals
        std::vector<double> algebraic_; /// std::vector describing the algebraic equations

        std::vector<std::string> beer_; /// std::vector of beer quotes
        ASALI::beerQuote beerQuote_;    /// Point of ASALI::beerQuote object

        /// Check SUNDIALS output flags
        int checkFlag(void *flagvalue, int opt);

        /// Show errors
        void error();
    };

    template <typename T>
    bvpInterface<T>::bvpInterface()
    {
        yIDA_ = NULL;
        dyIDA_ = NULL;
        y0IDA_ = NULL;
        dy0IDA_ = NULL;
        algebraicIDA_ = NULL;
        ida_mem_ = NULL;

        constraints_ = false;
        check_ = true;

        upperBand_ = 0.;
        lowerBand_ = 0.;
        relTol_ = 1.e-07;
        absTol_ = 1.e-12;
        t0_ = 0.;
    }

    template <typename T>
    void bvpInterface<T>::setEquations(T *eq)
    {
        eq_ = eq;
        NEQ_ = eq_->NumberOfEquations();

        y0IDA_ = N_VNew_Serial(NEQ_);
        if (checkFlag((void *)y0IDA_, 0))
        {
            this->error();
        }

        dy0IDA_ = N_VNew_Serial(NEQ_);
        if (checkFlag((void *)dy0IDA_, 0))
        {
            this->error();
        }

        yIDA_ = N_VNew_Serial(NEQ_);
        if (checkFlag((void *)yIDA_, 0))
        {
            this->error();
        }

        dyIDA_ = N_VNew_Serial(NEQ_);
        if (checkFlag((void *)dyIDA_, 0))
        {
            this->error();
        }

        algebraicIDA_ = N_VNew_Serial(NEQ_);
        if (checkFlag((void *)algebraicIDA_, 0))
        {
            this->error();
        }

        algebraic_.resize(NEQ_);
        y0_.resize(NEQ_);
        dy0_.resize(NEQ_);
    }

    template <typename T>
    void bvpInterface<T>::setBandDimensions(const double upperBand, const double lowerBand)
    {
        upperBand_ = upperBand;
        lowerBand_ = lowerBand;
    }

    template <typename T>
    void bvpInterface<T>::setTollerance(const double absTol, const double relTol)
    {
        absTol_ = absTol;
        relTol_ = relTol;
    }

    template <typename T>
    void bvpInterface<T>::setConstraints(const bool constraints)
    {
        constraints_ = constraints;
    }

    template <typename T>
    void bvpInterface<T>::setAlgebraic(const std::vector<bool> &algebraic)
    {
        for (int i = 0; i < NEQ_; i++)
        {
            algebraic_[i] = (algebraic[i] == true) ? 0.0 : 1.0;
        }
    }

    template <typename T>
    void bvpInterface<T>::setInitialConditions(double t0, std::vector<double> y0)
    {
        std::vector<double> dy0(NEQ_);

        eq_->Equations(t0, y0, dy0_);

        t0_ = t0;
        y0_ = y0;
    }

    template <typename T>
    int equations(double t, N_Vector y, N_Vector dy, N_Vector f, void *user_data)
    {
        T *data;
        data = (T *)user_data;

        double *ydata = N_VGetArrayPointer_Serial(y);
        double *dydata = N_VGetArrayPointer_Serial(dy);
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

        for (unsigned int i = 0; i < N; i++)
        {
            if (data->AlgebraicEquations()[i] == false)
            {
                fdata[i] -= dydata[i];
            }
        }

        return (flag);
    }

    template <typename T>
    int bvpInterface<T>::solve(const double tf, std::vector<double> &yf)
    {
        int flag;

        N_VSetArrayPointer_Serial(&dy0_[0], dy0IDA_);
        N_VSetArrayPointer_Serial(&y0_[0], y0IDA_);
        N_VSetArrayPointer_Serial(&algebraic_[0], algebraicIDA_);

        ida_mem_ = IDACreate();
        if (checkFlag((void *)ida_mem_, 0))
        {
            this->error();
        }

        flag = IDASetMaxNumSteps(ida_mem_, 5000000);
        if (checkFlag(&flag, 1))
        {
            this->error();
        }

        flag = IDASetUserData(ida_mem_, eq_);
        if (checkFlag(&flag, 1))
        {
            this->error();
        }

        flag = IDAInit(ida_mem_, equations<T>, t0_, y0IDA_, dy0IDA_);
        if (checkFlag(&flag, 1))
        {
            this->error();
        }

        flag = IDASStolerances(ida_mem_, relTol_, absTol_);
        if (checkFlag(&flag, 1))
        {
            this->error();
        }

        flag = IDASetId(ida_mem_, algebraicIDA_);
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

            LS_ = SUNDenseLinearSolver(yIDA_, A_);
            if (checkFlag((void *)LS_, 0))
            {
                this->error();
            }

            flag = IDADlsSetLinearSolver(ida_mem_, LS_, A_);
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

            LS_ = SUNBandLinearSolver(yIDA_, A_);
            if (checkFlag((void *)LS_, 0))
            {
                this->error();
            }

            flag = IDADlsSetLinearSolver(ida_mem_, LS_, A_);
            if (checkFlag(&flag, 1))
            {
                this->error();
            }
        }

        if (constraints_ == true)
        {
            N_Vector constraints = N_VNew_Serial(NEQ_);
            N_VConst(1.0, constraints);
            flag = IDASetConstraints(ida_mem_, constraints);
            if (checkFlag(&flag, 1))
            {
                this->error();
            }
            N_VDestroy_Serial(constraints);
        }

        flag = IDASolve(ida_mem_, tf, &t0_, yIDA_, dyIDA_, IDA_NORMAL);
        if (checkFlag(&flag, 1))
        {
            this->error();
        }

        yf.clear();
        yf.resize(NEQ_);
        double *sol = N_VGetArrayPointer_Serial(yIDA_);
        for (int i = 0; i < NEQ_; i++)
        {
            yf[i] = sol[i];
        }

        return flag;
    }

    template <typename T>
    int bvpInterface<T>::checkFlag(void *flagvalue, int opt)
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
    void bvpInterface<T>::error()
    {
        check_ = false;
        Gtk::MessageDialog dialog(*this, "Ops, something wrong happend!", true, Gtk::MESSAGE_ERROR);
        dialog.set_secondary_text(beerQuote_.getRandomQuote(), true);
        dialog.run();
    }

    template <typename T>
    bvpInterface<T>::~bvpInterface(void)
    {
        N_VDestroy_Serial(yIDA_);
        N_VDestroy_Serial(dyIDA_);
        IDAFree(&ida_mem_);
    }
}
#endif