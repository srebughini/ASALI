# **ASALI: Modeling and beyond**  
## **APIs elapsed time comparison**  
These results are obtained with a *AMD Athlon(tm) II P320 Dual-Core Processor* with *Ubuntu 22.04.3 LTS*.  
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
|O<sub>2</sub>|0.2|Molar fraction|  
|N<sub>2</sub>|0.7|Molar fraction|  
 
The performance comparison has the following assumptions:  
* Number of runs: **10000**  
* Elapsed time to initialize **output variables** is **not considered**  
## Results  
The table reports the compatutational time required to **estimate all thermodynamic and transport properties** and the computational time required to **initialize ASALI**.  
|Language|Initialization (s)|Calculation (s)|  
|--------|----------------|-------------------|  
|C++|2.364e-03|6.794e-06| 
|C|3.400e-04|3.121e-05| 
|Fortran|n.a.|5.447e-07| 
|Java|2.531e-04|7.306e-06| 
|Rust|4.508e-04|8.546e-04| 