var NSinput = 10;
var mainDoc = window.document

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
      "properties": [
        {"name": "Molecular weight", "value": mixture.getMolecularWeight(), "ud": "kg/kmol"},
        {"name": "Density", "value": mixture.getDensity(), "ud": "kg/m<sup>3</sup>"},
        {"name": "Viscosity", "value": mixture.getViscosity(), "ud": "Pas"},
        {"name": "Diffusivity", "value": diff, "ud": "m<sup>2</sup>/s"},
        {"name": "Thermal conductivity", "value": mixture.getThermalConductivity(), "ud": "W/m/K"},
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
/*
function gasMixtureProperties() {
  let properties = estimateMixtureProperties();
  if (properties.length > 0)
  {
    let propertiesWindow = window.open("output.html", "_blank");

    //Opening a window is asynchronous
    propertiesWindow.onload = function()
    {
      var propertiesDoc = propertiesWindow.document
      let properties_id = "p";
      let value_id = "v";
      let unit_dimension_id = "ud";

      for (let i = 0; i < properties.length; i++) {
        
        if (properties[i]["name"] == "Diffusivity")
        {
          propertiesDoc.getElementById(properties_id.concat(i)).innerHTML = properties[i]["name"]
          let diff = ""
          console.log(properties[i]["value"])
          for (const [key, value] of Object.entries(properties[i]["value"])) {
            diff = diff.concat(key)
            diff = diff.concat(": ")
            diff = diff.concat(value.toExponential(3))
            diff = diff.concat("<br>")

          }
          propertiesDoc.getElementById(value_id.concat(i)).innerHTML = diff
          propertiesDoc.getElementById(unit_dimension_id.concat(i)).innerHTML = properties[i]["ud"]
        }
        else
        {
          propertiesDoc.getElementById(properties_id.concat(i)).innerHTML = properties[i]["name"]
          propertiesDoc.getElementById(value_id.concat(i)).innerHTML = properties[i]["value"].toExponential(3)
          propertiesDoc.getElementById(unit_dimension_id.concat(i)).innerHTML = properties[i]["ud"]
        }
      }
    }
  }
}*/


function calculateEquilibrium() {
    newWindow = window.open("", null, "height=200,width=400,status=yes,toolbar=no,menubar=no,location=center");  
  
    newWindow.document.write("<h1>Calculate Equilibrium: Under construction</h1>");
}

function runWebApp()
{
    // Estimate mixture properties
    let output = estimateMixtureProperties();

    if (Object.keys(output).length > 0 )
    {
      let properties = output["properties"];
      let name = output["composition"]["name"];
      let mole = output["composition"]["mole"];
      let mass = output["composition"]["mass"];

      // Genere new window object
      let transportWindow = window.open("https://srebughini.github.io/ASALI/results/transport-properties", "_blank");

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
          moleCell.innerHTML = mole[i];
          massCell.innerHTML = mass[i];
        }
          /*
          let resultsDoc = resultsWindow.document
          let properties_id = "p";
          let value_id = "v";
          let unit_dimension_id = "ud";
    
          for (let i = 0; i < properties.length; i++) {
            
            if (properties[i]["name"] == "Diffusivity")
            {
              propertiesDoc.getElementById(properties_id.concat(i)).innerHTML = properties[i]["name"]
              let diff = ""
              console.log(properties[i]["value"])
              for (const [key, value] of Object.entries(properties[i]["value"])) {
                diff = diff.concat(key)
                diff = diff.concat(": ")
                diff = diff.concat(value.toExponential(3))
                diff = diff.concat("<br>")
    
              }
              propertiesDoc.getElementById(value_id.concat(i)).innerHTML = diff
              propertiesDoc.getElementById(unit_dimension_id.concat(i)).innerHTML = properties[i]["ud"]
            }
            else
            {
              propertiesDoc.getElementById(properties_id.concat(i)).innerHTML = properties[i]["name"]
              propertiesDoc.getElementById(value_id.concat(i)).innerHTML = properties[i]["value"].toExponential(3)
              propertiesDoc.getElementById(unit_dimension_id.concat(i)).innerHTML = properties[i]["ud"]
            }
          }*/
      }
    }
}