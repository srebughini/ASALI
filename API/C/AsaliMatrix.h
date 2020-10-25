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

#ifndef ASALIMATRIX_H_
#define ASALIMATRIX_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double** elements;
    int      row;
    int      col;
} dv;

typedef struct
{
    int** elements;
    int   row;
    int   col;
} iv;

typedef struct
{
    dv* md;
    iv* mi;
} AsaliMatrix;


void empty_matrix_of_double(AsaliMatrix *m, const int row, const int col);
void empty_matrix_of_int(AsaliMatrix *m, const int row, const int col);

void matrix_from_double(AsaliMatrix *m, const int row, const int col, const double value);
void matrix_from_int(AsaliMatrix *m, const int row, const int col, const int value);

void set_matrix_element_from_int(AsaliMatrix *m, const int ridx, const int cidx, const int value);
void set_matrix_element_from_double(AsaliMatrix *m, const int ridx, const int cidx, const double value);

int get_matrix_element_as_int(AsaliMatrix *m, const int ridx, const int cidx);
double get_matrix_element_as_double(AsaliMatrix *m, const int ridx, const int cidx);

int get_matrix_number_of_rows(AsaliMatrix *m);
int get_matrix_number_of_columns(AsaliMatrix *m);

#endif // ASALIMATRIX_H_

