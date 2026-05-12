# **ASALI: Modeling and beyond**  
## **APIs elapsed time comparison**  
These results are obtained with a *Intel(R) Core(TM) i7-10700K CPU @ 3.80GHz* with *Windows*.  
If you download ASALI, you can run the same test on your own computer using the following commands:  
```bash  
cd API/elapsedTimeComparison/  
./run.sh -n 10000 -f test.md --compile  
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
* Number of runs: **10000**  
* Elapsed time to initialize **output variables** is **not considered**  
## Results  
The table reports the compatutational time required to **estimate all thermodynamic and transport properties** and the computational time required to **initialize ASALI**.  
|Language|Initialization (s)|Calculation (s)|  
|--------|----------------|-------------------|  
|C++ |  3.523e-04|     3.300e-06|
|C |  4.040e-05|     2.340e-05|
|Fortran |  n.a.|         2.444e-07|
|Java |  1.332e-05|     1.183e-06|
|Rust |  4.995e-5|     2.806e-4|
|Octave |  1.522e-02|     3.752e-01|
|Python |  6.823e-06|     2.972e-03|
|Julia |  n.a.|     8.018e-04|
