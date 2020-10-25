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

#ifndef ASALIVECTOR_H_
#define ASALIVECTOR_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double* elements;
    int     size;
} de;

typedef struct
{
    int* elements;
    int  size;
} ie;

typedef struct
{
    char** elements;
    int  size;
} ce;

typedef struct
{
    de* vd;
    ie* vi;
    ce* vc;
} AsaliVector;


void empty_vector_of_double(AsaliVector *v, const int SIZE);
void empty_vector_of_int(AsaliVector *v, const int SIZE);
void empty_vector_of_char(AsaliVector *v, const int SIZE);

void vector_from_double(AsaliVector *v, const int SIZE, const double value);
void vector_from_int(AsaliVector *v, const int SIZE, const int value);
void vector_from_char(AsaliVector *v, const int SIZE, const char* value);

void vector_from_double_array(AsaliVector *v, const int SIZE, const double* value);
void vector_from_int_array(AsaliVector *v, const int SIZE, const int* value);

void set_vector_element_from_int(AsaliVector *v, const int idx, const int value);
void set_vector_element_from_double(AsaliVector *v, const int idx, const double value);
void set_vector_element_from_char(AsaliVector *v, const int idx, const char* value);

int get_vector_element_as_int(AsaliVector *v, const int idx);
double get_vector_element_as_double(AsaliVector *v, const int idx);
char* get_vector_element_as_char(AsaliVector *v, const int idx);

int get_vector_size(AsaliVector *v);

#endif // ASALIVECTOR_H_

