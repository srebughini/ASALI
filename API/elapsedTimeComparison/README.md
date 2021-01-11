# **ASALI: Modeling and beyond**  
## **APIs elapsed time comparison**  
These results are obtained with a *AMD Athlon(tm) II P320 Dual-Core Processor* with *Ubuntu 20.04.1 LTS*.  
If you download ASALI, you can run the same test on your own computer using the following commands:  
```bash  
cd API/elapsedTimeComparison/  
./run.sh -n 30000 -f test.md --compile  
```  
## Assumptions and operating conditions  
The gas mixture operating conditions are reported in the following table:  
|Property|Value|Unit dimension|  
|--------|-----|--------------|  
|Temperature|393.15|K|  
|Pressure|4|bar|  
|H<sub>2</sub>|0.1|Molar fraction|  
|O<sub>2</sub>|0.2|Molar fraction|  
|N<sub>2</sub>|0.7|Molar fraction|  
 
The performance comparison has the following assumptions:  
* Number of runs: **30000**  
* Elapsed time to initialize **output variables** is **not considered**  
## Results  
The table reports the compatutational time required to **estimate all thermodynamic and transport properties** and the computational time required to **initialize ASALI**.  
|Language|Initialization (s)|Estimation (s)|  
|--------|----------------|-------------------|  
|C++|2.371e-03|6.821e-06| 
|C|3.965e-04|3.032e-05| 
|Fortran|n.a.|6.991e-07| 
