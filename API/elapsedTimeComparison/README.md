# **ASALI: Modeling and beyond**  
## **APIs elapsed time comparison**  
These results are obtained with a *AMD Athlon(tm) II P320 Dual-Core Processor* with *Ubuntu 22.04.3 LTS*.  
If you download ASALI, you can run the same test on your own computer using the following commands:  
```bash  
cd API/elapsedTimeComparison/  
./run.sh -n 2000 -f test.md --compile  
```  
## Assumptions and operating conditions  
The gas mixture operating conditions are reported in the following table:  
|Property|Value|Unit dimension|  
|--------|-----|--------------|  
|Temperature|393.15|K|  
|Pressure|4|bar|  
|H<sub>2</sub>|0.1|Molar fraction|  
|O<sub>2</sub>|0.1|Molar fraction|  
|C<sub>3</sub>H<sub>8</sub>|0.1|Molar fraction|  
|C<sub>2</sub>H<sub>6</sub>|0.1|Molar fraction|  
|CH<sub>4</sub>|0.1|Molar fraction|  
|CO<sub>2</sub>|0.1|Molar fraction|  
|HE|0.1|Molar fraction|  
|N<sub>2</sub>|0.1|Molar fraction|  
|NH<sub>3</sub>|0.2|Molar fraction|  
 
The performance comparison has the following assumptions:  
* Number of runs: **2000**  
* Elapsed time to initialize **output variables** is **not considered**  
## Results  
The table reports the compatutational time required to **estimate all thermodynamic and transport properties** and the computational time required to **initialize ASALI**.  
|Language|Initialization (s)|Calculation (s)|  
|--------|----------------|-------------------|  
|C++|7.588e-04|1.006e-05| 
|C|7.030e-05|1.197e-04| 
|Fortran|n.a.|2.863e-06| 
|Java|9.980e-05|1.603e-05| 
|Rust|1.102e-4|7.897e-4| 
|Octave|6.782e-03|8.205e-01| 
|Python|2.900e-05|1.433e-02|
