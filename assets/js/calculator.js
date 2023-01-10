var transportPageUrl = "/ASALI/results/transport-properties/";
var thermoPageUrl = "/ASALI/results/thermodynamic-properties/";
var eqTPPageUrl = "/ASALI/results/equilibrium-@-constant-t-p/";
var webAppPageUrl = "/ASALI/pages/webapp/";
var resultsPageUrl = "/ASALI/results/";

var webAppResults = "webAppResults";

var name_id_prefix = "n";
var value_id_prefix = "x";
var T_id = "T";
var P_id = "P";
var select_str = "Select";
var inputContainer_id = "inputContainer";


function getInputLineHTML(counter) {
  /**
   * Get the HTML code for the input line to insert specie and mole fraction
   */
  return `
          <div class="form-group">
            <div class="input-group">
                  <span class="input-group-addon text-center" id="${name_id_prefix}${counter}-addon"><i class="fa-regular fa-atom"></i></span>
                  <select style="min-width:100%;width:50px;" class="form-control text-left" aria-describedby="${name_id_prefix}${counter}-addon" id="${name_id_prefix}${counter}">
                      <option value="">Select...</option>
                  </select>
                  <span class="input-group-addon text-center" id="${value_id_prefix}${counter}-addon"><i class="fa-regular fa-chart-pie"></i></span> 
                  <input type="number" style="min-width:100%;width:50px;" class="form-control text-right" placeholder="0.5" aria-describedby="${value_id_prefix}${counter}-addon" id="${value_id_prefix}${counter}" min="0" max="1">
            </div>
          </div>
        `
}

function getNumberOfInput() {
  /**
   * Get the number of input species
   */
  let inputContainer = document.getElementById(inputContainer_id);
  let Ndiv = inputContainer.getElementsByTagName('div').length;
  return Math.floor(Ndiv / 2) - 2
}

function getSpeciesList() {
  /**
   * Get the list of species present in JASALI
   */
  // - TODO: Try to get moleculesDict directly from JASALI
  let moleculesDict = {
    "AR": {
      elementsSymbol: ["Ar"],
      numberOfAtoms: [1]
    },
    "HE": {
      elementsSymbol: ["He"],
      numberOfAtoms: [1]
    },
    "CH4": {
      elementsSymbol: ["H", "C"],
      numberOfAtoms: [4, 1]
    },
    "C3H8": {
      elementsSymbol: ["H", "C"],
      numberOfAtoms: [8, 3]
    },
    "C3H6": {
      elementsSymbol: ["H", "C"],
      numberOfAtoms: [6, 3]
    },
    "C2H4": {
      elementsSymbol: ["H", "C"],
      numberOfAtoms: [4, 2]
    },
    "C2H2": {
      elementsSymbol: ["H", "C"],
      numberOfAtoms: [2, 2]
    },
    "O2": {
      elementsSymbol: ["O"],
      numberOfAtoms: [2]
    },
    "N2": {
      elementsSymbol: ["N"],
      numberOfAtoms: [2]
    },
    "CO": {
      elementsSymbol: ["C", "O"],
      numberOfAtoms: [1, 1]
    },
    "CO2": {
      elementsSymbol: ["C", "O"],
      numberOfAtoms: [1, 2]
    },
    "H2O": {
      elementsSymbol: ["H", "O"],
      numberOfAtoms: [2, 1]
    },
    "H2O2": {
      elementsSymbol: ["H", "O"],
      numberOfAtoms: [2, 2]
    },
    "NO2": {
      elementsSymbol: ["O", "N"],
      numberOfAtoms: [2, 1]
    },
    "NO": {
      elementsSymbol: ["O", "N"],
      numberOfAtoms: [1, 1]
    },
    "N2O": {
      elementsSymbol: ["O", "N"],
      numberOfAtoms: [1, 2]
    },
    "NH3": {
      elementsSymbol: ["H", "N"],
      numberOfAtoms: [3, 1]
    },
    "CH2O": {
      elementsSymbol: ["H", "C", "O"],
      numberOfAtoms: [2, 1, 1]
    },
    "CH3OH": {
      elementsSymbol: ["H", "C", "O"],
      numberOfAtoms: [4, 1, 1]
    },
    "C6H6": {
      elementsSymbol: ["H", "C"],
      numberOfAtoms: [6, 6]
    },
    "C7H8": {
      elementsSymbol: ["H", "C"],
      numberOfAtoms: [8, 7]
    },
    "N2H4": {
      elementsSymbol: ["H", "N"],
      numberOfAtoms: [4, 2]
    },
    "CH3COOH": {
      elementsSymbol: ["H", "C", "O"],
      numberOfAtoms: [4, 2, 2]
    },
    "C2H5OH": {
      elementsSymbol: ["H", "C", "O"],
      numberOfAtoms: [6, 2, 1]
    },
    "CH3COCH3": {
      elementsSymbol: ["H", "C", "O"],
      numberOfAtoms: [6, 3, 1]
    },
    "MEK": {
      elementsSymbol: ["H", "C", "O"],
      numberOfAtoms: [8, 4, 1]
    },
    "NC4H8": {
      elementsSymbol: ["H", "C"],
      numberOfAtoms: [8, 4]
    },
    "IC4H8": {
      elementsSymbol: ["H", "C"],
      numberOfAtoms: [8, 4]
    },
    "IC4H10": {
      elementsSymbol: ["H", "C"],
      numberOfAtoms: [10, 4]
    },
    "NC4H10": {
      elementsSymbol: ["H", "C"],
      numberOfAtoms: [10, 4]
    },
    "N1C4H9OH": {
      elementsSymbol: ["H", "C", "O"],
      numberOfAtoms: [10, 4, 1]
    },
    "N2C4H9OH": {
      elementsSymbol: ["H", "C", "O"],
      numberOfAtoms: [10, 4, 1]
    },
    "TC4H9OH": {
      elementsSymbol: ["H", "C", "O"],
      numberOfAtoms: [10, 4, 1]
    },
    "IC4H9OH": {
      elementsSymbol: ["H", "C", "O"],
      numberOfAtoms: [10, 4, 1]
    },
    "CYC5H8": {
      elementsSymbol: ["H", "C"],
      numberOfAtoms: [8, 5]
    },
    "C5H8": {
      elementsSymbol: ["H", "C"],
      numberOfAtoms: [8, 5]
    },
    "C6H5OH": {
      elementsSymbol: ["H", "C", "O"],
      numberOfAtoms: [6, 6, 1]
    },
    "C6H5CHO": {
      elementsSymbol: ["H", "C", "O"],
      numberOfAtoms: [6, 7, 1]
    },
    "NC7H14": {
      elementsSymbol: ["H", "C"],
      numberOfAtoms: [14, 7]
    },
    "NC7H16": {
      elementsSymbol: ["H", "C"],
      numberOfAtoms: [16, 7]
    },
    "XYLENE": {
      elementsSymbol: ["H", "C"],
      numberOfAtoms: [10, 8]
    },
    "C6H5C2H3": {
      elementsSymbol: ["H", "C"],
      numberOfAtoms: [8, 8]
    },
    "IC8H18": {
      elementsSymbol: ["H", "C"],
      numberOfAtoms: [18, 8]
    },
    "NC10H22": {
      elementsSymbol: ["H", "C"],
      numberOfAtoms: [22, 10]
    },
    "BIPHENYL": {
      elementsSymbol: ["H", "C"],
      numberOfAtoms: [10, 12]
    },
    "H2": {
      elementsSymbol: ["H"],
      numberOfAtoms: [2]
    },
    "C2H6": {
      elementsSymbol: ["H", "C"],
      numberOfAtoms: [6, 2]
    }
  }

  let molecule = jasali.Molecule();

  return molecule.getAvailableSpecies();
}

function addSpeciesListToSingleInput(input_counter, specieNames) {
  /**
   * Add the list of the species in a specific drop down menù of the input line
   */
  let select_obj = document.getElementById(name_id_prefix.concat(input_counter));
  for (let j = 0; j < specieNames.length; j++) {
    let opt = document.createElement('option');
    opt.value = specieNames[j];
    opt.text = specieNames[j];
    select_obj.add(opt);
  }
}

function addSpeciesList() {
  /**
   * Add the list of the species in all the drop down menù of the input line
   */
  let specieNames = getSpeciesList();
  let NSinput = getNumberOfInput();
  for (let i = 0; i < NSinput; i++) {
    addSpeciesListToSingleInput(i + 1, specieNames);
  }
}

function addInputLine() {
  /**
   * Add input line to insert specie and mole fraction
   */
  let actualNSinput = getNumberOfInput();
  let newLineHTML = getInputLineHTML(actualNSinput + 1);
  let specieNames = getSpeciesList();
  document.getElementById(inputContainer_id).insertAdjacentHTML("beforeEnd", newLineHTML);
  addSpeciesListToSingleInput(actualNSinput + 1, specieNames);
}


function readComposition() {
  /**
   * Read the input composition and return a dictionary: {Specie Name: Mole Fraction}
   */
  const composition = {};
  let NSinput = getNumberOfInput();
  for (let i = 0; i < NSinput; i++) {
    let select_obj = document.getElementById(name_id_prefix.concat(i + 1));
    let value_obj = document.getElementById(value_id_prefix.concat(i + 1));

    if (!value_obj.value.includes(select_str)) {
      let value = parseFloat(value_obj.value).toFixed(6);
      let name = select_obj.options[select_obj.selectedIndex].value.toString();
      if (!isNaN(value)) {
        composition[name] = value;
      }
    }
  }
  return composition;
}

function readTemperature() {
  /**
   * Read the input temperature
   */
  return parseFloat(document.getElementById(T_id).value);
}

function readPressure() {
  /**
   * Read the input pressure
   */
  return parseFloat(document.getElementById(P_id).value);
}

function estimateMixtureProperties() {
  /**
   * Estimate the mixture properties using JASALI and return a dictionary
   */

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
    let composition = readComposition();

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

      // Calculate chemical equilibrium
      if (mixture.getSpeciesName().length > 1) {
        let compositionEQ = {}
        mixture.getSpeciesName().forEach((key, i) => compositionEQ[key] = mixture.calculateChemicalEquilibriumTP()[i]);

        let mixtureEQ = jasali.GasMixture({
          mixtureComposition: compositionEQ,
          gasState: state,
          compositionType: "mole"
        })

        outputEq = {
          "name": mixtureEQ.getSpeciesName(),
          "mole": mixtureEQ.getMoleFraction(),
          "mass": mixtureEQ.getMassFraction()
        }

        outputDiff = { "value": mixture.getMixtureDiffusion(), "ud": "m<sup>2</sup>/s" }
      }
      else {
        outputEq = {
          "name": mixture.getSpeciesName(),
          "mole": mixture.getMoleFraction(),
          "mass": mixture.getMassFraction()
        }

        outputDiff = { "value": mixture.getSpeciesDiffusion(), "ud": "m<sup>2</sup>/s" }
      }

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
        "diffusivity": outputDiff,
        "equilibrium": outputEq
      }
      return output;
    }
  }
}

function showOperatingConditions(results, doc) {
  /**
   * Show the operating conditions in the results page
   */
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
  /**
   * Show the transport properties in the results page
   */
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
    nameCell.innerHTML = "<b>Diffusivity</b>";
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
  /**
   * Show the thermodynamic properties in the results page
   */
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

function showEquilibrium(results, doc) {
  /**
   * Show the equilibrium in the results page
   */
  let name = results["equilibrium"]["name"];
  let mole = results["equilibrium"]["mole"];
  let mass = results["equilibrium"]["mass"];
  let inputTable = doc.getElementById("output-table")

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
  /**
   * Run the webapp at button press
   */
  // Estimate mixture properties
  let results = estimateMixtureProperties();

  // Save mixture properties from LocalStorage
  localStorage.setItem(webAppResults, JSON.stringify(results));

  if (Object.keys(results).length > 0) {
    // Genere new window object
    let destinationWindow = window.open(transportPageUrl, "_blank");

    //Opening a window is asynchronous
    destinationWindow.onload = function () {
      showOperatingConditions(results, destinationWindow.document);
      showTransportProperties(results, destinationWindow.document);
    }
  }
}

function showResults(destinationPageUrl) {
  /**
   * Show the results page
   */
  // Get mixture properties from LocalStorage
  let results = JSON.parse(localStorage.getItem(webAppResults));

  if (Object.keys(results).length > 0) {
    showOperatingConditions(results, document);
    if (destinationPageUrl.includes(transportPageUrl)) {
      showTransportProperties(results, document);
    }
    else if (destinationPageUrl.includes(thermoPageUrl)) {
      showThermoProperties(results, document);
    }
    else if (destinationPageUrl.includes(eqTPPageUrl)) {
      showEquilibrium(results, document);
    }
  }
}

window.onload = function updatePage() {
  /**
   * Main function that run on page load
   */
  let actualPageUrl = window.location.href.toString();
  if (actualPageUrl.includes(webAppPageUrl)) {
    addSpeciesList();
  }
  else if (actualPageUrl.includes(resultsPageUrl)) {
    showResults(actualPageUrl);
  }
}