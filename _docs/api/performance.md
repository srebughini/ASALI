---
permalink: /docs/api-performance/
---
<h1 class="text-left"><b>APIs elapsed time comparison</b></h1>
This section reports the comparison of the ASALI APIs in term of computational time. These results are obtained with a *AMD Athlon(tm) II P320 Dual-Core Processor* with *Ubuntu 22.04.3 LTS*.  
If you download ASALI, you can run the same test on your own computer using the following commands:  
```bash  
cd API/elapsedTimeComparison/  
./run.sh -n 2000 -f test.md --compile  
```  

<h2 class="text-left"><b>Assumptions and operating conditions</b></h2>
The gas mixture operating conditions are reported in the following table:  

<table class="table table-striped">
  <thead>
      <tr>
          <th scope="row">Property</th>
          <th>Value</th>
          <th>Unit dimension</th>
      </tr>
  </thead>
  <tbody>
    <tr>
      <th scope="row"><b>Temperature</b></th>
      <td>393.15</td>
      <td>K</td>
    </tr>
    <tr>
      <th scope="row"><b>Pressure</b></th>
      <td>4</td>
      <td>bar</td>
    </tr>
    <tr>
      <th scope="row">H<sub>2</sub></td>
      <td>0.1</td>
      <td>Molar fraction</td>
    </tr>
    <tr>
      <th scope="row">O<sub>2</sub></th>
      <td>0.1</td>
      <td>Molar fraction</td>
    </tr>
    <tr>
      <th scope="row">C<sub>3</sub>H<sub>8</sub></th>
      <td>0.1</td>
      <td>Molar fraction</td>
    </tr>
    <tr>
      <th scope="row">C<sub>2</sub>H<sub>6</sub></th>
      <td>0.1</td>
      <td>Molar fraction</td>
    </tr>
    <tr>
      <th scope="row">CH<sub>4</sub></th>
      <td>0.1</td>
      <td>Molar fraction</td>
    </tr>
    <tr>
      <th scope="row">CO<sub>2</sub></th>
      <td>0.1</td>
      <td>Molar fraction</td>
    </tr>
    <tr>
      <th scope="row">HE</th>
      <td>0.1</td>
      <td>Molar fraction</td>
    </tr>
    <tr>
      <th scope="row">N<sub>2</sub></th>
      <td>0.1</td>
      <td>Molar fraction</td>
    </tr>
    <tr>
      <th scope="row">NH<sub>3</sub></th>
      <td>0.2</td>
      <td>Molar fraction</td>
    </tr>
  </tbody>
</table>

The performance comparison has the following assumptions:  
* Number of runs: **10000**  
* Elapsed time to initialize **output variables** is **not considered**  

<h2 class="text-left"><b>Results</b></h2>
The table reports the compatutational time required to **estimate all thermodynamic and transport properties** and the computational time required to **initialize ASALI**.  

<table class="table table-striped">
  <thead>
      <tr>
        <th scope="row">Language</th>
        <th>Initialization (s)</th>
        <th>Calculation (s)</th>
      </tr>
  </thead>
  <tbody>
    <tr>
      <th scope="row">C++</th>
      <td>7.685e-04</td>
      <td>1.003e-05</td>
    </tr>
    <tr>
      <th scope="row">C</th>
      <td>7.086e-05</td>
      <td>1.196e-04</td>
    </tr>
    <tr>
      <th scope="row">Fortran</th>
      <td>n.a.</td>
      <td>2.751e-06</td>
    </tr>
    <tr>
      <th scope="row">Java</th>
      <td>1.058e-04</td>
      <td>1.575e-05</td>
    </tr>
    <tr>
      <th scope="row">Rust</th>
      <td>1.098e-04</td>
      <td>9.363e-04</td>
    </tr>
    <tr>
      <th scope="row">Octave</th>
      <td>6.621e-03</td>
      <td>8.256e-01</td>
    </tr>
  </tbody>
</table>
