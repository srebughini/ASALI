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


#include "het1dOdeInterface.h"

namespace ASALI
{
    het1dOdeInterface::het1dOdeInterface()
    {
        #include "Beer.H"

        yCVODE_       = NULL;
        dyCVODE_      = NULL;
        y0CVODE_      = NULL;
        dy0CVODE_     = NULL;
        cvode_mem_    = NULL;
        
        constraints_  = false;
        check_        = true;

        upperBand_    = 0.;
        lowerBand_    = 0.;
        relTol_       = 1.e-07;
        absTol_       = 1.e-12;
        t0_           = 0.;
    }

    void het1dOdeInterface::setEquations(ASALI::het1dEquations* eq)
    {
        eq_  = eq;
        NEQ_ = eq_->NumberOfEquations();

        y0CVODE_ = N_VNew_Serial(NEQ_);
        if (checkFlag((void *)y0CVODE_, "N_VNew_Serial", 0)) 
        {
            this->error();
        }    

        dy0CVODE_ = N_VNew_Serial(NEQ_);
        if (checkFlag((void *)dy0CVODE_, "N_VNew_Serial", 0)) 
        {
            this->error();
        }    

        yCVODE_ = N_VNew_Serial(NEQ_);
        if (checkFlag((void *)yCVODE_, "N_VNew_Serial", 0)) 
        {
            this->error();
        }    

        dyCVODE_ = N_VNew_Serial(NEQ_);
        if (checkFlag((void *)dyCVODE_, "N_VNew_Serial", 0)) 
        {
            this->error();
        }    
    }
    
    void het1dOdeInterface::setBandDimensions(const double upperBand, const double lowerBand)
    {
        upperBand_ = upperBand;
        lowerBand_ = lowerBand;
    }
    
    void het1dOdeInterface::setTollerance(const double absTol, const double relTol)
    {
        absTol_ = absTol;
        relTol_ = relTol;
    }
    
    void het1dOdeInterface::setConstraints(const bool constraints)
    {
        constraints_ = constraints;
    }

    void het1dOdeInterface::setInitialConditions(double t0, std::vector<double> y0)
    {
        std::vector<double> dy0(NEQ_);

        eq_->Equations(t0,y0,dy0);

        t0_ = t0;

        for (int i=0;i<NEQ_;i++)
        {
            NV_Ith_S(dy0CVODE_, i) = dy0[i];
            NV_Ith_S( y0CVODE_, i) =  y0[i];
        }
    }

    static int equationsCVODE(double t, N_Vector y, N_Vector f, void *user_data)
    {
        ASALI::het1dEquations *data;
        data = (ASALI::het1dEquations*)user_data;

        unsigned int N = data->NumberOfEquations();

        double *ydata  = N_VGetArrayPointer_Serial(y);
        double *fdata  = N_VGetArrayPointer_Serial(f);

        std::vector<double> y_(N);
        std::vector<double> dy_(N);

        for (unsigned int i=0;i<N;i++)
        {
            y_[i] = ydata[i];
        }

        int flag = data->Equations(t,y_,dy_);

        for (unsigned int i=0;i<N;i++)
        {
            fdata[i] = dy_[i];
        }

        return(flag);
    }

    int het1dOdeInterface::solve(const double tf, std::vector<double>& yf)
    {
        int flag;

        /* Call IDACreate to create the solver memory and specify the 
        *  Backward Differentiation Formula and the use of a Newton iteration */
        cvode_mem_ = CVodeCreate(CV_BDF, CV_NEWTON);
        if (checkFlag((void *)cvode_mem_, "CVodeCreate", 0))
        {
            this->error();
        }

        flag = CVodeSetMaxNumSteps(cvode_mem_, 5000000);
        if (checkFlag(&flag, "CVodeSetMaxNumSteps", 1))
        {
            this->error();
        }
        
        flag = CVodeSetUserData(cvode_mem_, eq_);
        if(checkFlag(&flag, "CVodeSetUserData", 1))
        {
            this->error();
        }
        
        /* Call CVodeInit to initialize the integrator memory and specify the
        * user's right hand side function in y'=f(t,y), the inital time t0, and
        * the initial dependent variable vector y0Sundials_. */
        flag = CVodeInit(cvode_mem_, equationsCVODE, t0_, y0CVODE_);
        if (checkFlag(&flag, "CVodeInit", 1))
        {
            this->error();
        }
        
        /* Call CVodeSStolerances to specify the scalar relative tolerance
        * and scalar absolute tolerances */
        flag = CVodeSStolerances(cvode_mem_, relTol_, absTol_);
        if (checkFlag(&flag, "CVodeSVtolerances", 1))
        {
            this->error();
        }
        
        /* Call Solver */
        if (upperBand_ == 0 && lowerBand_ == 0)
        {
            flag = CVDense(cvode_mem_, NEQ_);
            if (checkFlag(&flag, "CVDense", 1))
            {
                this->error();
            }
        }
        else
        {
            flag = CVBand(cvode_mem_, NEQ_, upperBand_, lowerBand_);
            if (checkFlag(&flag, "CVBand", 1))
            {
                this->error();
            }
        }

        /* Solving */
        flag = CVode(cvode_mem_,tf, yCVODE_, &t0_, CV_NORMAL);
        if(checkFlag(&flag, "CVode", 1))
        {
            this->error();
        }

        yf.clear();
        yf.resize(NEQ_);
        double *sol = N_VGetArrayPointer_Serial(yCVODE_);
        if ( constraints_ == true )
        {
            for (int i=0;i<NEQ_;i++)
            {
                yf[i] = std::max(0.,sol[i]);
            }
        }
        else
        {
            for (int i=0;i<NEQ_;i++)
            {
                yf[i] = sol[i];
            }
        }
        
        return flag;
    }

    int het1dOdeInterface::checkFlag(void *flagvalue, const char *funcname, int opt)
    {
        /* 
         * Check function return value...
         *   opt == 0 means SUNDIALS function allocates memory so check if
         *            returned NULL pointer
         *   opt == 1 means SUNDIALS function returns a flag so check if
         *            flag >= 0
         *   opt == 2 means function allocates memory so check if returned
         *            NULL pointer 
         */

        int *errflag;

        /* Check if SUNDIALS function returned NULL pointer - no memory allocated */
        if (opt == 0 && flagvalue == NULL)
        {
            return(1);
        }
        else if (opt == 1)
        {
            /* Check if flag < 0 */
            errflag = (int *) flagvalue;
            if (*errflag < 0)
            {
                return(1); 
            }
        }
        else if (opt == 2 && flagvalue == NULL)
        {
            /* Check if function returned NULL pointer - no memory allocated */
            return(1);
        }

        return(0);
    }

    void het1dOdeInterface::error()
    {
        check_ = false;
        Gtk::MessageDialog dialog(*this,"Ops, something wrong happend!",true,Gtk::MESSAGE_ERROR);
        dialog.set_secondary_text(this->getBeer(),true);
        dialog.run();
    }

    std::string het1dOdeInterface::getBeer()
    {
        srand(time(NULL));
        int i = rand()%beer_.size();
        return beer_[i];
    }

    het1dOdeInterface::~het1dOdeInterface(void)
    {
        N_VDestroy_Serial(y0CVODE_);
        N_VDestroy_Serial(dy0CVODE_);
        N_VDestroy_Serial(yCVODE_);
        N_VDestroy_Serial(dyCVODE_);
        CVodeFree(&cvode_mem_);
    }
}
