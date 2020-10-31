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

// C
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int get_number_of_lines_in_file(const char* filename)
{
    FILE *fp;
    fp = fopen(filename, "r");
    int count = 0;
    char c;
    for (c = getc(fp); c != EOF; c = getc(fp))
    {
        if (c == '\n')
        {
            count = count + 1;
        }
    }
    fclose(fp);
    return count;
}

int max(int a, int b)
{
    if ( a > b )
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    int NC = get_number_of_lines_in_file("../database/transport.asali");

    char *names[NC], *names_in_thermo[NC];
    int  *geometry;
    int   nT11, nT22;
    float *LJpotential, *LJdiameter, *dipole, *polar, *collision, *MW;
    float *highA, *highB, *highC, *highD, *highE, *highF, *highG;
    float *lowA, *lowB, *lowC, *lowD, *lowE, *lowF, *lowG;
    float *Tsigma22, *Tsigma11;
    float **sigmaMatrix22, **sigmaMatrix11;
    float dsigma22[8], dsigma11[8];

    //Read transport.asali
    {
        geometry    = (int*) malloc(NC * sizeof(int));
        LJpotential = (float*) malloc(NC * sizeof(float));
        LJdiameter  = (float*) malloc(NC * sizeof(float));
        dipole      = (float*) malloc(NC * sizeof(float));
        polar       = (float*) malloc(NC * sizeof(float));
        collision   = (float*) malloc(NC * sizeof(float));
        MW          = (float*) malloc(NC * sizeof(float));

        FILE *fp;
        fp = fopen("../database/transport.asali", "r");
        char stringValue[1024];
        for (int i=0;i<NC;i++)
        {
            fgets(stringValue, sizeof(stringValue), fp);
            stringValue[strlen(stringValue) - 1] = '\0';

            char *dummyArray[8];
            char *dummyValue = strtok (stringValue, "\t");
            int j = 0;
            while (dummyValue != NULL)
            {
                dummyArray[j++] = dummyValue;
                dummyValue = strtok (NULL, "\t");
            }

            names[i] = (char*) malloc( strlen(dummyArray[0]) * sizeof(char));
            strcpy(names[i],dummyArray[0]);
            geometry[i]    = atoi(dummyArray[1]);
            LJpotential[i] = atof(dummyArray[2]);
            LJdiameter[i]  = atof(dummyArray[3]);
            dipole[i]      = atof(dummyArray[4]);
            polar[i]       = atof(dummyArray[5]);
            collision[i]   = atof(dummyArray[6]);
            MW[i]          = atof(dummyArray[7]);
        }

        fclose(fp);   
    }

    //Write transport.asali
    {
        FILE *fp;
        fp = fopen("transport.H", "w+");
        fprintf(fp,"/*##############################################################################################\n");
        fprintf(fp,"#                                                                                              #\n");
        fprintf(fp,"#     #############       #############       #############       ####                ####     #\n");
        fprintf(fp,"#    #             #     #             #     #             #     #    #              #    #    #\n");
        fprintf(fp,"#    #    #####    #     #    #########      #    #####    #     #    #              #    #    #\n");
        fprintf(fp,"#    #    #   #    #     #    #              #    #   #    #     #    #              #    #    #\n");
        fprintf(fp,"#    #    #####    #     #    #              #    #####    #     #    #              #    #    #\n");
        fprintf(fp,"#    #             #     #    #########      #             #     #    #              #    #    #\n");
        fprintf(fp,"#    #             #     #             #     #             #     #    #              #    #    #\n");
        fprintf(fp,"#    #    #####    #      #########    #     #    #####    #     #    #              #    #    #\n");
        fprintf(fp,"#    #    #   #    #              #    #     #    #   #    #     #    #              #    #    #\n");
        fprintf(fp,"#    #    #   #    #      #########    #     #    #   #    #     #    #########      #    #    #\n");
        fprintf(fp,"#    #    #   #    #     #             #     #    #   #    #     #             #     #    #    #\n");
        fprintf(fp,"#     ####     ####       #############       ####     ####       #############       ####     #\n");
        fprintf(fp,"#                                                                                              #\n");
        fprintf(fp,"#   Author: Stefano Rebughini <ste.rebu@outlook.it>                                            #\n");
        fprintf(fp,"#                                                                                              #\n");
        fprintf(fp,"################################################################################################\n");
        fprintf(fp,"#                                                                                              #\n");
        fprintf(fp,"#   License                                                                                    #\n");
        fprintf(fp,"#                                                                                              #\n");
        fprintf(fp,"#   This file is part of ASALI.                                                                #\n");
        fprintf(fp,"#                                                                                              #\n");
        fprintf(fp,"#   ASALI is free software: you can redistribute it and/or modify                              #\n");
        fprintf(fp,"#   it under the terms of the GNU General Public License as published by                       #\n");
        fprintf(fp,"#   the Free Software Foundation, either version 3 of the License, or                          #\n");
        fprintf(fp,"#   (at your option) any later version.                                                        #\n");
        fprintf(fp,"#                                                                                              #\n");
        fprintf(fp,"#   ASALI is distributed in the hope that it will be useful,                                   #\n");
        fprintf(fp,"#   but WITHOUT ANY WARRANTY; without even the implied warranty of                             #\n");
        fprintf(fp,"#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #\n");
        fprintf(fp,"#   GNU General Public License for more details.                                               #\n");
        fprintf(fp,"#                                                                                              #\n");
        fprintf(fp,"#   You should have received a copy of the GNU General Public License                          #\n");
        fprintf(fp,"#   along with ASALI. If not, see <http://www.gnu.org/licenses/>.                              #\n");
        fprintf(fp,"#                                                                                              #\n");
        fprintf(fp,"##############################################################################################*/\n");
        fprintf(fp,"\n");
        fprintf(fp,"void transport_update(Asali* asali_)\n");
        fprintf(fp,"{\n");
        fprintf(fp,"\tif ( !asali_->transport_updated_ )\n");
        fprintf(fp,"\t{\n");
        fprintf(fp,"\t\tasali_->transport_ = (struct transportParameters*) malloc(%d * sizeof(struct transportParameters));\n",NC);
        fprintf(fp,"\t\tasali_->number_of_species = %d;\n",NC);
        for (unsigned int i=0;i<NC;i++)
        {
            fprintf(fp,"\t\t\n");
            fprintf(fp,"\t\tasali_->transport_[%d].name = (char*) malloc(%d * sizeof(char));\n",i,(int)strlen(names[i]));
            fprintf(fp,"\t\tstrcpy(asali_->transport_[%d].name,\"%s\");\n",i,names[i]);
            fprintf(fp,"\t\tasali_->transport_[%d].geometry = %d;\n",i,geometry[i]);
            fprintf(fp,"\t\tasali_->transport_[%d].LJpotential = %6.3f;\n",i,LJpotential[i]);
            fprintf(fp,"\t\tasali_->transport_[%d].LJdiameter = %6.3f;\n",i,LJdiameter[i]);
            fprintf(fp,"\t\tasali_->transport_[%d].dipole = %6.3f;\n",i,dipole[i]);
            fprintf(fp,"\t\tasali_->transport_[%d].polar = %6.3f;\n",i,polar[i]);
            fprintf(fp,"\t\tasali_->transport_[%d].collision = %6.3f;\n",i,collision[i]);
            fprintf(fp,"\t\tasali_->transport_[%d].MW = %6.3f;\n",i,MW[i]);
        }
        fprintf(fp,"\t}\n");
        fprintf(fp,"}\n");
        fclose(fp);
    }

    //Read thermo.asali
    {
        highA = (float*) malloc(NC * sizeof(float));
        highB = (float*) malloc(NC * sizeof(float));
        highC = (float*) malloc(NC * sizeof(float));
        highD = (float*) malloc(NC * sizeof(float));
        highE = (float*) malloc(NC * sizeof(float));
        highF = (float*) malloc(NC * sizeof(float));
        highG = (float*) malloc(NC * sizeof(float));
        lowA  = (float*) malloc(NC * sizeof(float));
        lowB  = (float*) malloc(NC * sizeof(float));
        lowC  = (float*) malloc(NC * sizeof(float));
        lowD  = (float*) malloc(NC * sizeof(float));
        lowE  = (float*) malloc(NC * sizeof(float));
        lowF  = (float*) malloc(NC * sizeof(float));
        lowG  = (float*) malloc(NC * sizeof(float));
        
        int nl = get_number_of_lines_in_file("../database/thermo.asali");

        FILE *fp;
        {
            fp = fopen("../database/thermo.asali", "r");
            char stringValue[1024];
            int  k = 0;
            for (int i=0;i<nl;i=i+4)
            {
                fgets(stringValue, sizeof(stringValue), fp);
                stringValue[strlen(stringValue) - 1] = '\0';
                names_in_thermo[k] = (char*) malloc(strlen(stringValue) * sizeof(char));
                strncpy(names_in_thermo[k],stringValue,strlen(stringValue));
                names_in_thermo[k][strlen(names_in_thermo[k]) - 1] = '\0';

                fgets(stringValue, sizeof(stringValue), fp);
                stringValue[strlen(stringValue) - 1] = '\0';
                highA[k] = atof(strtok(stringValue, "\t"));
                highB[k] = atof(strtok(NULL, "\t"));
                highC[k] = atof(strtok(NULL, "\t"));
                highD[k] = atof(strtok(NULL, "\t"));
                highE[k] = atof(strtok(NULL, "\t"));

                fgets(stringValue, sizeof(stringValue), fp);
                stringValue[strlen(stringValue) - 1] = '\0';
                highF[k] = atof(strtok(stringValue, "\t"));
                highG[k] = atof(strtok(NULL, "\t"));
                lowA[k]  = atof(strtok(NULL, "\t"));
                lowB[k]  = atof(strtok(NULL, "\t"));
                lowC[k]  = atof(strtok(NULL, "\t"));

                fgets(stringValue, sizeof(stringValue), fp);
                stringValue[strlen(stringValue) - 1] = '\0';
                lowD[k] = atof(strtok(stringValue, "\t"));
                lowE[k] = atof(strtok(NULL, "\t"));
                lowF[k] = atof(strtok(NULL, "\t"));
                lowG[k] = atof(strtok(NULL, "\t"));
                k++;
            }
            fclose(fp);
        }
    }

    //Write thermo.asali
    {
        FILE *fp;
        fp = fopen("thermo.H", "w+");
        fprintf(fp,"/*##############################################################################################\n");
        fprintf(fp,"#                                                                                              #\n");
        fprintf(fp,"#     #############       #############       #############       ####                ####     #\n");
        fprintf(fp,"#    #             #     #             #     #             #     #    #              #    #    #\n");
        fprintf(fp,"#    #    #####    #     #    #########      #    #####    #     #    #              #    #    #\n");
        fprintf(fp,"#    #    #   #    #     #    #              #    #   #    #     #    #              #    #    #\n");
        fprintf(fp,"#    #    #####    #     #    #              #    #####    #     #    #              #    #    #\n");
        fprintf(fp,"#    #             #     #    #########      #             #     #    #              #    #    #\n");
        fprintf(fp,"#    #             #     #             #     #             #     #    #              #    #    #\n");
        fprintf(fp,"#    #    #####    #      #########    #     #    #####    #     #    #              #    #    #\n");
        fprintf(fp,"#    #    #   #    #              #    #     #    #   #    #     #    #              #    #    #\n");
        fprintf(fp,"#    #    #   #    #      #########    #     #    #   #    #     #    #########      #    #    #\n");
        fprintf(fp,"#    #    #   #    #     #             #     #    #   #    #     #             #     #    #    #\n");
        fprintf(fp,"#     ####     ####       #############       ####     ####       #############       ####     #\n");
        fprintf(fp,"#                                                                                              #\n");
        fprintf(fp,"#   Author: Stefano Rebughini <ste.rebu@outlook.it>                                            #\n");
        fprintf(fp,"#                                                                                              #\n");
        fprintf(fp,"################################################################################################\n");
        fprintf(fp,"#                                                                                              #\n");
        fprintf(fp,"#   License                                                                                    #\n");
        fprintf(fp,"#                                                                                              #\n");
        fprintf(fp,"#   This file is part of ASALI.                                                                #\n");
        fprintf(fp,"#                                                                                              #\n");
        fprintf(fp,"#   ASALI is free software: you can redistribute it and/or modify                              #\n");
        fprintf(fp,"#   it under the terms of the GNU General Public License as published by                       #\n");
        fprintf(fp,"#   the Free Software Foundation, either version 3 of the License, or                          #\n");
        fprintf(fp,"#   (at your option) any later version.                                                        #\n");
        fprintf(fp,"#                                                                                              #\n");
        fprintf(fp,"#   ASALI is distributed in the hope that it will be useful,                                   #\n");
        fprintf(fp,"#   but WITHOUT ANY WARRANTY; without even the implied warranty of                             #\n");
        fprintf(fp,"#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #\n");
        fprintf(fp,"#   GNU General Public License for more details.                                               #\n");
        fprintf(fp,"#                                                                                              #\n");
        fprintf(fp,"#   You should have received a copy of the GNU General Public License                          #\n");
        fprintf(fp,"#   along with ASALI. If not, see <http://www.gnu.org/licenses/>.                              #\n");
        fprintf(fp,"#                                                                                              #\n");
        fprintf(fp,"##############################################################################################*/\n");
        fprintf(fp,"\n");
        fprintf(fp,"void thermo_update(Asali* asali_)\n");
        fprintf(fp,"{\n");
        fprintf(fp,"\tif ( !asali_->thermo_updated_ )\n");
        fprintf(fp,"\t{\n");
        fprintf(fp,"\t\tasali_->thermo_ = (struct thermoParameters*) malloc(%d * sizeof(struct thermoParameters));\n",NC);
        for (unsigned int i=0;i<NC;i++)
        {
            fprintf(fp,"\t\t\n");
            for (unsigned int j=0;j<NC;j++)
            {
                if ( strcmp(names_in_thermo[j], names[i]) == 0)
                {
                    fprintf(fp,"\t\tasali_->thermo_[%d].name = (char*) malloc(%d * sizeof(char));\n",i,(int)strlen(names[i]));
                    fprintf(fp,"\t\tstrcpy(asali_->thermo_[%d].name,\"%s\");\n\n",i,names[i]);
                    
                    fprintf(fp,"\t\tasali_->thermo_[%d].high = (float*) malloc(7 * sizeof(float));\n",i);
                    fprintf(fp,"\t\tasali_->thermo_[%d].high[%d] = %.10e;\n",i,0,highA[j]);
                    fprintf(fp,"\t\tasali_->thermo_[%d].high[%d] = %.10e;\n",i,1,highB[j]);
                    fprintf(fp,"\t\tasali_->thermo_[%d].high[%d] = %.10e;\n",i,2,highC[j]);
                    fprintf(fp,"\t\tasali_->thermo_[%d].high[%d] = %.10e;\n",i,3,highD[j]);
                    fprintf(fp,"\t\tasali_->thermo_[%d].high[%d] = %.10e;\n",i,4,highE[j]);
                    fprintf(fp,"\t\tasali_->thermo_[%d].high[%d] = %.10e;\n",i,5,highF[j]);
                    fprintf(fp,"\t\tasali_->thermo_[%d].high[%d] = %.10e;\n\n",i,6,highG[j]);

                    fprintf(fp,"\t\tasali_->thermo_[%d].low = (float*) malloc(7 * sizeof(float));\n",i);
                    fprintf(fp,"\t\tasali_->thermo_[%d].low[%d] = %.10e;\n",i,0,lowA[j]);
                    fprintf(fp,"\t\tasali_->thermo_[%d].low[%d] = %.10e;\n",i,1,lowB[j]);
                    fprintf(fp,"\t\tasali_->thermo_[%d].low[%d] = %.10e;\n",i,2,lowC[j]);
                    fprintf(fp,"\t\tasali_->thermo_[%d].low[%d] = %.10e;\n",i,3,lowD[j]);
                    fprintf(fp,"\t\tasali_->thermo_[%d].low[%d] = %.10e;\n",i,4,lowE[j]);
                    fprintf(fp,"\t\tasali_->thermo_[%d].low[%d] = %.10e;\n",i,5,lowF[j]);
                    fprintf(fp,"\t\tasali_->thermo_[%d].low[%d] = %.10e;\n",i,6,lowG[j]);
                    break;
                }
            }
        }
        fprintf(fp,"\t}\n");
        fprintf(fp,"}\n");
        fclose(fp);
    }

    //Read omega22.asali
    {
        int nl = get_number_of_lines_in_file("../database/omega22.asali");
        nT22 = nl-1;
        Tsigma22      = (float*) malloc(nT22 * sizeof(float));
        sigmaMatrix22 = (float**) malloc(nT22 * sizeof(float*)); 
        
        for (unsigned int i=0;i<nT22;i++)
        {
            sigmaMatrix22[i] = (float*) malloc( 8 * sizeof(float)); 
        }

        FILE *fp;
        fp = fopen("../database/omega22.asali", "r");
        char stringValue[1024];

        {
            fgets(stringValue, sizeof(stringValue), fp);
            stringValue[strlen(stringValue) - 1] = '\0';
            strtok(stringValue, "\t");
            for (int i=0;i<8;i++)
            {
                dsigma22[i] = atof(strtok(NULL, "\t"));
            }
        }

        for (int i=0;i<nT22;i++)
        {
            fgets(stringValue, sizeof(stringValue), fp);
            stringValue[strlen(stringValue) - 1] = '\0';
            Tsigma22[i] = atof(strtok(stringValue, "\t"));
            for (int k=0;k<8;k++)
            {
                sigmaMatrix22[i][k] = atof(strtok(NULL, "\t"));
            }
        }

        fclose(fp);
    }

    //Read astar.asali
    {
        int nl = get_number_of_lines_in_file("../database/astar.asali");
        nT11 = nl-1;
        Tsigma11      = (float*) malloc(nT11 * sizeof(float));
        sigmaMatrix11 = (float**) malloc(nT11 * sizeof(float*)); 

        for (unsigned int i=0;i<nT11;i++)
        {
            sigmaMatrix11[i] = (float*) malloc( 8 * sizeof(float)); 
        }

        FILE *fp;
        fp = fopen("../database/astar.asali", "r");
        char stringValue[1024];

        {
            fgets(stringValue, sizeof(stringValue), fp);
            stringValue[strlen(stringValue) - 1] = '\0';
            strtok(stringValue, "\t");
            for (int i=0;i<8;i++)
            {
                dsigma11[i] = atof(strtok(NULL, "\t"));
            }
        }

        for (unsigned int i=0;i<nT11;i++)
        {
            fgets(stringValue, sizeof(stringValue), fp);
            stringValue[strlen(stringValue) - 1] = '\0';
            Tsigma11[i] = atof(strtok(stringValue, "\t"));
            for (int k=0;k<8;k++)
            {
                sigmaMatrix11[i][k] = atof(strtok(NULL, "\t"));
            }
        }

        fclose(fp);
    }

    //Write omega.asali
    {
        FILE *fp;
        fp = fopen("omega.H", "w+");
        fprintf(fp,"/*##############################################################################################\n");
        fprintf(fp,"#                                                                                              #\n");
        fprintf(fp,"#     #############       #############       #############       ####                ####     #\n");
        fprintf(fp,"#    #             #     #             #     #             #     #    #              #    #    #\n");
        fprintf(fp,"#    #    #####    #     #    #########      #    #####    #     #    #              #    #    #\n");
        fprintf(fp,"#    #    #   #    #     #    #              #    #   #    #     #    #              #    #    #\n");
        fprintf(fp,"#    #    #####    #     #    #              #    #####    #     #    #              #    #    #\n");
        fprintf(fp,"#    #             #     #    #########      #             #     #    #              #    #    #\n");
        fprintf(fp,"#    #             #     #             #     #             #     #    #              #    #    #\n");
        fprintf(fp,"#    #    #####    #      #########    #     #    #####    #     #    #              #    #    #\n");
        fprintf(fp,"#    #    #   #    #              #    #     #    #   #    #     #    #              #    #    #\n");
        fprintf(fp,"#    #    #   #    #      #########    #     #    #   #    #     #    #########      #    #    #\n");
        fprintf(fp,"#    #    #   #    #     #             #     #    #   #    #     #             #     #    #    #\n");
        fprintf(fp,"#     ####     ####       #############       ####     ####       #############       ####     #\n");
        fprintf(fp,"#                                                                                              #\n");
        fprintf(fp,"#   Author: Stefano Rebughini <ste.rebu@outlook.it>                                            #\n");
        fprintf(fp,"#                                                                                              #\n");
        fprintf(fp,"################################################################################################\n");
        fprintf(fp,"#                                                                                              #\n");
        fprintf(fp,"#   License                                                                                    #\n");
        fprintf(fp,"#                                                                                              #\n");
        fprintf(fp,"#   This file is part of ASALI.                                                                #\n");
        fprintf(fp,"#                                                                                              #\n");
        fprintf(fp,"#   ASALI is free software: you can redistribute it and/or modify                              #\n");
        fprintf(fp,"#   it under the terms of the GNU General Public License as published by                       #\n");
        fprintf(fp,"#   the Free Software Foundation, either version 3 of the License, or                          #\n");
        fprintf(fp,"#   (at your option) any later version.                                                        #\n");
        fprintf(fp,"#                                                                                              #\n");
        fprintf(fp,"#   ASALI is distributed in the hope that it will be useful,                                   #\n");
        fprintf(fp,"#   but WITHOUT ANY WARRANTY; without even the implied warranty of                             #\n");
        fprintf(fp,"#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #\n");
        fprintf(fp,"#   GNU General Public License for more details.                                               #\n");
        fprintf(fp,"#                                                                                              #\n");
        fprintf(fp,"#   You should have received a copy of the GNU General Public License                          #\n");
        fprintf(fp,"#   along with ASALI. If not, see <http://www.gnu.org/licenses/>.                              #\n");
        fprintf(fp,"#                                                                                              #\n");
        fprintf(fp,"##############################################################################################*/\n");
        fprintf(fp,"\n");
        fprintf(fp,"void omega_update(Asali* asali_)\n");
        fprintf(fp,"{\n");
        fprintf(fp,"\tif ( !asali_->omega11_updated_ )\n");
        fprintf(fp,"\t{\n");
        fprintf(fp,"\t\tasali_->omega11_.size = %d;\n",nT11);
        fprintf(fp,"\t\tasali_->omega11_.d = (float*) malloc(%d * sizeof(float));\n",8);
        for (unsigned int i=0;i<8;i++)
        {
            fprintf(fp,"\t\tasali_->omega11_.d[%d] = %3.2f;\n",i,dsigma11[i]);
        }
        fprintf(fp,"\n");
        fprintf(fp,"\t\tasali_->omega11_.T = (float*) malloc(%i * sizeof(float));\n",nT11);
        for (unsigned int i=0;i<nT11;i++)
        {
            fprintf(fp,"\t\tasali_->omega11_.T[%d] = %3.2f;\n",i,Tsigma11[i]);
        }

        fprintf(fp,"\n");
        fprintf(fp,"\t\tasali_->omega11_.sigma = (float**) malloc(%i * sizeof(int));\n",nT11);
        for (unsigned int i=0;i<nT11;i++)
        {
            fprintf(fp,"\n");
            fprintf(fp,"\t\tasali_->omega11_.sigma[%d] = (float*) malloc(%d * sizeof(int));\n",i,8);
            for (unsigned int j=0;j<8;j++)
            {
                fprintf(fp,"\t\tasali_->omega11_.sigma[%d][%d] = %5.4f;\n",i,j,sigmaMatrix22[i][j]/sigmaMatrix11[i][j]);
            }
        }

        fprintf(fp,"\t}\n");
        fprintf(fp,"\n");
        fprintf(fp,"\tif ( !asali_->omega22_updated_ )\n");
        fprintf(fp,"\t{\n");
        fprintf(fp,"\t\tasali_->omega22_.size = %d;\n",nT22);
        fprintf(fp,"\t\tasali_->omega22_.d = (float*) malloc(%d * sizeof(float));\n",8);
        for (unsigned int i=0;i<8;i++)
        {
            fprintf(fp,"\t\tasali_->omega22_.d[%d] = %3.2f;\n",i,dsigma22[i]);
        }
        fprintf(fp,"\n");
        fprintf(fp,"\t\tasali_->omega22_.T = (float*) malloc(%i * sizeof(float));\n",nT22);
        for (unsigned int i=0;i<nT22;i++)
        {
            fprintf(fp,"\t\tasali_->omega22_.T[%d] = %3.2f;\n",i,Tsigma22[i]);
        }
        fprintf(fp,"\n");
        fprintf(fp,"\t\tasali_->omega22_.sigma = (float**) malloc(%i * sizeof(float));\n",nT22);
        for (unsigned int i=0;i<nT11;i++)
        {
            fprintf(fp,"\n");
            fprintf(fp,"\t\tasali_->omega22_.sigma[%d] = (float*) malloc(%d * sizeof(int));\n",i,8);
            for (unsigned int j=0;j<8;j++)
            {
                fprintf(fp,"\t\tasali_->omega22_.sigma[%d][%d] = %5.4f;\n",i,j,sigmaMatrix22[i][j]);
            }
        }

        fprintf(fp,"\t}\n");
        fprintf(fp,"}\n");
        fclose(fp);
    }
    return 0;
}
