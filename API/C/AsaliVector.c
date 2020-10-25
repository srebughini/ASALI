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

#include "AsaliVector.h"

void empty_vector_of_double(AsaliVector *v, const int SIZE)
{
    v->vd = (de*) malloc(1 * sizeof(de));
    v->vd->size = SIZE;
    v->vd->elements = (double*) malloc(SIZE * sizeof(double));

    v->vi = NULL;
    v->vc = NULL;
}

void empty_vector_of_int(AsaliVector *v, const int SIZE)
{
    v->vi = (ie*) malloc(1 * sizeof(ie));
    v->vi->size = SIZE;
    v->vi->elements = (int*) malloc(SIZE * sizeof(int));
    
    v->vd = NULL;
    v->vc = NULL;
}

void empty_vector_of_char(AsaliVector *v, const int SIZE)
{
    v->vc = (ce*) malloc(1 * sizeof(ce));
    v->vc->size = SIZE;
    v->vc->elements = (char**) malloc(SIZE * sizeof(char*));
    
    for (int j=0;j<SIZE;j++)
    {
        v->vc->elements[j] = (char*) malloc(1 * sizeof(char));
    }
    
    v->vd = NULL;
    v->vi = NULL;
}

void vector_from_double(AsaliVector *v, const int SIZE, const double value)
{
    v->vd = (de*) malloc(1 * sizeof(de));
    v->vd->size = SIZE;
    v->vd->elements = (double*) malloc(SIZE * sizeof(double));
    
    for (int j=0;j<SIZE;j++)
    {
        v->vd->elements[j] = value;
    }

    v->vi = NULL;
    v->vc = NULL;
}

void vector_from_double_array(AsaliVector *v, const int SIZE, const double* value)
{
    v->vd = (de*) malloc(1 * sizeof(de));
    v->vd->size = SIZE;
    v->vd->elements = (double*) malloc(SIZE * sizeof(double));
    
    for (int j=0;j<SIZE;j++)
    {
        v->vd->elements[j] = value[j];
    }

    v->vi = NULL;
    v->vc = NULL;
}

void vector_from_int(AsaliVector *v, const int SIZE, const int value)
{
    v->vi = (ie*) malloc(1 * sizeof(ie));
    v->vi->size = SIZE;
    v->vi->elements = (int*) malloc(SIZE * sizeof(int));

    for (int j=0;j<SIZE;j++)
    {
        v->vi->elements[j] = value;
    }

    v->vd = NULL;
    v->vc = NULL;
}

void vector_from_int_array(AsaliVector *v, const int SIZE, const int* value)
{
    v->vi = (ie*) malloc(1 * sizeof(ie));
    v->vi->size = SIZE;
    v->vi->elements = (int*) malloc(SIZE * sizeof(int));

    for (int j=0;j<SIZE;j++)
    {
        v->vi->elements[j] = value[j];
    }

    v->vd = NULL;
    v->vc = NULL;
}

void vector_from_char(AsaliVector *v, const int SIZE, const char* value)
{
    v->vc = (ce*) malloc(1 * sizeof(ce));
    v->vc->size = SIZE;
    v->vc->elements = (char**) malloc(SIZE * sizeof(char*));
    for (int j=0;j<SIZE;j++)
    {
        v->vc->elements[j] = (char*) malloc(strlen(value) * sizeof(char));
        strcpy(v->vc->elements[j],value);
    }
    
    v->vd = NULL;
    v->vi = NULL;
}

void set_vector_element_from_int(AsaliVector *v, const int idx, const int value)
{
    if ( v->vi )
    {
        v->vi->elements[idx] = value;
    }
    else if ( v->vd )
    {
        v->vd->elements[idx] = (double)value;
    }
    else if ( v->vc )
    {
        v->vc->elements[idx] = (char*) malloc(1024 * sizeof(char));
        sprintf(v->vc->elements[idx], "%d", value);
    }
}

void set_vector_element_from_double(AsaliVector *v, const int idx, const double value)
{
    if ( v->vi )
    {
        v->vi->elements[idx] = (int) value;
    }
    else if ( v->vd )
    {
        v->vd->elements[idx] = value;
    }
    else if ( v->vc )
    {
        v->vc->elements[idx] = (char*) malloc(1024 * sizeof(char));
        sprintf(v->vc->elements[idx], "%f", value);
    }
}

void set_vector_element_from_char(AsaliVector *v, const int idx, const char* value)
{
    if ( v->vi )
    {
        printf("\nAsaliVector::error --> cannot cast %s into int\n", value);
        exit(-1);
    }
    else if ( v->vd )
    {
        printf("\nAsaliVector::error --> cannot cast %s into double\n", value);
        exit(-1);
    }
    else if ( v->vc )
    {
        v->vc->elements[idx] = (char*) malloc(strlen(value) * sizeof(char));
        strcpy(v->vc->elements[idx],value);
    }
}


int get_vector_element_as_int(AsaliVector *v, const int idx)
{
    if ( v->vi )
    {
        return v->vi->elements[idx];
    }
    else if ( v->vd )
    {
        return (int)v->vd->elements[idx];
    }
    else if ( v->vc)
    {
        printf("\nAsaliVector::error --> cannot convert %s to int\n", v->vc->elements[idx]);
        exit(-1);
    }
}

double get_vector_element_as_double(AsaliVector *v, const int idx)
{
    if (v->vi)
    {
        return (double)v->vi->elements[idx];
    }
    else if (v->vd)
    {
        return v->vd->elements[idx];
    }
    else if (v->vc)
    {
        printf("\nAsaliVector::error --> cannot convert %s to double\n", v->vc->elements[idx]);
        exit(-1);
    }
}

char* get_vector_element_as_char(AsaliVector *v, const int idx)
{
    if ( v->vi )
    {
        char* a;
        a = (char*) malloc(1024 * sizeof(char));
        sprintf(a, "%d", v->vi->elements[idx]);
        return a;
    }
    else if ( v->vd )
    {
        char* a;
        a = (char*) malloc(1024 * sizeof(char));
        sprintf(a, "%f", v->vd->elements[idx]);
        return a;
    }
    else if ( v->vc)
    {
        return v->vc->elements[idx];
    }
}

int get_vector_size(AsaliVector *v)
{
    if (v->vi)
    {
        return v->vi->size;
    }
    else if (v->vd)
    {
        return v->vd->size;
    }
    else if (v->vc)
    {
        return v->vc->size;
    }
}
