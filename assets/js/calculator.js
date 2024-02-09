var transportPageUrl = "/ASALI/results/transport-properties/";
var thermoPageUrl = "/ASALI/results/thermodynamic-properties/";
var eqTPPageUrl = "/ASALI/results/equilibrium-@-constant-t-p/";
var vacuumPageUrl = "/ASALI/results/vacuum-properties/"
var webAppPageUrl = "/ASALI/pages/webapp/";
var resultsPageUrl = "/ASALI/results/";

var webAppResults = "webAppResults";

var name_id_prefix = "n";
var value_id_prefix = "x";
var T_id = "T";
var P_id = "P";
var select_str = "Select";
var inputContainer_id = "inputContainer";

function mergeChemicalNameAndFormula(name){
  /**
   * Merge chemical name and formula and prettify it
   */
  let mol = jasali.Molecule(name);
  return mol.getChemicalName().concat(": ", mol.getFormula().replace(/\d+/g, '<sub>$&</sub>').replaceAll('<sub>1</sub>', ''));
}

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
  let molecule = jasali.Molecule();
  let chemicalNames = molecule.getAvailableSpeciesChemicalName();
  let formulas = molecule.getAvailableSpeciesFormula();
  let species = chemicalNames.map((n,i) => n.concat(": ", formulas[i].replace(/\d+/g, '<sub>$&</sub>').replaceAll('<sub>1</sub>', '')));
  return species.sort();
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
    opt.innerHTML = specieNames[j];
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
  let molecule = jasali.Molecule();
  for (let i = 0; i < NSinput; i++) {
    let select_obj = document.getElementById(name_id_prefix.concat(i + 1));
    let value_obj = document.getElementById(value_id_prefix.concat(i + 1));

    if (!value_obj.value.includes(select_str)) {
      let value = parseFloat(value_obj.value).toFixed(8);
      let specie = select_obj.options[select_obj.selectedIndex].value.toString();
      let chemicalName = specie.split(": ");
      let name = molecule.getNameFromChemicalName(chemicalName[0]);
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

      //Calculate mean free path and mean gas velocity
      let names = Object.keys(composition);
      let v = new Array(names.length);
      let l = new Array(names.length);
      for (let i = 0; i < names.length; i++) {
        let specie = jasali.GasSpecie({
          name: names[i],
          gasState: state
        });
        v[i] = specie.getArithmeticMeanGasVelocity();
        l[i] = specie.getMeanFreePath();
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
        "vacuum": [
          { "name": "Mean gas velocity", "value": v , "ud": "m/s"},
          { "name": "Mean free path", "value": l, "ud": "m"}
        ],
        "temperature": T,
        "pressure": P,
        "composition": {
          "name": mixture.getSpeciesName(),
          "mole": mixture.getMoleFraction(),
          "mass": mixture.getMassFraction()
        },
        "diffusivity": outputDiff,
        "equilibrium": outputEq,
        "velocity": { "value": v, "ud": "m/s" },
        "path": { "value": l, "ud": "m" }
      }
      return output;
    }
  }
}

function showOperatingConditions(results, doc, showCompositionBool) {
  /**
   * Show the operating conditions in the results page
   */
  let name = results["composition"]["name"];
  let mole = results["composition"]["mole"];
  let mass = results["composition"]["mass"];
  let inputTable = doc.getElementById("input-table")

  doc.getElementById(T_id).innerHTML = results["temperature"];
  doc.getElementById(P_id).innerHTML = results["pressure"];

  if (showCompositionBool)
  {
    for (let i = 0; i < name.length; i++) {
      let newRow = inputTable.insertRow(-1);
      let nameCell = newRow.insertCell(0);
      let moleCell = newRow.insertCell(1);
      let massCell = newRow.insertCell(2);
      nameCell.innerHTML = mergeChemicalNameAndFormula(name[i]);
      nameCell.id = name_id_prefix.concat(i + 1);
      moleCell.innerHTML = parseFloat(mole[i]).toExponential(3);
      moleCell.id = value_id_prefix.concat(i + 1);
      massCell.innerHTML = parseFloat(mass[i]).toExponential(3);
    }
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
      nameCell.innerHTML = mergeChemicalNameAndFormula(name[i]);
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

function showVacuumProperties(results, doc) {
  /**
   * Show the vacuum properties in the results page
   */

  let outputTable = doc.getElementById("output-table")

  // Mean gas velocity main line
  {
    let newRow = outputTable.insertRow(-1);
    let nameCell = newRow.insertCell(0);
    newRow.insertCell(1);
    newRow.insertCell(2);
    nameCell.innerHTML = "<b>Mean gas velocity</b>";
  }

  {
    let values = results["velocity"]["value"];
    let ud = results["velocity"]["ud"];
    let name = results["composition"]["name"];
    
    for (let i = 0; i < values.length; i++) {
      let newRow = outputTable.insertRow(-1);
      let nameCell = newRow.insertCell(0);
      let valueCell = newRow.insertCell(1);
      let udCell = newRow.insertCell(2);
      nameCell.innerHTML = mergeChemicalNameAndFormula(name[i]);
      valueCell.innerHTML = parseFloat(values[i]).toExponential(3);
      udCell.innerHTML = ud;
    }
  }

  // Mean free path main line
  {
    let newRow = outputTable.insertRow(-1);
    let nameCell = newRow.insertCell(0);
    newRow.insertCell(1);
    newRow.insertCell(2);
    nameCell.innerHTML = "<b>Mean free path</b>";
  }

  {
    let values = results["path"]["value"];
    let ud = results["path"]["ud"];
    let name = results["composition"]["name"];
    
    for (let i = 0; i < values.length; i++) {
      let newRow = outputTable.insertRow(-1);
      let nameCell = newRow.insertCell(0);
      let valueCell = newRow.insertCell(1);
      let udCell = newRow.insertCell(2);
      nameCell.innerHTML = mergeChemicalNameAndFormula(name[i]);
      valueCell.innerHTML = parseFloat(values[i]).toExponential(3);
      udCell.innerHTML = ud;
    }
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
    nameCell.innerHTML = mergeChemicalNameAndFormula(name[i]);
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
      showOperatingConditions(results, destinationWindow.document, true);
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
    if (destinationPageUrl.includes(transportPageUrl)) {
      showOperatingConditions(results, document, true);
      showTransportProperties(results, document);
    }
    else if (destinationPageUrl.includes(thermoPageUrl)) {
      showOperatingConditions(results, document, true);
      showThermoProperties(results, document);
    }
    else if (destinationPageUrl.includes(vacuumPageUrl)) {
      showOperatingConditions(results, document, false);
      showVacuumProperties(results, document);
    }
    else if (destinationPageUrl.includes(eqTPPageUrl)) {
      showOperatingConditions(results, document, true);
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