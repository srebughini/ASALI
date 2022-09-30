var NSinput = 10;

var transportPageUrl = "https://srebughini.github.io/ASALI/results/transport-properties"
var thermoPageUrl = "https://srebughini.github.io/ASALI/results/thermodynamic-properties"
var eqTPPageUrl = "https://srebughini.github.io/ASALI/results/equilibrium-@-constant-t-p"

var name_id_prefix = "n";
var value_id_prefix = "x";
var T_id = "T";
var P_id = "P";

function readComposition() {
  const composition = {};
  for (let i = 0; i < NSinput; i++) {
    let name = document.getElementById(name_id_prefix.concat(i + 1)).value;
    let value = parseFloat(document.getElementById(value_id_prefix.concat(i + 1)).value);
    if (name) {
      if (!isNaN(value)) {
        composition[name] = value;
      }
    }
  }
  return composition;
}

function readTemperature() {
    return parseFloat(document.getElementById(T_id).value);
}

function readPressure() {
    return parseFloat(document.getElementById(P_id).value);
}

function estimateMixtureProperties() {
  //Read temperature
  let T = readTemperature();

  //Read pressure
  let P = readPressure();

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
    let composition = readComposition()

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
        {"name": "Molecular weight", "value": mixture.getMolecularWeight(), "ud": "kg/kmol"},
        {"name": "Density", "value": mixture.getDensity(), "ud": "kg/m<sup>3</sup>"},
        {"name": "Viscosity", "value": mixture.getViscosity(), "ud": "Pas"},
        {"name": "Diffusivity", "value": diff, "ud": "m<sup>2</sup>/s"},
        {"name": "Thermal conductivity", "value": mixture.getThermalConductivity(), "ud": "W/m/K"}
      ],
      "thermo": [
        {"name": "Specific heat", "value": mixture.getMassSpecificHeat(), "ud": "J/kg/K"},
        {"name": "Enthalpy", "value": mixture.getMassEnthalpy(), "ud": "J/kg"},
        {"name": "Entropy", "value": mixture.getMassEntropy(), "ud": "J/kg/K"},
        {"name": "Gibbs free energy", "value": mixture.getMassGibbsFreeEnergy(), "ud": "J/kg"},
        {"name": "Internal energy", "value": mixture.getMassInternalEnergy(), "ud": "J/kg"}
      ],
      "temperature": T,
      "pressure": P,
      "composition": {"name": mixture.getSpeciesName(),
                      "mole": mixture.getMoleFraction(),
                      "mass": mixture.getMassFraction()}
      }

      return output;
    }
  }
}


function showOperatingConditions(results, doc)
{
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
    nameCell.id = name_id_prefix.concat(i+1);
    moleCell.innerHTML = parseFloat(mole[i]).toExponential(3);
    moleCell.id = value_id_prefix.concat(i+1);
    massCell.innerHTML = parseFloat(mass[i]).toExponential(3);
  }
}

function runWebApp()
{
    // Estimate mixture properties
    let results = estimateMixtureProperties();

    if (Object.keys(output).length > 0 )
    {
      // Genere new window object
      let destinationWindow = window.open(transportPageUrl, "_blank");

      //Opening a window is asynchronous
      destinationWindow.onload = function()
      {
        showOperatingConditions(results, destinationWindow.document);
      }
    }
}

function showResults(destinationPageUrl)
{
  // Estimate mixture properties
  let results = estimateMixtureProperties();
  if (Object.keys(output).length > 0 )
  {
    // Genere new window object
    let destinationWindow = window.open(transportPageUrl); //, "_blank");

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
  }
  else
  {
    return false;
  }
}