var NSinput = 10;

var transportPageUrl = "/ASALI/results/transport-properties/"
var thermoPageUrl = "/ASALI/results/thermodynamic-properties/"
var eqTPPageUrl = "/ASALI/results/equilibrium-@-constant-t-p/"

var name_id_prefix = "n";
var value_id_prefix = "x";
var T_id = "T";
var P_id = "P";

function readComposition(fromInput) {
  const composition = {};
  for (let i = 0; i < NSinput; i++) {
    let name_obj = document.getElementById(name_id_prefix.concat(i + 1));
    if (name_obj) {
      let value_obj = document.getElementById(value_id_prefix.concat(i + 1));
      if (value_obj) {
        let value;
        let name;
        if (fromInput) {
          name = name_obj.value;
          value = value_obj.value;
        }
        else {
          name = name_obj.innerText;
          value = value_obj.innerText;
        }
        if (name) {
          if (!isNaN(value)) {
            composition[name] = value;
          }
        }
      }
    }
  }
  return composition;
}

function readTemperature(fromInput) {
  if (fromInput) {
    return parseFloat(document.getElementById(T_id).value);
  }
  return parseFloat(document.getElementById(T_id).innerText);
}

function readPressure(fromInput) {
  if (fromInput) {
    return parseFloat(document.getElementById(P_id).value);
  }
  return parseFloat(document.getElementById(P_id).innerText);
}

function estimateMixtureProperties(fromInput) {
  //Read temperature
  let T = readTemperature(fromInput);

  //Read pressure
  let P = readPressure(fromInput);

  if (isNaN(T)) {
    alert("Temperature input not valid!");
    return {};
  }
  else if (isNaN(P)) {
    alert("Pressure input not valid!");
    return {};
  }
  else {
    //Generate state object
    let state = jasali.GasState({
      temperature: T,
      pressure: P
    })

    //Read composition
    let composition = readComposition(fromInput)

    if (Object.keys(composition).length == 0) {
      alert("Input composition not valid!");
      return {};
    }
    else {
      //Generate mixture object
      let mixture = jasali.GasMixture({
        mixtureComposition: composition,
        gasState: state,
        compositionType: "mole"
      })

      let moleEQ = mixture.calculateChemicalEquilibriumTP();

      console.log(moleEQ);

      //Extract output from the mixture object
      output = {
        "transport": [
          { "name": "Molecular weight", "value": mixture.getMolecularWeight(), "ud": "kg/kmol" },
          { "name": "Density", "value": mixture.getDensity(), "ud": "kg/m<sup>3</sup>" },
          { "name": "Viscosity", "value": mixture.getViscosity(), "ud": "Pas" },
          { "name": "Thermal conductivity", "value": mixture.getThermalConductivity(), "ud": "W/m/K" }
        ],
        "thermo": [
          { "name": "Specific heat", "value": mixture.getMassSpecificHeat(), "ud": "J/kg/K" },
          { "name": "Enthalpy", "value": mixture.getMassEnthalpy(), "ud": "J/kg" },
          { "name": "Entropy", "value": mixture.getMassEntropy(), "ud": "J/kg/K" },
          { "name": "Gibbs free energy", "value": mixture.getMassGibbsFreeEnergy(), "ud": "J/kg" },
          { "name": "Internal energy", "value": mixture.getMassInternalEnergy(), "ud": "J/kg" }
        ],
        "temperature": T,
        "pressure": P,
        "composition": {
          "name": mixture.getSpeciesName(),
          "mole": mixture.getMoleFraction(),
          "mass": mixture.getMassFraction()
        },
        "diffusivity": { "value": mixture.getMixtureDiffusion(), "ud": "m<sup>2</sup>/s" },
      }

      return output;
    }
  }
}

function showOperatingConditions(results, doc) {
  let name = results["composition"]["name"];
  let mole = results["composition"]["mole"];
  let mass = results["composition"]["mass"];
  let inputTable = doc.getElementById("input-table")

  doc.getElementById(T_id).innerHTML = results["temperature"];
  doc.getElementById(P_id).innerHTML = results["pressure"];

  for (let i = 0; i < name.length; i++) {
    let newRow = inputTable.insertRow(-1);
    let nameCell = newRow.insertCell(0);
    let moleCell = newRow.insertCell(1);
    let massCell = newRow.insertCell(2);
    nameCell.innerHTML = name[i];
    nameCell.id = name_id_prefix.concat(i + 1);
    moleCell.innerHTML = parseFloat(mole[i]).toExponential(3);
    moleCell.id = value_id_prefix.concat(i + 1);
    massCell.innerHTML = parseFloat(mass[i]).toExponential(3);
  }
}

function showTransportProperties(results, doc) {
  let properties = results["transport"];
  let outputTable = doc.getElementById("output-table")

  for (let i = 0; i < properties.length; i++) {
    let newRow = outputTable.insertRow(-1);
    let nameCell = newRow.insertCell(0);
    let valueCell = newRow.insertCell(1);
    let udCell = newRow.insertCell(2);
    nameCell.innerHTML = properties[i]["name"];
    valueCell.innerHTML = parseFloat(properties[i]["value"]).toExponential(3);
    udCell.innerHTML = properties[i]["ud"];
  }


  // Diffifusivity main line
  {
    let newRow = outputTable.insertRow(-1);
    let nameCell = newRow.insertCell(0);
    newRow.insertCell(1);
    newRow.insertCell(2);
    nameCell.innerHTML = "Diffusivity";
  }

  {
    let diffValues = results["diffusivity"]["value"];
    let diffUd = results["diffusivity"]["ud"];
    let name = results["composition"]["name"]; 
    for (let i = 0; i < diffValues.length; i++) {
      let newRow = outputTable.insertRow(-1);
      let nameCell = newRow.insertCell(0);
      let valueCell = newRow.insertCell(1);
      let udCell = newRow.insertCell(2);
      nameCell.innerHTML = name[i];
      valueCell.innerHTML = parseFloat(diffValues[i]).toExponential(3);
      udCell.innerHTML = diffUd;
    }
  }
}

function showThermoProperties(results, doc) {
  let properties = results["thermo"];
  let outputTable = doc.getElementById("output-table")

  for (let i = 0; i < properties.length; i++) {
    let newRow = outputTable.insertRow(-1);
    let nameCell = newRow.insertCell(0);
    let valueCell = newRow.insertCell(1);
    let udCell = newRow.insertCell(2);
    nameCell.innerHTML = properties[i]["name"];
    valueCell.innerHTML = parseFloat(properties[i]["value"]).toExponential(3);
    udCell.innerHTML = properties[i]["ud"];
  }
}


function runWebApp() {
  // Estimate mixture properties
  let results = estimateMixtureProperties(true);

  if (Object.keys(output).length > 0) {
    // Genere new window object
    let destinationWindow = window.open(transportPageUrl, "_blank");

    //Opening a window is asynchronous
    destinationWindow.onload = function () {
      showOperatingConditions(results, destinationWindow.document);
      showTransportProperties(results, destinationWindow.document)
    }
  }
}

function showResults(destinationPageUrl) {
  // Estimate mixture properties
  let results = estimateMixtureProperties(false);

  if (Object.keys(results).length > 0) {
    // Genere new window object
    let destinationWindow = window.open(destinationPageUrl, "_blank");

    //Opening a window is asynchronous
    destinationWindow.onload = function () {
      showOperatingConditions(results, destinationWindow.document);
      if (destinationPageUrl === transportPageUrl) {
        showTransportProperties(results, destinationWindow.document);
        return false;
      }
      else if (destinationPageUrl == thermoPageUrl) {
        showThermoProperties(results, destinationWindow.document);
        return false;
      }
      else if (destinationPageUrl == eqTPPageUrl) {
        // TO DO - Add Equilibrium
        return false;
      }
      else {
        return false;
      }
    }
    return false;
  }
  else {
    return false;
  }
}