var NSinput = 10;
var mainDoc = window.document
var destinationPageUrl = "https://srebughini.github.io/ASALI/results/operating-conditions"

function readComposition() {
  const composition = {};
  let name_id = "n";
  let value_id = "x";

  for (let i = 0; i < NSinput; i++) {
    let name = mainDoc.getElementById(name_id.concat(i + 1)).value;
    let value = parseFloat(mainDoc.getElementById(value_id.concat(i + 1)).value);
    if (name) {
      if (!isNaN(value)) {
        composition[name] = value;
      }
    }
  }
  return composition;
}

function readTemperature() {
    return parseFloat(mainDoc.getElementById("T").value);
}

function readPressure() {
    return parseFloat(mainDoc.getElementById("P").value);
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

function runWebApp()
{
    // Estimate mixture properties
    var output = estimateMixtureProperties();

    if (Object.keys(output).length > 0 )
    {
      let properties = output["properties"];
      let name = output["composition"]["name"];
      let mole = output["composition"]["mole"];
      let mass = output["composition"]["mass"];

      // Genere new window object
      var transportWindow = window.open(destinationPageUrl, "_blank");

      //Opening a window is asynchronous
      transportWindow.onload = function()
      {
        let transportDoc = transportWindow.document;
        let inputTable = transportDoc.getElementById("input-table")

        transportDoc.getElementById("T").innerHTML = output["temperature"];
        transportDoc.getElementById("P").innerHTML = output["pressure"];

        for (let i = 0; i < name.length; i++) { 
          let newRow = inputTable.insertRow(-1);
          let nameCell = newRow.insertCell(0);
          let moleCell = newRow.insertCell(1);
          let massCell = newRow.insertCell(2);
          nameCell.innerHTML = name[i];
          moleCell.innerHTML = parseFloat(mole[i]).toExponential(3);
          massCell.innerHTML = parseFloat(mass[i]).toExponential(3);
        }
      }
    }
}

function prova(id)
{
  alert("Sto provando: ", id);
  return true;
}