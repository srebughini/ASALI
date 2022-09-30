var NSinput = 10;

var transportPageUrl = "https://srebughini.github.io/ASALI/results/transport-properties"
var thermoPageUrl = "https://srebughini.github.io/ASALI/results/thermodynamic-properties"
var eqTPPageUrl = "https://srebughini.github.io/ASALI/results/equilibrium-@-constant-t-p"

var name_id_prefix = "n";
var value_id_prefix = "x";
var T_id = "T";
var P_id = "P";

function readComposition(fromInput) {
  const composition = {};
  for (let i = 0; i < NSinput; i++) {
    let name_obj = document.getElementById(name_id_prefix.concat(i + 1));
    if (name_obj)
    {
      let value_obj = document.getElementById(value_id_prefix.concat(i + 1));
      if (value_obj)
      {
        let value;
        let name;
        if (fromInput){
          name = name_obj.value;
          value = value_obj.value;
        }
        else
        {
          name = name_obj.innerText;
          value = value_obj.innerText;
        }

        console.log(name, value);

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

      let diff = {};
      mixture.getSpeciesName().forEach((key, i) => diff[key] = mixture.getMixtureDiffusion()[i]);

      //Extract output from the mixture object
      output = {
        "transport": [
          { "name": "Molecular weight", "value": mixture.getMolecularWeight(), "ud": "kg/kmol" },
          { "name": "Density", "value": mixture.getDensity(), "ud": "kg/m<sup>3</sup>" },
          { "name": "Viscosity", "value": mixture.getViscosity(), "ud": "Pas" },
          { "name": "Diffusivity", "value": diff, "ud": "m<sup>2</sup>/s" },
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
        }
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

function runWebApp() {
  // Estimate mixture properties
  let results = estimateMixtureProperties(true);

  if (Object.keys(output).length > 0) {
    // Genere new window object
    let destinationWindow = window.open(transportPageUrl, "_blank");

    //Opening a window is asynchronous
    destinationWindow.onload = function () {
      showOperatingConditions(results, destinationWindow.document);
    }
  }
}

function showResults(destinationPageUrl) {
  // Estimate mixture properties
  let results = readComposition(false);

  if (Object.keys(results).length > 0) {
    // Genere new window object
    let destinationWindow = window.open(destinationPageUrl, "_blank");

    //Opening a window is asynchronous
    destinationWindow.onload = function()
    {
      showOperatingConditions(results, destinationWindow.document);
      if (destinationPageUrl == transportPageUrl)
      {
        return false;
      }
      else if (destinationPageUrl == thermoPageUrl)
      {
        return false;
      }
      else if (destinationPageUrl == eqTPPageUrl)
      {
        return false;
      }
      else
      {
        return false;
      }
    }
    return false;
  }
  else {
    return false;
  }
}