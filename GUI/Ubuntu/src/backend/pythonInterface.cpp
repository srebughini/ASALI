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
#   ASALI is free software: you can redistribute it and/or modify                              #
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

#include "backend/pythonInterface.hpp"

namespace ASALI
{
    pythonInterface::pythonInterface()
    {
        small.resize(26);    big.resize(26);
        small[0]  = "a";    big[0]  = "A";
        small[1]  = "b";    big[1]  = "B";
        small[2]  = "c";    big[2]  = "C";
        small[3]  = "d";    big[3]  = "D";
        small[4]  = "e";    big[4]  = "E";
        small[5]  = "f";    big[5]  = "F";
        small[6]  = "g";    big[6]  = "G";
        small[7]  = "h";    big[7]  = "H";
        small[8]  = "i";    big[8]  = "I";
        small[9]  = "j";    big[9]  = "J";
        small[10] = "k";    big[10] = "K";
        small[11] = "l";    big[11] = "L";
        small[12] = "m";    big[12] = "M";
        small[13] = "n";    big[13] = "N";
        small[14] = "o";    big[14] = "O";
        small[15] = "p";    big[15] = "P";
        small[16] = "q";    big[16] = "Q";
        small[17] = "r";    big[17] = "R";
        small[18] = "s";    big[18] = "S";
        small[19] = "t";    big[19] = "T";
        small[20] = "u";    big[20] = "U";
        small[21] = "v";    big[21] = "V";
        small[22] = "w";    big[22] = "W";
        small[23] = "x";    big[23] = "X";
        small[24] = "y";    big[24] = "Y";
        small[25] = "z";    big[25] = "Z";
        
        Nhet_ = 0;
        Nhom_ = 0;
    }

    void pythonInterface::setTemperature(const double T)
    {
        pTemperature = Py_BuildValue("d",T);
    }
    
    void pythonInterface::setMoleFraction(const std::vector<double> x, const std::vector<std::string> name)
    {
        pMassFraction = PyList_New(n_.size());

        for (unsigned int j=0;j<n_.size();j++)
        {
            PyList_SetItem(pMassFraction, j, Py_BuildValue("d",0.0));
        }

        for (unsigned int i=0;i<x.size();i++)
        {
            for (unsigned int j=0;j<n_.size();j++)
            {
                if ( name[i] == n_[j] )
                {
                    PyList_SetItem(pMassFraction, j, Py_BuildValue("d",x[i]));
                    break;
                }
            }
        }
    }
    
    int  pythonInterface::checkNames(std::string name)
    {
        int check = 1;

        this->convertToCaption(name);
        for (unsigned int j=0;j<n_.size();j++)
        {
            if ( name == n_[j] )
            {
                check = 0;
                break;
            }
        }

        return check;
    }

    std::vector<int>  pythonInterface::checkNames(std::vector<std::string> &name)
    {
        std::vector<int> check(name.size());
        
        for (unsigned int i=0;i<name.size();i++)
        {
            this->convertToCaption(name[i]);
            check[i] = 1;
            for (unsigned int j=0;j<n_.size();j++)
            {
                if ( name[i] == n_[j] )
                {
                    check[i] = 0;
                    break;
                }
            }
        }

        return check;
    }


    std::string pythonInterface::initialize(const std::string function, const std::string path)
    {
        #if ASALI_ON_WINDOW == 1
        _putenv_s("PYTHONPATH",path.c_str());
        #else
        setenv("PYTHONPATH",path.c_str(), 1);
        #endif

        Py_Initialize();

        if ( (pModule = PyImport_ImportModule(function.c_str() ) ) )
        {
            if ( (pClass = PyObject_GetAttrString(pModule, "kinetic")) )
            {
                if ( (pInstance = PyObject_CallObject(pClass, NULL) ))
                {
                    if ( (pName = PyObject_CallMethod(pInstance,(char*)"name", NULL)) )
                    {
                        if ( (pHetReaction = PyUnicode_FromString("heterogeneous")) )
                        {
                            if ( (pHomReaction = PyUnicode_FromString("homogeneous")) )
                            {
                                if ( (pNhom = PyObject_CallMethod(pInstance,(char*)"NRhom", NULL)) )
                                {
                                    if ( (pNhet = PyObject_CallMethod(pInstance,(char*)"NRhet", NULL)) )
                                    {
                                        if ( (pAllHomReaction = PyUnicode_FromString("allHomogeneous")) )
                                        {
                                            if ( (pAllHetReaction = PyUnicode_FromString("allHeterogeneous")) )
                                            {
                                                if ( (pHomNet = PyUnicode_FromString("netHom")) )
                                                {
                                                    if ( (pHetNet = PyUnicode_FromString("netHet")) )
                                                    {
                                                        n_.clear();
                                                        for (unsigned int i=0;i<PyList_Size(pName);i++)
                                                        {
                                                            n_.push_back(std::string(PyUnicode_AsUTF8(PyList_GetItem(pName,i))));
                                                        }
                                                        Nhom_ = (unsigned int) PyFloat_AsDouble(pNhom);
                                                        Nhet_ = (unsigned int) PyFloat_AsDouble(pNhet);
                                                        return std::string("done");
                                                    }
                                                    else
                                                    {
                                                        return std::string("netHetFunction");
                                                    }
                                                }
                                                else
                                                {
                                                    return std::string("netHomFunction");
                                                }
                                            }
                                            else
                                            {
                                                return std::string("allHeterogeneousFunction");
                                            }
                                        }
                                        else
                                        {
                                            return std::string("allHomogeneousFunction");
                                        }
                                    }
                                    else
                                    {
                                        return std::string("NhetFunction");
                                    }
                                }
                                else
                                {
                                    return std::string("NhomFunction");
                                }
                            }
                            else
                            {
                                return std::string("homogeneousFunction");
                            }
                        }
                        else
                        {
                            return std::string("heterogeneousFunction");
                        }
                    }
                    else
                    {
                        return std::string("nameFunction");
                    }
                }
                else
                {
                    return std::string("getInstance");
                }
            }
            else
            {
                return std::string("getClass");
            }
        }
        else
        {
            return std::string("importModule");
        }
    }
    
    void pythonInterface::run()
    {
        this->runHeterogeneous();
        this->runHomogeneous();
    }
    
    void pythonInterface::runHomogeneous()
    {
        pHomReactionRate  = PyObject_CallMethodObjArgs(pInstance,pHomReaction,pTemperature,pMassFraction,NULL);

        Rhom_.clear();
        for (unsigned int i=0;i<PyList_Size(pHomReactionRate);i++)
        {
            Rhom_.push_back(PyFloat_AsDouble(PyList_GetItem(pHomReactionRate,i)));
        }
    }
    
    void pythonInterface::runHeterogeneous()
    {
        pHetReactionRate = PyObject_CallMethodObjArgs(pInstance,pHetReaction,pTemperature,pMassFraction,NULL);

        Rhet_.clear();
        for (unsigned int i=0;i<PyList_Size(pHetReactionRate);i++)
        {
            Rhet_.push_back(PyFloat_AsDouble(PyList_GetItem(pHetReactionRate,i)));
        }
    }

    void pythonInterface::runAllHeterogeneous()
    {
        pAllHetReactionRate = PyObject_CallMethodObjArgs(pInstance,pAllHetReaction,pTemperature,pMassFraction,NULL);

        RallHet_.resize(Nhet_);
        unsigned int counter = 0;
        for (unsigned int i=0;i<Nhet_;i++)
        {
            RallHet_[i].resize(n_.size());
            for (unsigned int j=0;j<n_.size();j++)
            {
                RallHet_[i][j] = PyFloat_AsDouble(PyList_GetItem(pAllHetReactionRate,counter++));
            }
        }
    }

    void pythonInterface::runAllHomogeneous()
    {
        pAllHomReactionRate = PyObject_CallMethodObjArgs(pInstance,pAllHomReaction,pTemperature,pMassFraction,NULL);

        RallHom_.resize(Nhom_);
        unsigned int counter = 0;
        for (unsigned int i=0;i<Nhom_;i++)
        {
            RallHom_[i].resize(n_.size());
            for (unsigned int j=0;j<n_.size();j++)
            {
                RallHom_[i][j] = PyFloat_AsDouble(PyList_GetItem(pAllHomReactionRate,counter++));
            }
        }
    }

    void pythonInterface::runNetHomogeneous()
    {
        pHomNetRate  = PyObject_CallMethodObjArgs(pInstance,pHomNet,pTemperature,pMassFraction,NULL);

        RhomNet_.clear();
        for (unsigned int i=0;i<PyList_Size(pHomNetRate);i++)
        {
            RhomNet_.push_back(PyFloat_AsDouble(PyList_GetItem(pHomNetRate,i)));
        }
    }
    
    void pythonInterface::runNetHeterogeneous()
    {
        pHetNetRate = PyObject_CallMethodObjArgs(pInstance,pHetNet,pTemperature,pMassFraction,NULL);

        RhetNet_.clear();
        for (unsigned int i=0;i<PyList_Size(pHetNetRate);i++)
        {
            RhetNet_.push_back(PyFloat_AsDouble(PyList_GetItem(pHetNetRate,i)));
        }
    }

    void pythonInterface::convertToCaption(std::string& n)
    {
        for(unsigned int i=0;i<26;i++)
        {
            std::replace(n.begin(),n.end(),*small[i].c_str(),*big[i].c_str());
        }
    }
    
    void pythonInterface::close()
    {
        Py_Finalize();
    }

    pythonInterface::~pythonInterface()
    {
    }
}
