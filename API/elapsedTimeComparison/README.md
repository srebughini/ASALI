# **ASALI: Modeling and beyond**  
## **APIs elapsed time comparison**  
These results are obtained with a *AMD Athlon(tm) II P320 Dual-Core Processor* with *Ubuntu 20.04.1 LTS*.  
You can run the same test on your own computer using the following command:  
`./run.sh -n 100000 --compile`  
### 1. Assumptions  
The performance comparison has the following assumptions:  
* Number of runs: **100000**  
* Elapsed time to initialize **output variables** is **not considered**  
* Elapsed time to initialize **operating condition** is **not considered**  
### 2. Results  
|Language|Total time (s)|Single run time (s)|
|--------|----------------|-------------------|
|C++|6.962e-01|6.962e-06| 
|C|2.953e+00|2.953e-05| 
|Fortran|5.422e-02|5.422e-07| 
