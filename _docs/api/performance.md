---
permalink: /docs/api-performance/
redirect_from: /docs/index.html
---

# **APIs elapsed time comparison**  
This section reports the comparison of the ASALI APIs in term of computational time. These results are obtained with a *AMD Athlon(tm) II P320 Dual-Core Processor* with *Ubuntu 20.04.1 LTS*.   
If you download ASALI, you can run the same test on your own computer using the following commands:  
`cd API/elapsedTimeComparison/`  
`./run.sh -n 100000 --compile`  
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
* Number of runs: **100000**  
* Elapsed time to initialize **output variables** is **not considered**  
* Elapsed time to initialize **operating condition** is **not considered**  

## Results  
The table reports the compatutational time required to **estimate all thermodynamic and transport properties** and the computational time required to **initialize ASALI**.

|Language|Initialization (s)|Estimation (s)|
|--------|----------------|-------------------|
|C++|6.962e-01|6.962e-06| 
|C|2.953e+00|2.953e-05| 
|Fortran|5.422e-02|5.422e-07|
