param(
    [int]$n,
    [string]$file,
    [switch]$compile
)

# =========================
# HELP
# =========================
function Help {
    Write-Host "Syntax: .\run.ps1 -n 100 -f test.md --compile"
    Write-Host "   options:"
    Write-Host "          --compile                Compile source code."
    Write-Host "          -f                       Output file (README.md)."
    Write-Host "          -n                       Number of runs (e.g. 100)."
    exit
}

# =========================
# COMPILATION
# =========================
function Compile {

    Write-Host "Compiling/Preparing..."

    Remove-Item -Force -ErrorAction SilentlyContinue ..\C\elapsed-time.exe
    Remove-Item -Force -ErrorAction SilentlyContinue ..\Cpp\elapsed-time.exe
    Remove-Item -Force -ErrorAction SilentlyContinue ..\Fortran\elapsed-time.exe

    # C
    Write-Host "...C version..."
    Set-Location ..\C
    cl database-generator.c /std:c11 /TC /Fe:database-generator.exe
    .\database-generator.exe
    cl /std:c11 /TC elapsed-time.c AsaliVector.c AsaliMatrix.c Asali.c /Fe:elapsed-time.exe
    Set-Location ..\elapsedTimeComparison

    # C++
    Write-Host "...Cpp version..."
    Set-Location ..\Cpp
    cl database-generator.cpp  /EHsc /Fe:database-generator.exe
    database-generator.exe
    cl Asali.cpp elapsed-time.cpp /EHsc /Fe:elapsed-time.exe
    Set-Location ..\elapsedTimeComparison

    # Fortran
    Write-Host "...Fortran version..."
    Set-Location ..\Fortran
    gfortran database-generator.f90 -o database-generator.exe
    .\database-generator.exe
    gfortran elapsed-time.f90 -o elapsed-time.exe
    Set-Location ..\elapsedTimeComparison

    # Java
    Write-Host "...Java version..."
    Set-Location ..\Java
    javac -Xlint DatabaseGenerator.java
    java DatabaseGenerator
    javac -Xlint *.java
    Set-Location ..\elapsedTimeComparison

    # Rust
    Write-Host "...Rust version..."
    Set-Location ..\Rust
    cargo build --quiet --release
    cargo run --quiet --bin databasegenerator
    cargo build --quiet --release
    Set-Location ..\elapsedTimeComparison

    # Octave
    Write-Host "...Octave version..."
    Set-Location ..\Octave
    octave --quiet --no-window-system database-generator.m
    Set-Location ..\elapsedTimeComparison

    # Python
    Write-Host "...Python version..."
    Set-Location ..\Python
    python database-generator.py
    Set-Location ..\elapsedTimeComparison

    # Julia
    Write-Host "...Julia version..."
    Set-Location ..\Julia
    julia --startup-file=no --quiet database-generator.jl
    Set-Location ..\elapsedTimeComparison

    Write-Host "...done!"
}

# =========================
# RUN BENCHMARK
# =========================
function Run($N) {

    Write-Host "Running..."

    ..\C\elapsed-time.exe $N > C.txt
    ..\Cpp\elapsed-time.exe $N > Cpp.txt
    ..\Fortran\elapsed-time.exe $N > Fortran.txt

    Set-Location ..\Java
    java ElapsedTime $N > ..\elapsedTimeComparison\Java.txt
    Set-Location ..\elapsedTimeComparison

    Set-Location ..\Rust
    cargo run --quiet --bin elapsedtime $N > ..\elapsedTimeComparison\Rust.txt
    Set-Location ..\elapsedTimeComparison

    Set-Location ..\Octave
    octave --quiet --no-window-system elapsed-time.m $N > ..\elapsedTimeComparison\Octave.txt
    Set-Location ..\elapsedTimeComparison

    Set-Location ..\Python
    python elapsed-time.py --number-of-runs $N > ..\elapsedTimeComparison\Python.txt
    Set-Location ..\elapsedTimeComparison


    Set-Location ..\Julia
    # warm-up (NOT timed)
    julia --startup-file=no --quiet elapsed-time.jl 1 | Out-Null
    julia --startup-file=no --quiet elapsed-time.jl $N > ..\elapsedTimeComparison\Julia.txt

    Set-Location ..\elapsedTimeComparison

    Write-Host "...done!"
}

# =========================
# SCREEN OUTPUT
# =========================
function PrintOnScreen($N) {

    $cpu = (Get-CimInstance Win32_Processor).Name
    $os = (Get-CimInstance Win32_OperatingSystem).Caption

    Write-Host "ASALI-API performance test"
    Write-Host ""
    Write-Host "Number of runs:   $N"
    Write-Host "Processor model:  $cpu"
    Write-Host "Operating system: $os"
    Write-Host ""

    (Get-Content Cpp.txt)      -replace ",","." -replace "E","e"
    (Get-Content C.txt)        -replace ",","." -replace "E","e"
    (Get-Content Fortran.txt)   -replace ",","." -replace "E","e"
    (Get-Content Java.txt)      -replace ",","." -replace "E","e"
    (Get-Content Rust.txt)      -replace ",","." -replace "E","e"
    (Get-Content Octave.txt)    -replace ",","." -replace "E","e"
    (Get-Content Python.txt)    -replace ",","." -replace "E","e"
    (Get-Content Julia.txt)     -replace ",","." -replace "E","e"
}

# =========================
# PARSE OUTPUT
# =========================
function ParseSingle($file) {

    $lines = Get-Content $file

    $lang = ($lines[0] -replace "version","").Trim()
    $init = ($lines[1] -replace "Initialization \(s\):","").Trim()
    $calc = ($lines[2] -replace "Calculation \(s\):","").Trim()

    return "|$lang|$init|$calc|"
}

# =========================
# MARKDOWN HEADER
# =========================
function MarkdownHead($N, $model, $os) {
}

# =========================
# WRITE FILE
# =========================
function PrintOnFile($N, $model, $os) {

MarkdownHead $N $model $os | Out-File $file -Encoding utf8

ParseSingle Cpp.txt     | Out-File $file -Append
ParseSingle C.txt       | Out-File $file -Append
ParseSingle Fortran.txt | Out-File $file -Append
ParseSingle Java.txt    | Out-File $file -Append
ParseSingle Rust.txt    | Out-File $file -Append
ParseSingle Octave.txt  | Out-File $file -Append
ParseSingle Python.txt  | Out-File $file -Append
ParseSingle Julia.txt   | Out-File $file -Append
}

# =========================
# MAIN
# =========================

if (-not $n) { Help }
if (-not $file) { Help }

$compile_source = $compile.IsPresent

if ($compile_source) {
Compile
}

Run $n

PrintOnScreen $n

$model = (Get-CimInstance Win32_Processor).Name
$osname = (Get-CimInstance Win32_OperatingSystem).Caption

PrintOnFile $n $model $osname

Remove-Item Cpp.txt, C.txt, Fortran.txt, Java.txt, Rust.txt, Octave.txt, Python.txt, Julia.txt -ErrorAction SilentlyContinue

