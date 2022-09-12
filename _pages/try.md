---
permalink: /pages/try/
redirect_from: /docs/index.html
---


<div class="container">
    <h2 class="text-center"><b>Gas mixture conditions</b></h2>
    <div class="form-group">
            <div class="input-group">
                <span class="input-group-addon text-center" id="T-addon">Temperature</span>
                <input type="number" class="form-control text-right" placeholder="298.15" aria-describedby="T-addon" id="T" min="0">
                <span class="input-group-addon text-center" id="T-addon">K</span>
            </div>
    </div>
    <div class="form-group">
        <div class="input-group">
            <span class="input-group-addon text-center" id="P-addon">Pressure</span>
            <input type="number" class="form-control text-right" placeholder="101325" aria-describedby="P-addon" id="P" min="0">
            <span class="input-group-addon text-center">Pa</span>
        </div>
    </div>
</div>

<div class="container">
    <h2 class="text-center"><b>Gas mixture mole fraction</b></h2>
    <div class="row">
        <div class="form-group">
            <div class="input-group">
                    <span style="width:10%" class="input-group-addon text-center" id="s1-addon">#1 Name</span> 
                    <input style="width:40%" type="text" class="form-control text-right" placeholder="H2" aria-describedby="n1-addon" id="n1">
                    <span style="width:10%" class="input-group-addon text-center" id="x1-addon">Fraction</span> 
                    <input style="width:40%" type="number" class="form-control text-right" placeholder="0.5" aria-describedby="x1-addon" id="x1" min="0" max="1">
            </div>
        </div>
    </div>
    <!--
    <div class="form-group">
        <div class="input-group">
            <span class="input-group-addon text-center" id="n1-addon">#1</span> 
            <input type="text" class="form-control text-right" placeholder="Name (Ex. H2)" aria-describedby="n1-addon" id="n1">
        </div>
        <div class="input-group">
            <span class="input-group-addon text-center" id="x1-addon">#1</span> 
            <input type="number" class="form-control text-right" placeholder="Mole fraction (Ex. 0.5)" aria-describedby="x1-addon" id="x1" min="0" max="1">
        </div>
    </div>
    <div class="form-group">
        <div class="input-group">
            <span class="input-group-addon text-center" id="s2-addon">#1</span> 
            <span class="input-group-addon text-center" id="n2-addon">Name</span> 
            <input type="text" class="form-control text-right" placeholder="H2" aria-describedby="n2-addon" id="n2">
            <span class="input-group-addon text-center" id="x2-addon">Fraction</span> 
            <input type="number" class="form-control text-right" placeholder="0.5" aria-describedby="x2-addon" id="x2" min="0" max="1">
        </div>
    </div>
    -->
</div>

<!--
<div class="container">
    <h2 class="text-center"><b>Gas mixture conditions</b></h2>
    <div class="row">
        <div class="col-sm-6 text-center">
            <input type="number" class="form-control" placeholder="Temperature in K" id="T">
        </div>
        <div class="col-sm-6 text-center">
            <input type="number" class="form-control" placeholder="Pressure in Pa" id="P">
        </div>
    </div>
</div>
<div class="container">
    <h2 class="text-center"><b>Gas mixture mole fraction</b></h2>
    <div class="row">
        <div class="col-sm-4 text-center">
            <p>Specie #1</p>
        </div>
        <div class="col-sm-4 text-center">
            <input type="text" class="form-control" placeholder="Name" id="n1">
        </div>
        <div class="col-sm-4 text-center">
            <input type="number" class="form-control" placeholder="Mole fraction" id="x1">
        </div>
        <div class="w-100"></div>
        <div class="col-sm-4 text-center">
            <p>Specie #1</p>
        </div>
        <div class="col-sm-4 text-center">
            <input type="text" class="form-control" placeholder="Name" id="n2">
        </div>
        <div class="col-sm-4 text-center">
            <input type="number" class="form-control" placeholder="Mole fraction" id="x2">
        </div>
    </div>
</div>
-->
<!--
<p></p>
<div class="row">
    <div class="col-sm-6 text-center">
        <input type="text" class="form-control" placeholder="Specie name" id="n3">
    </div>
    <div class="col-sm-6 text-center">
        <input type="number" class="form-control" placeholder="Mole fraction" id="x3">
    </div>
</div>
<p></p>
<div class="row">
    <div class="col-sm-6 text-center">
        <input type="text" class="form-control" placeholder="Specie name" id="n4">
    </div>
    <div class="col-sm-6 text-center">
        <input type="number" class="form-control" placeholder="Mole fraction" id="x4">
    </div>
</div>
<p></p>
<div class="row">
    <div class="col-sm-6 text-center">
        <input type="text" class="form-control" placeholder="Specie name" id="n5">
    </div>
    <div class="col-sm-6 text-center">
        <input type="number" class="form-control" placeholder="Mole fraction" id="x5">
    </div>
</div>
<p></p>
<div class="row">
    <div class="col-sm-6 text-center">
        <input type="text" class="form-control" placeholder="Specie name" id="n6">
    </div>
    <div class="col-sm-6 text-center">
        <input type="number" class="form-control" placeholder="Mole fraction" id="x6">
    </div>
</div>
<p></p>
<div class="row">
    <div class="col-sm-6 text-center">
        <input type="text" class="form-control" placeholder="Specie name" id="n7">
    </div>
    <div class="col-sm-6 text-center">
        <input type="number" class="form-control" placeholder="Mole fraction" id="x7">
    </div>
</div>
<p></p>
<div class="row">
    <div class="col-sm-6 text-center">
        <input type="text" class="form-control" placeholder="Specie name" id="n8">
    </div>
    <div class="col-sm-6 text-center">
        <input type="number" class="form-control" placeholder="Mole fraction" id="x8">
    </div>
</div>
<p></p>
<div class="row">
    <div class="col-sm-6 text-center">
        <input type="text" class="form-control" placeholder="Specie name" id="n9">
    </div>
    <div class="col-sm-6 text-center">
        <input type="number" class="form-control" placeholder="Mole fraction" id="x9">
    </div>
</div>
<p></p>
<div class="row">
    <div class="col-sm-6 text-center">
        <input type="text" class="form-control" placeholder="Specie name" id="n10">
    </div>
    <div class="col-sm-6 text-center">
        <input type="number" class="form-control" placeholder="Mole fraction" id="x10">
    </div>
</div>
<p></p>
-->
<div class="row">
    <div class="col-sm-6 text-center">
        <button class="btn btn-primary btn-lg"><i class="fa fa-rocket" aria-hidden="true"></i>    Estimate properties</button>
    </div>
    <div class="col-sm-6 text-center">
        <button class="btn btn-primary btn-lg"><i class="fa fa-spinner" aria-hidden="true"></i>   Calculate equilibrium</button>
    </div>
</div>

