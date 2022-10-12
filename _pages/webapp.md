---
permalink: /pages/webapp/
---


<div class="container">
    <h2 class="text-center"><b>Operating conditions</b></h2>
    <p class="text-left">Insert gas mixture <b>temperature</b> <i class="fa-regular fa-temperature-three-quarters"></i> and <b>pressure</b> <i class="fa-regular fa-gauge"></i> conditions:</p>
    <div class="form-group">
            <div class="input-group">
                <span class="input-group-addon text-left" id="T-addon"><i class="fa-regular fa-temperature-three-quarters"></i>&nbsp;&nbsp;</span>
                <input type="number" class="form-control text-right" placeholder="298.15" aria-describedby="T-addon" id="T" min="0" max="2000">
                <span class="input-group-addon text-right" id="T-addon">K&ensp;</span>
            </div>
    </div>
    <div class="form-group">
        <div class="input-group">
            <span class="input-group-addon text-left" id="T-addon"><i class="fa-regular fa-gauge"></i></span>
            <input type="number" class="form-control text-right" placeholder="101325" aria-describedby="P-addon" id="P" min="0">
            <span class="input-group-addon text-right">Pa</span>
        </div>
    </div>
    <h2 class="text-center"><b>Composition</b></h2>
    <p class="text-left">Insert gas mixture <b>molecule name</b> <i class="fa-regular fa-atom"></i> and <b>mole fraction</b> <i class="fa-regular fa-chart-pie"></i> composition: </p>
    <div class="form-group">
        <div class="input-group">
                <span class="input-group-addon text-center" id="n1-addon"><i class="fa-regular fa-atom"></i></span>
                <select style="min-width:100%;width:50px;" class="form-control text-left" aria-describedby="n1-addon" id="n1" onload="showSpeciesList()";>
                    <option value="">Select species..</option>
                    <option>H2</option>
                    <option>O2</option>
                </select>
                <!--<input type="text" style="min-width:100%;width:50px;" class="form-control text-right" placeholder="H2" aria-describedby="n1-addon" id="n1">-->
                <span class="input-group-addon text-center" id="x1-addon"><i class="fa-regular fa-chart-pie"></i></span> 
                <input type="number" style="min-width:100%;width:50px;" class="form-control text-right" placeholder="0.5" aria-describedby="x1-addon" id="x1" min="0" max="1">
        </div>
    </div>
    <div class="form-group">
        <div class="input-group">
                <span class="input-group-addon text-center" id="n2-addon"><i class="fa-regular fa-atom"></i></span> 
                <input type="text" style="min-width:100%;width:50px;" class="form-control text-right" placeholder="H2" aria-describedby="n2-addon" id="n2">
                <span class="input-group-addon text-center" id="x2-addon"><i class="fa-regular fa-chart-pie"></i></span> 
                <input type="number" style="min-width:100%;width:50px;" class="form-control text-right" placeholder="0.5" aria-describedby="x2-addon" id="x2" min="0" max="1">
        </div>
    </div>
    <div class="form-group">
        <div class="input-group">
                <span class="input-group-addon text-center" id="n3-addon"><i class="fa-regular fa-atom"></i></span> 
                <input type="text" style="min-width:100%;width:50px;" class="form-control text-right" placeholder="H2" aria-describedby="n3-addon" id="n3">
                <span class="input-group-addon text-center" id="x3-addon"><i class="fa-regular fa-chart-pie"></i></span> 
                <input type="number" style="min-width:100%;width:50px;" class="form-control text-right" placeholder="0.5" aria-describedby="x3-addon" id="x3" min="0" max="1">
        </div>
    </div>
    <div class="form-group">
        <div class="input-group">
                <span class="input-group-addon text-center" id="n4-addon"><i class="fa-regular fa-atom"></i></span> 
                <input type="text" style="min-width:100%;width:50px;" class="form-control text-right" placeholder="H2" aria-describedby="n4-addon" id="n4">
                <span class="input-group-addon text-center" id="x4-addon"><i class="fa-regular fa-chart-pie"></i></span> 
                <input type="number" style="min-width:100%;width:50px;" class="form-control text-right" placeholder="0.5" aria-describedby="x4-addon" id="x4" min="0" max="1">
        </div>
    </div>
    <div class="form-group">
        <div class="input-group">
                <span class="input-group-addon text-center" id="n5-addon"><i class="fa-regular fa-atom"></i></span> 
                <input type="text" style="min-width:100%;width:50px;" class="form-control text-right" placeholder="H2" aria-describedby="n5-addon" id="n5">
                <span class="input-group-addon text-center" id="x5-addon"><i class="fa-regular fa-chart-pie"></i></span> 
                <input type="number" style="min-width:100%;width:50px;" class="form-control text-right" placeholder="0.5" aria-describedby="x5-addon" id="x5" min="0" max="1">
        </div>
    </div>
    <div class="form-group">
        <div class="input-group">
                <span class="input-group-addon text-center" id="n6-addon"><i class="fa-regular fa-atom"></i></span> 
                <input type="text" style="min-width:100%;width:50px;" class="form-control text-right" placeholder="H2" aria-describedby="n6-addon" id="n6">
                <span class="input-group-addon text-center" id="x6-addon"><i class="fa-regular fa-chart-pie"></i></span> 
                <input type="number" style="min-width:100%;width:50px;" class="form-control text-right" placeholder="0.5" aria-describedby="x6-addon" id="x6" min="0" max="1">
        </div>
    </div>
    <div class="form-group">
        <div class="input-group">
                <span class="input-group-addon text-center" id="n7-addon"><i class="fa-regular fa-atom"></i></span> 
                <input type="text" style="min-width:100%;width:50px;" class="form-control text-right" placeholder="H2" aria-describedby="n7-addon" id="n7">
                <span class="input-group-addon text-center" id="x7-addon"><i class="fa-regular fa-chart-pie"></i></span> 
                <input type="number" style="min-width:100%;width:50px;" class="form-control text-right" placeholder="0.5" aria-describedby="x7-addon" id="x7" min="0" max="1">
        </div>
    </div>
    <div class="form-group">
        <div class="input-group">
                <span class="input-group-addon text-center" id="n8-addon"><i class="fa-regular fa-atom"></i></span> 
                <input type="text" style="min-width:100%;width:50px;" class="form-control text-right" placeholder="H2" aria-describedby="n8-addon" id="n8">
                <span class="input-group-addon text-center" id="x8-addon"><i class="fa-regular fa-chart-pie"></i></span> 
                <input type="number" style="min-width:100%;width:50px;" class="form-control text-right" placeholder="0.5" aria-describedby="x8-addon" id="x8" min="0" max="1">
        </div>
    </div>
    <div class="form-group">
        <div class="input-group">
                <span class="input-group-addon text-center" id="n9-addon"><i class="fa-regular fa-atom"></i></span> 
                <input type="text" style="min-width:100%;width:50px;" class="form-control text-right" placeholder="H2" aria-describedby="n9-addon" id="n9">
                <span class="input-group-addon text-center" id="x9-addon"><i class="fa-regular fa-chart-pie"></i></span> 
                <input type="number" style="min-width:100%;width:50px;" class="form-control text-right" placeholder="0.5" aria-describedby="x9-addon" id="x9" min="0" max="1">
        </div>
    </div>
    <div class="form-group">
        <div class="input-group">
                <span class="input-group-addon text-center" id="n10-addon"><i class="fa-regular fa-atom"></i></span> 
                <input type="text" style="min-width:100%;width:50px;" class="form-control text-right" placeholder="H2" aria-describedby="n10-addon" id="n10">
                <span class="input-group-addon text-center" id="x10-addon"><i class="fa-regular fa-chart-pie"></i></span> 
                <input type="number" style="min-width:100%;width:50px;" class="form-control text-right" placeholder="0.5" aria-describedby="x10-addon" id="x10" min="0" max="1">
        </div>
    </div>
</div>

<div class="container">
    <p class="text-center"><button class="btn btn-primary btn-lg" onclick="runWebApp();"><i class="fa-regular fa-power-off"></i>&nbsp;&nbsp;&nbsp;&nbsp;Run</button></p>
</div>

