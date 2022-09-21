function estimateProperties() {
    //Generate state objec
    let state = jasali.GasState({
        temperature: parseFloat(document.getElementById("T").innerHTML),
        pressure: parseFloat(document.getElementById("P").innerHTML)
    })
        
    //Generate mixture object
    let mixture = jasali.GasMixture({
        mixtureComposition: {
        "O2": 0.21,
        "N2": 0.78,
        "AR": 0.01
        },
        gasState: state,
        compositionType: "mole"
    })
}

function calculateEquilibrium() {
    newWindow = window.open("", null, "height=200,width=400,status=yes,toolbar=no,menubar=no,location=center");  
  
    newWindow.document.write("<h1>Calculate Equilibrium: Under construction</h1>");
}

function runWebApp()
{
    let resultsWindow = window.open("https://srebughini.github.io/ASALI/pages/results/", "_blank");

    //Opening a window is asynchronous
    resultsWindow.onload = function()
    {

    }
}