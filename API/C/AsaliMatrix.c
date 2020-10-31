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

#include "AsaliMatrix.h"

void empty_matrix_of_double(AsaliMatrix *m, const int row, const int col)
{
    m->md = (dv*) malloc(1 * sizeof(dv));
    m->md->row = row;
    m->md->col = col;
    m->md->elements = (double**) malloc(row * sizeof(double*));
    
    for (int i=0;i<row;i++)
    {
        m->md->elements[i] = (double*) malloc(col * sizeof(double));
    }

    m->mi = NULL;
}

void empty_matrix_of_int(AsaliMatrix *m, const int row, const int col)
{
    m->mi = (iv*) malloc(1 * sizeof(iv));
    m->mi->row = row;
    m->mi->col = col;
    m->mi->elements = (int**) malloc(row * sizeof(int*));
    
    for (int i=0;i<row;i++)
    {
        m->mi->elements[i] = (int*) malloc(col * sizeof(int));
    }

    m->md = NULL;
}

void matrix_from_double(AsaliMatrix *m, const int row, const int col, const double value)
{
    m->md = (dv*) malloc(1 * sizeof(dv));
    m->md->row = row;
    m->md->col = col;
    m->md->elements = (double**) malloc(row * sizeof(double*));
    
    for (int i=0;i<row;i++)
    {
        m->md->elements[i] = (double*) malloc(col * sizeof(double));
        for (int j=0;j<col;j++)
        {
            m->md->elements[i][j] = value;
        }
    }

    m->mi = NULL;
}

void matrix_from_int(AsaliMatrix *m, const int row, const int col, const int value)
{
    m->mi = (iv*) malloc(1 * sizeof(iv));
    m->mi->row = row;
    m->mi->col = col;
    m->mi->elements = (int**) malloc(row * sizeof(int*));
    
    for (int i=0;i<row;i++)
    {
        m->mi->elements[i] = (int*) malloc(col * sizeof(int));
        for (int j=0;j<col;j++)
        {
            m->mi->elements[i][j] = value;
        }
    }

    m->md = NULL;
}

void set_matrix_element_from_int(AsaliMatrix *m, const int ridx, const int cidx, const int value)
{
    if ( m->mi )
    {
        m->mi->elements[ridx][cidx] = value;
    }
    else if ( m->md )
    {
        m->md->elements[ridx][cidx] = (double)value;
    }
}

void set_matrix_element_from_double(AsaliMatrix *m, const int ridx, const int cidx, const double value)
{
    if ( m->mi )
    {
        m->mi->elements[ridx][cidx] = (int) value;
    }
    else if ( m->md )
    {
        m->md->elements[ridx][cidx] = value;
    }
}

int get_matrix_element_as_int(AsaliMatrix *m, const int ridx, const int cidx)
{
    if ( m->mi )
    {
        return m->mi->elements[ridx][cidx];
    }
    else if ( m->md )
    {
        return (int)m->md->elements[ridx][cidx];
    }
}

double get_matrix_element_as_double(AsaliMatrix *m, const int ridx, const int cidx)
{
    if (m->mi)
    {
        return (double)m->mi->elements[ridx][cidx];
    }
    else if (m->md)
    {
        return m->md->elements[ridx][cidx];
    }
}

int get_matrix_number_of_rows(AsaliMatrix *m)
{
    if (m->mi)
    {
        return m->mi->row;
    }
    else if (m->md)
    {
        return m->md->row;
    }
}

int get_matrix_number_of_columns(AsaliMatrix *m)
{
    if (m->mi)
    {
        return m->mi->col;
    }
    else if (m->md)
    {
        return m->md->col;
    }
}
