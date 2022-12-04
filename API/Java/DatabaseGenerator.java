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

import java.io.*; 
import java.util.*;
import java.lang.*; 

class ReadTransport
{
    int NC_ = 0;

    String path_;

    ArrayList<String> names_    = new ArrayList<String>();
    
    Vector<Integer> geometry_   = new Vector<Integer>();
    
    Vector<Double> LJpotential_ = new Vector<Double>();
    Vector<Double> LJdiameter_  = new Vector<Double>();
    Vector<Double> dipole_      = new Vector<Double>();
    Vector<Double> polar_       = new Vector<Double>();
    Vector<Double> collision_   = new Vector<Double>();
    Vector<Double> MW_          = new Vector<Double>();
    
    public int get_number_of_species()
    {
        return NC_;
    }
    
    public ArrayList<String> get_species_names()
    {
        return names_;
    }
    
    public Vector<Integer> get_geometry()
    {
        return geometry_;
    }

    public Vector<Double> get_LJpotential()
    {
        return LJpotential_;
    }

    public Vector<Double> get_LJdiameter()
    {
        return LJdiameter_;
    }

    public Vector<Double> get_dipole()
    {
        return dipole_;
    }

    public Vector<Double> get_polar()
    {
        return polar_;
    }

    public Vector<Double> get_collision()
    {
        return collision_;
    }

    public Vector<Double> get_MW()
    {
        return MW_;
    }

    public ReadTransport(String path) throws Exception 
    {
        File file = new File(path); 
  
        BufferedReader loadFile = new BufferedReader(new FileReader(file)); 

        String line; 
        while ((line = loadFile.readLine()) != null) 
        {
            NC_++;
            String[] lineArray = line.split("\t", -1);
            
            names_.add(lineArray[0]);
            geometry_.add(Integer.valueOf(lineArray[1]));
            LJpotential_.add(Double.parseDouble(lineArray[2]));
            LJdiameter_.add(Double.parseDouble(lineArray[3]));
            dipole_.add(Double.parseDouble(lineArray[4]));
            polar_.add(Double.parseDouble(lineArray[5]));
            collision_.add(Double.parseDouble(lineArray[6]));
            MW_.add(Double.parseDouble(lineArray[7]));
        }
    }
}

class ReadThermo
{
    int NC_ = 0;

    String path_;

    ArrayList<String> names_ = new ArrayList<String>();
    
    Vector<Double> highA_ = new Vector<Double>();
    Vector<Double> highB_ = new Vector<Double>();
    Vector<Double> highC_ = new Vector<Double>();
    Vector<Double> highD_ = new Vector<Double>();
    Vector<Double> highE_ = new Vector<Double>();
    Vector<Double> highF_ = new Vector<Double>();
    Vector<Double> highG_ = new Vector<Double>();
    Vector<Double> lowA_  = new Vector<Double>();
    Vector<Double> lowB_  = new Vector<Double>();
    Vector<Double> lowC_  = new Vector<Double>();
    Vector<Double> lowD_  = new Vector<Double>();
    Vector<Double> lowE_  = new Vector<Double>();
    Vector<Double> lowF_  = new Vector<Double>();
    Vector<Double> lowG_  = new Vector<Double>();
    
    public int get_number_of_species()
    {
        return NC_;
    }
    
    public ArrayList<String> get_species_names()
    {
        return names_;
    }

    public Vector<Double> get_highA()
    {
        return highA_;
    }

    public Vector<Double> get_highB()
    {
        return highB_;
    }

    public Vector<Double> get_highC()
    {
        return highC_;
    }

    public Vector<Double> get_highD()
    {
        return highD_;
    }

    public Vector<Double> get_highE()
    {
        return highE_;
    }

    public Vector<Double> get_highF()
    {
        return highF_;
    }

    public Vector<Double> get_highG()
    {
        return highG_;
    }

    public Vector<Double> get_lowA()
    {
        return lowA_;
    }

    public Vector<Double> get_lowB()
    {
        return lowB_;
    }

    public Vector<Double> get_lowC()
    {
        return lowC_;
    }
    
    public Vector<Double> get_lowD()
    {
        return lowD_;
    }
    
    public Vector<Double> get_lowE()
    {
        return lowE_;
    }
    
     public Vector<Double> get_lowF()
    {
        return lowF_;
    }

    public Vector<Double> get_lowG()
    {
        return lowG_;
    }

    public ReadThermo(String path) throws Exception 
    {
        File file = new File(path); 
  
        BufferedReader loadFile = new BufferedReader(new FileReader(file)); 

        String line;
        int    linecounter = 0;
        while ((line = loadFile.readLine()) != null) 
        {
            String[] lineArray = line.split("\t", -1);
            if ( linecounter == 0 )
            {
                NC_++;
                names_.add(lineArray[0]);
                linecounter++;
            }
            else if ( linecounter == 1 )
            {
                highA_.add(Double.parseDouble(lineArray[0]));
                highB_.add(Double.parseDouble(lineArray[1]));
                highC_.add(Double.parseDouble(lineArray[2]));
                highD_.add(Double.parseDouble(lineArray[3]));
                highE_.add(Double.parseDouble(lineArray[4]));
                linecounter++;
            }
            else if ( linecounter == 2 )
            {
                highF_.add(Double.parseDouble(lineArray[0]));
                highG_.add(Double.parseDouble(lineArray[1]));
                lowA_.add(Double.parseDouble(lineArray[2]));
                lowB_.add(Double.parseDouble(lineArray[3]));
                lowC_.add(Double.parseDouble(lineArray[4]));
                linecounter++;
            }
            else if ( linecounter == 3 )
            {
                lowD_.add(Double.parseDouble(lineArray[0]));
                lowE_.add(Double.parseDouble(lineArray[1]));
                lowF_.add(Double.parseDouble(lineArray[2]));
                lowG_.add(Double.parseDouble(lineArray[3]));
                linecounter = 0;
            }
        }
    }
}

class ReadOmega
{
    String path_;

    Vector<Double> dsigma_ = new Vector<Double>();
    Vector<Double> Tsigma_ = new Vector<Double>();
    
    Vector<Vector<Double>> sigmaMatrix_ = new Vector<Vector<Double>>();
    
    public Vector<Double> get_Tsigma()
    {
        return Tsigma_;
    }
    
    public Vector<Double> get_dsigma()
    {
        return dsigma_;
    }

    public Vector<Vector<Double>> get_sigmaMatrix()
    {
        return sigmaMatrix_;
    }

    public ReadOmega(String path) throws Exception 
    {
        File file = new File(path); 
  
        BufferedReader loadFile = new BufferedReader(new FileReader(file)); 

        String line;

        int    linecounter = 0;
        while ((line = loadFile.readLine()) != null) 
        {
            String[] lineArray = line.split("\t", -1);
            if ( linecounter == 0 )
            {
                linecounter++;
                for (int i = 1; i<lineArray.length; i++)
                {
                    dsigma_.add(Double.parseDouble(lineArray[i]));
                }
            }
            else
            {
                Tsigma_.add(Double.parseDouble(lineArray[0]));
                Vector<Double> sigma = new Vector<Double>();
                sigma.setSize(8);
                
                for (int i = 1; i<lineArray.length; i++)
                {
                    sigma.set(i-1,Double.parseDouble(lineArray[i]));
                }
                sigmaMatrix_.add(sigma);
            }
        }
    }
}

class DatabaseGenerator 
{
    static String logo = "/*##############################################################################################\n" + 
                         "#                                                                                              #\n" + 
                         "#     #############       #############       #############       ####                ####     #\n" +
                         "#    #             #     #             #     #             #     #    #              #    #    #\n" +
                         "#    #    #####    #     #    #########      #    #####    #     #    #              #    #    #\n" +
                         "#    #    #   #    #     #    #              #    #   #    #     #    #              #    #    #\n" +
                         "#    #    #####    #     #    #              #    #####    #     #    #              #    #    #\n" +
                         "#    #             #     #    #########      #             #     #    #              #    #    #\n" +
                         "#    #             #     #             #     #             #     #    #              #    #    #\n" +
                         "#    #    #####    #      #########    #     #    #####    #     #    #              #    #    #\n" +
                         "#    #    #   #    #              #    #     #    #   #    #     #    #              #    #    #\n" +
                         "#    #    #   #    #      #########    #     #    #   #    #     #    #########      #    #    #\n" +
                         "#    #    #   #    #     #             #     #    #   #    #     #             #     #    #    #\n" +
                         "#     ####     ####       #############       ####     ####       #############       ####     #\n" +
                         "#                                                                                              #\n" +
                         "#   Author: Stefano Rebughini <ste.rebu@outlook.it>                                            #\n" +
                         "#                                                                                              #\n" +
                         "################################################################################################\n" +
                         "#                                                                                              #\n" +
                         "#   License                                                                                    #\n" +
                         "#                                                                                              #\n" +
                         "#   This file is part of ASALI.                                                                #\n" +
                         "#                                                                                              #\n" +
                         "#   ASALI is free software: you can redistribute it and/or modify                              #\n" +
                         "#   it under the terms of the GNU General Public License as published by                       #\n" +
                         "#   the Free Software Foundation, either version 3 of the License, or                          #\n" +
                         "#   (at your option) any later version.                                                        #\n" +
                         "#                                                                                              #\n" +
                         "#   ASALI is distributed in the hope that it will be useful,                                   #\n" +
                         "#   but WITHOUT ANY WARRANTY; without even the implied warranty of                             #\n" +
                         "#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #\n" +
                         "#   GNU General Public License for more details.                                               #\n" +
                         "#                                                                                              #\n" +
                         "#   You should have received a copy of the GNU General Public License                          #\n" +
                         "#   along with ASALI. If not, see <http://www.gnu.org/licenses/>.                              #\n" +
                         "#                                                                                              #\n" +
                         "##############################################################################################*/\n";

    static void writeThermo(ReadThermo thermo_, ReadTransport transport_, String filename_) throws Exception 
    {
        PrintWriter writer = new PrintWriter(filename_, "UTF-8");
        writer.println(logo);
        writer.println("public class ThermoDatabase\n{\n");

        String nameStr  = "String [] names_ = {";
        String highAStr = "double [] highA_ = {";
        String highBStr = "double [] highB_ = {";
        String highCStr = "double [] highC_ = {";
        String highDStr = "double [] highD_ = {";
        String highEStr = "double [] highE_ = {";
        String highFStr = "double [] highF_ = {";
        String highGStr = "double [] highG_ = {";
        String lowAStr = "double [] lowA_ = {";
        String lowBStr = "double [] lowB_ = {";
        String lowCStr = "double [] lowC_ = {";
        String lowDStr = "double [] lowD_ = {";
        String lowEStr = "double [] lowE_ = {";
        String lowFStr = "double [] lowF_ = {";
        String lowGStr = "double [] lowG_ = {";
        
        for(int i=0; i<transport_.get_number_of_species()-1; i++) 
        {
            for(int j=0; j<thermo_.get_number_of_species(); j++) 
            {
                if ( Objects.equals(thermo_.get_species_names().get(j), transport_.get_species_names().get(i)) )
                {
                    nameStr  = nameStr  + "\"" + thermo_.get_species_names().get(j)  + "\",\n                        ";
                    highAStr = highAStr + String.valueOf(thermo_.get_highA().get(j)) + ",\n                        ";
                    highBStr = highBStr + String.valueOf(thermo_.get_highB().get(j)) + ",\n                        ";
                    highCStr = highCStr + String.valueOf(thermo_.get_highC().get(j)) + ",\n                        ";
                    highDStr = highDStr + String.valueOf(thermo_.get_highD().get(j)) + ",\n                        ";
                    highEStr = highEStr + String.valueOf(thermo_.get_highE().get(j)) + ",\n                        ";
                    highFStr = highFStr + String.valueOf(thermo_.get_highF().get(j)) + ",\n                        ";
                    highGStr = highGStr + String.valueOf(thermo_.get_highG().get(j)) + ",\n                        ";
                    lowAStr = lowAStr + String.valueOf(thermo_.get_lowA().get(j)) + ",\n                        ";
                    lowBStr = lowBStr + String.valueOf(thermo_.get_lowB().get(j)) + ",\n                        ";
                    lowCStr = lowCStr + String.valueOf(thermo_.get_lowC().get(j)) + ",\n                        ";
                    lowDStr = lowDStr + String.valueOf(thermo_.get_lowD().get(j)) + ",\n                        ";
                    lowEStr = lowEStr + String.valueOf(thermo_.get_lowE().get(j)) + ",\n                        ";
                    lowFStr = lowFStr + String.valueOf(thermo_.get_lowF().get(j)) + ",\n                        ";
                    lowGStr = lowGStr + String.valueOf(thermo_.get_lowG().get(j)) + ",\n                        ";
                }
            }
        }

        for(int j=0; j<thermo_.get_number_of_species(); j++) 
        {
            if ( Objects.equals(thermo_.get_species_names().get(j), transport_.get_species_names().get(transport_.get_number_of_species()-1)) )
            {
                    nameStr  = nameStr  + "\"" + thermo_.get_species_names().get(j)  + "\"};";
                    highAStr = highAStr + String.valueOf(thermo_.get_highA().get(j)) + "};";
                    highBStr = highBStr + String.valueOf(thermo_.get_highB().get(j)) + "};";
                    highCStr = highCStr + String.valueOf(thermo_.get_highC().get(j)) + "};";
                    highDStr = highDStr + String.valueOf(thermo_.get_highD().get(j)) + "};";
                    highEStr = highEStr + String.valueOf(thermo_.get_highE().get(j)) + "};";
                    highFStr = highFStr + String.valueOf(thermo_.get_highF().get(j)) + "};";
                    highGStr = highGStr + String.valueOf(thermo_.get_highG().get(j)) + "};";
                    lowAStr = lowAStr + String.valueOf(thermo_.get_lowA().get(j)) + "};";
                    lowBStr = lowBStr + String.valueOf(thermo_.get_lowB().get(j)) + "};";
                    lowCStr = lowCStr + String.valueOf(thermo_.get_lowC().get(j)) + "};";
                    lowDStr = lowDStr + String.valueOf(thermo_.get_lowD().get(j)) + "};";
                    lowEStr = lowEStr + String.valueOf(thermo_.get_lowE().get(j)) + "};";
                    lowFStr = lowFStr + String.valueOf(thermo_.get_lowF().get(j)) + "};";
                    lowGStr = lowGStr + String.valueOf(thermo_.get_lowG().get(j)) + "};";
            }
        }

        writer.println("\t" + nameStr + "\n");
        writer.println("\t" + highAStr + "\n");
        writer.println("\t" + highBStr + "\n");
        writer.println("\t" + highCStr + "\n");
        writer.println("\t" + highDStr + "\n");
        writer.println("\t" + highEStr + "\n");
        writer.println("\t" + highFStr + "\n");
        writer.println("\t" + highGStr + "\n");
        writer.println("\t" + lowAStr + "\n");
        writer.println("\t" + lowBStr + "\n");
        writer.println("\t" + lowCStr + "\n");
        writer.println("\t" + lowDStr + "\n");
        writer.println("\t" + lowEStr + "\n");
        writer.println("\t" + lowFStr + "\n");
        writer.println("\t" + lowGStr + "\n");

        writer.println("\tString [] names()");
        writer.println("\t{");
        writer.println("\t\treturn names_;");
        writer.println("\t}\n");

        writer.println("\tdouble [] highA()");
        writer.println("\t{");
        writer.println("\t\treturn highA_;");
        writer.println("\t}\n");

        writer.println("\tdouble [] highB()");
        writer.println("\t{");
        writer.println("\t\treturn highB_;");
        writer.println("\t}\n");

        writer.println("\tdouble [] highC()");
        writer.println("\t{");
        writer.println("\t\treturn highC_;");
        writer.println("\t}\n");

        writer.println("\tdouble [] highD()");
        writer.println("\t{");
        writer.println("\t\treturn highD_;");
        writer.println("\t}\n");

        writer.println("\tdouble [] highE()");
        writer.println("\t{");
        writer.println("\t\treturn highE_;");
        writer.println("\t}\n");

        writer.println("\tdouble [] highF()");
        writer.println("\t{");
        writer.println("\t\treturn highF_;");
        writer.println("\t}\n");

        writer.println("\tdouble [] highG()");
        writer.println("\t{");
        writer.println("\t\treturn highG_;");
        writer.println("\t}\n");

        writer.println("\tdouble [] lowA()");
        writer.println("\t{");
        writer.println("\t\treturn lowA_;");
        writer.println("\t}\n");

        writer.println("\tdouble [] lowB()");
        writer.println("\t{");
        writer.println("\t\treturn lowB_;");
        writer.println("\t}\n");

        writer.println("\tdouble [] lowC()");
        writer.println("\t{");
        writer.println("\t\treturn lowC_;");
        writer.println("\t}\n");

        writer.println("\tdouble [] lowD()");
        writer.println("\t{");
        writer.println("\t\treturn lowD_;");
        writer.println("\t}\n");

        writer.println("\tdouble [] lowE()");
        writer.println("\t{");
        writer.println("\t\treturn lowE_;");
        writer.println("\t}\n");

        writer.println("\tdouble [] lowF()");
        writer.println("\t{");
        writer.println("\t\treturn lowF_;");
        writer.println("\t}\n");

        writer.println("\tdouble [] lowG()");
        writer.println("\t{");
        writer.println("\t\treturn lowG_;");
        writer.println("\t}\n");

        writer.println("\n}\n");
        writer.close();
    }

    static void writeTransport(ReadTransport transport_, String filename_) throws Exception 
    {
        PrintWriter writer = new PrintWriter(filename_, "UTF-8");
        writer.println(logo);
        writer.println("public class TransportDatabase\n{\n");

        String nameStr        = "String [] names_ = {";
        String geometryStr    = "int    [] geometry_ = {";
        String LJpotentialStr = "double [] LJpotential_ = {";
        String LJdiameterStr  = "double [] LJdiameter_ = {";
        String dipoleStr      = "double [] dipole_ = {";
        String polarStr       = "double [] polar_ = {";
        String collisionStr   = "double [] collision_ = {";
        String MWStr          = "double [] MW_ = {";
        
        for(int i=0; i<transport_.get_number_of_species()-1; i++) 
        {
            nameStr        = nameStr  + "\"" + transport_.get_species_names().get(i)  + "\",\n                        ";
            geometryStr    = geometryStr + String.valueOf(transport_.get_geometry().get(i)) + ",\n                        ";
            LJpotentialStr = LJpotentialStr + String.valueOf(transport_.get_LJpotential().get(i)) + ",\n                        ";
            LJdiameterStr  = LJdiameterStr + String.valueOf(transport_.get_LJdiameter().get(i)) + ",\n                        ";
            dipoleStr      = dipoleStr + String.valueOf(transport_.get_dipole().get(i)) + ",\n                        ";
            polarStr       = polarStr + String.valueOf(transport_.get_polar().get(i)) + ",\n                        ";
            collisionStr   = collisionStr + String.valueOf(transport_.get_collision().get(i)) + ",\n                        ";
            MWStr          = MWStr + String.valueOf(transport_.get_MW().get(i)) + ",\n                        ";
        }

        {
            nameStr        = nameStr  + "\"" + transport_.get_species_names().get(transport_.get_number_of_species()-1)  + "\"};";
            geometryStr    = geometryStr + String.valueOf(transport_.get_geometry().get(transport_.get_number_of_species()-1)) + "};";
            LJpotentialStr = LJpotentialStr + String.valueOf(transport_.get_LJpotential().get(transport_.get_number_of_species()-1)) + "};";
            LJdiameterStr  = LJdiameterStr + String.valueOf(transport_.get_LJdiameter().get(transport_.get_number_of_species()-1)) + "};";
            dipoleStr      = dipoleStr + String.valueOf(transport_.get_dipole().get(transport_.get_number_of_species()-1)) + "};";
            polarStr       = polarStr + String.valueOf(transport_.get_polar().get(transport_.get_number_of_species()-1)) + "};";
            collisionStr   = collisionStr + String.valueOf(transport_.get_collision().get(transport_.get_number_of_species()-1)) + "};";
            MWStr          = MWStr + String.valueOf(transport_.get_MW().get(transport_.get_number_of_species()-1)) + "};";
        }

        writer.println("\t" + nameStr + "\n");
        writer.println("\t" + geometryStr + "\n");
        writer.println("\t" + LJpotentialStr + "\n");
        writer.println("\t" + LJdiameterStr + "\n");
        writer.println("\t" + dipoleStr + "\n");
        writer.println("\t" + polarStr + "\n");
        writer.println("\t" + collisionStr + "\n");
        writer.println("\t" + MWStr + "\n");

        writer.println("\tString [] names()");
        writer.println("\t{");
        writer.println("\t\treturn names_;");
        writer.println("\t}\n");

        writer.println("\tint [] geometry()");
        writer.println("\t{");
        writer.println("\t\treturn geometry_;");
        writer.println("\t}\n");

        writer.println("\tdouble [] LJpotential()");
        writer.println("\t{");
        writer.println("\t\treturn LJpotential_;");
        writer.println("\t}\n");

        writer.println("\tdouble [] LJdiameter()");
        writer.println("\t{");
        writer.println("\t\treturn LJdiameter_;");
        writer.println("\t}\n");

        writer.println("\tdouble [] dipole()");
        writer.println("\t{");
        writer.println("\t\treturn dipole_;");
        writer.println("\t}\n");

        writer.println("\tdouble [] polar()");
        writer.println("\t{");
        writer.println("\t\treturn polar_;");
        writer.println("\t}\n");

        writer.println("\tdouble [] collision()");
        writer.println("\t{");
        writer.println("\t\treturn collision_;");
        writer.println("\t}\n");

        writer.println("\tdouble [] MW()");
        writer.println("\t{");
        writer.println("\t\treturn MW_;");
        writer.println("\t}\n");

        writer.println("\n}\n");
        writer.close();
    }

    static void writeOmega(ReadOmega omega22_, ReadOmega astar_, String filename_) throws Exception
    {
        PrintWriter writer = new PrintWriter(filename_, "UTF-8");
        writer.println(logo);
        writer.println("public class OmegaDatabase\n{\n");
        
        String d11Str  = "double []   dsigma11_      = {";
        String T11Str  = "double []   Tsigma11_      = {";
        String s11Str  = "double [][] sigmaMatrix11_ = {{";
        String d22Str  = "double []   dsigma22_      = {";
        String T22Str  = "double []   Tsigma22_      = {";
        String s22Str  = "double [][] sigmaMatrix22_ = {{";
        
        for (int i=0;i<omega22_.get_dsigma().size()-1;i++)
        {
            d11Str = d11Str + String.valueOf(astar_.get_dsigma().get(i)) + ",";
            d22Str = d22Str + String.valueOf(omega22_.get_dsigma().get(i)) + ",";
        }

        {
            d11Str = d11Str + String.valueOf(astar_.get_dsigma().get(astar_.get_dsigma().size()-1)) + "};";
            d22Str = d22Str + String.valueOf(omega22_.get_dsigma().get(omega22_.get_dsigma().size()-1)) + "};";
        }

        for (int i=0;i<omega22_.get_Tsigma().size()-1;i++)
        {
            T11Str = T11Str + String.valueOf(astar_.get_Tsigma().get(i)) + ",";
            T22Str = T22Str + String.valueOf(omega22_.get_Tsigma().get(i)) + ",";
        }

        {
            T11Str = T11Str + String.valueOf(astar_.get_Tsigma().get(astar_.get_Tsigma().size()-1)) + "};";
            T22Str = T22Str + String.valueOf(omega22_.get_Tsigma().get(omega22_.get_Tsigma().size()-1)) + "};";
        }
        
        for (int i=0;i<omega22_.get_sigmaMatrix().size()-1;i++)
        {
            for (int j=0;j<omega22_.get_sigmaMatrix().get(i).size()-1;j++)
            {
                s22Str = s22Str + String.valueOf(omega22_.get_sigmaMatrix().get(i).get(j)) + ",";
                s11Str = s11Str + String.valueOf(omega22_.get_sigmaMatrix().get(i).get(j)/astar_.get_sigmaMatrix().get(i).get(j)) + ",";
            }
            s22Str = s22Str + String.valueOf(omega22_.get_sigmaMatrix().get(i).lastElement()) + "},\n\t                              {";
            s11Str = s11Str + String.valueOf(omega22_.get_sigmaMatrix().get(i).lastElement()/astar_.get_sigmaMatrix().get(i).lastElement()) + "},\n\t                              {";
        }
        
        {
            for (int j=0;j<omega22_.get_sigmaMatrix().get(omega22_.get_sigmaMatrix().size()-1).size()-1;j++)
            {
                s22Str = s22Str + String.valueOf(omega22_.get_sigmaMatrix().lastElement().get(j)) + ",";
                s11Str = s11Str + String.valueOf(omega22_.get_sigmaMatrix().lastElement().get(j)/astar_.get_sigmaMatrix().lastElement().get(j)) + ",";
            }
            s22Str = s22Str + String.valueOf(omega22_.get_sigmaMatrix().lastElement().lastElement()) + "}};";
            s11Str = s11Str + String.valueOf(omega22_.get_sigmaMatrix().lastElement().lastElement()/astar_.get_sigmaMatrix().lastElement().lastElement()) + "}};";

        }

        writer.println("\t" + d11Str + "\n");
        writer.println("\t" + d22Str + "\n");
        writer.println("\t" + T11Str + "\n");
        writer.println("\t" + T22Str + "\n");
        writer.println("\t" + s11Str + "\n");
        writer.println("\t" + s22Str + "\n");


        writer.println("\tdouble [] dsigma11()");
        writer.println("\t{");
        writer.println("\t\treturn dsigma11_;");
        writer.println("\t}\n");

        writer.println("\tdouble [] dsigma22()");
        writer.println("\t{");
        writer.println("\t\treturn dsigma22_;");
        writer.println("\t}\n");

        writer.println("\tdouble [] Tsigma11()");
        writer.println("\t{");
        writer.println("\t\treturn Tsigma11_;");
        writer.println("\t}\n");

        writer.println("\tdouble [] Tsigma22()");
        writer.println("\t{");
        writer.println("\t\treturn Tsigma22_;");
        writer.println("\t}\n");

        writer.println("\tdouble [][] sigmaMatrix11()");
        writer.println("\t{");
        writer.println("\t\treturn sigmaMatrix11_;");
        writer.println("\t}\n");

        writer.println("\tdouble [][] sigmaMatrix22()");
        writer.println("\t{");
        writer.println("\t\treturn sigmaMatrix22_;");
        writer.println("\t}\n");

        writer.println("\n}\n");
        writer.close();
        
    }

    public static void main(String args[]) throws Exception 
    { 
        ReadTransport readTransport = new ReadTransport("../database/transport.asali");
        ReadThermo    readThermo    = new ReadThermo("../database/thermo.asali");
        ReadOmega     omega22       = new ReadOmega("../database/omega22.asali");
        ReadOmega     astar         = new ReadOmega("../database/astar.asali");

        writeThermo(readThermo,readTransport,"ThermoDatabase.java");
        writeTransport(readTransport,"TransportDatabase.java"); 
        writeOmega(omega22,astar,"OmegaDatabase.java");
    } 
}
