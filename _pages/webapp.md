---
permalink: /pages/webapp/
---


<div class="container" id="inputContainer">
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
                <select style="min-width:100%;width:50px;" class="form-control text-left" aria-describedby="n1-addon" id="n1">
                    <option value="">Select...</option>
                </select>
                <span class="input-group-addon text-center" id="x1-addon"><i class="fa-regular fa-chart-pie"></i></span> 
                <input type="number" style="min-width:100%;width:50px;" class="form-control text-right" placeholder="0.5" aria-describedby="x1-addon" id="x1" step="0.01" min="0" max="1">
        </div>
    </div>
</div>

<div class="container">
    <p class="text-center"><button class="btn btn-primary btn-lg" onclick="runWebApp();"><i class="fa-regular fa-power-off"></i>&nbsp;&nbsp;&nbsp;&nbsp;Run</button>
    <button class="btn btn-primary btn-lg" onclick="addInputLine();"><i class="fa-solid fa-circle-plus"></i>&nbsp;&nbsp;&nbsp;&nbsp;Add</button></p>
</div>

