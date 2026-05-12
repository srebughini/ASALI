@echo off
setlocal enabledelayedexpansion

REM =========================
REM MAIN (must be first)
REM =========================

set screen_output=true
set compile_source=false
set number_of_runs=
set file_output=

for /f "tokens=*" %%i in ('wmic cpu get name ^| findstr /r /v "^$"') do set processor_model=%%i
set processor_model=%processor_model: =_%

for /f "tokens=*" %%i in ('ver') do set osname=Windows

goto parse_args


REM =========================
REM HELP
REM =========================
:Help
echo Syntax: run.bat -n 100 -f test.md --compile
echo    options:
echo           --compile                Compile source code.
echo           -f                       Output file (README.md).
echo           -n                       Number of runs (e.g. 100).
goto :eof


REM =========================
REM COMPILATION
REM =========================
:compile
echo Compiling/Preparing...

del /f /q ..\C\elapsed-time.sh 2>nul
del /f /q ..\Cpp\elapsed-time.sh 2>nul
del /f /q ..\Fortran\elapsed-time.sh 2>nul

echo ...C version...
cd ..\C
cl database-generator.c /std:c11 /TC /Fe:database-generator.exe
database-generator.exe
cl /std:c11 /TC elapsed-time.c AsaliVector.c AsaliMatrix.c Asali.c /Fe:elapsed-time.exe
cd ..\elapsedTimeComparison

echo ...Cpp version...
cd ..\Cpp
cl database-generator.cpp /EHsc /Fe:database-generator.exe
database-generator.exe
cl Asali.cpp elapsed-time.cpp /EHsc /Fe:elapsed-time.exe
cd ..\elapsedTimeComparison

echo ...Fortran version...
cd ..\Fortran
ifx database-generator.f90 -o database-generator.exe
database-generator.exe
ifx elapsed-time.f90 -o elapsed-time.exe
cd ..\elapsedTimeComparison

echo ...Java version...
cd ..\Java
javac -Xlint DatabaseGenerator.java
java DatabaseGenerator
javac -Xlint ThermoDatabase.java TransportDatabase.java OmegaDatabase.java Asali.java ElapsedTime.java
cd ..\elapsedTimeComparison

echo ...Rust version...
cd ..\Rust
cargo build --quiet --release
cargo run --quiet --bin databasegenerator
cargo build --quiet --release
cd ..\elapsedTimeComparison

echo ...Octave version...
cd ..\Octave
octave --quiet --no-window-system database-generator.m
cd ..\elapsedTimeComparison

echo ...Python version...
cd ..\Python
python database-generator.py
cd ..\elapsedTimeComparison

echo ...Julia version...
cd ..\Julia
julia --quiet --startup-file=no database-generator.jl
cd ..\elapsedTimeComparison

echo ...done!
goto :eof


REM =========================
REM RUN BENCHMARK
REM =========================
:run
echo Running...
set N=%1

..\C\elapsed-time.exe %N% > C.txt
..\Cpp\elapsed-time.exe %N% > Cpp.txt
..\Fortran\elapsed-time.exe %N% > Fortran.txt

cd ..\Java
java ElapsedTime %N% > ..\elapsedTimeComparison\Java.txt
cd ..\elapsedTimeComparison

cd ..\Rust
cargo run --quiet --bin elapsedtime %N% > ..\elapsedTimeComparison\Rust.txt
cd ..\elapsedTimeComparison

cd ..\Octave
octave --quiet --no-window-system elapsed-time.m %N% > ..\elapsedTimeComparison\Octave.txt
cd ..\elapsedTimeComparison

cd ..\Python
python elapsed-time.py --number-of-runs %N% > ..\elapsedTimeComparison\Python.txt
cd ..\elapsedTimeComparison

cd ..\Julia
julia --startup-file=no --quiet elapsed-time.jl 1 > NUL
julia --startup-file=no --quiet elapsed-time.jl %N% > ..\elapsedTimeComparison\Julia.txt
cd ..\elapsedTimeComparison

echo ...done!
goto :eof


REM =========================
REM SCREEN OUTPUT
REM =========================
:printOnScreen
set N=%1
set model=%2
set osname=%3

echo ASALI-API performance test
echo.
echo Number of runs:   %N%
echo Processor model:  %model%
echo Operating system: %osname%
echo.

call :printFile Cpp.txt
call :printFile C.txt
call :printFile Fortran.txt
call :printFile Java.txt
call :printFile Rust.txt
call :printFile Octave.txt
call :printFile Python.txt
call :printFile Julia.txt
goto :eof


:printFile
for /f "usebackq delims=" %%A in (%1) do (
    set line=%%A
    set line=!line:,=.!
    set line=!line:E=e!
    echo !line!
)
goto :eof


REM =========================
REM PARSE OUTPUT
REM =========================
:parseSingleFileOutput
set "file=%~1"

set "i=0"

for /f "usebackq delims=" %%A in ("%file%") do (
    if !i! == 0 set "language=%%A"
    if !i! == 1 set "initime=%%A"
    if !i! == 2 set "estitime=%%A"
    set /a i+=1
)

set "language=%language:version=%"
set "language=%language:,=.%"
set "language=%language:E=e%"

set "initime=%initime:Initialization (s):=%"
set "initime=%initime:,=.%"
set "initime=%initime:E=e%"

set "estitime=%estitime:Calculation (s):=%"
set "estitime=%estitime:,=.%"
set "estitime=%estitime:E=e%"

echo ^|%language%^|%initime%^|%estitime%^|
goto :eof


REM =========================
REM MARKDOWN HEADER
REM =========================
:markdownFileHead
set N=%1
set model=%2
set osname=%3

echo # **ASALI: Modeling and beyond**
echo ## **APIs elapsed time comparison**
echo These results are obtained with a *%model%* with *%osname%*.
echo If you download ASALI, you can run the same test using:
echo ```bash
echo cd API/elapsedTimeComparison/
echo run.bat -n %N% -f test.md --compile
echo ```
echo ## Assumptions and operating conditions
echo ^|Property^|Value^|Unit dimension^|
echo ^|--------^|-----^|--------------^|
echo ^|Temperature^|393.15^|K^|
echo ^|Pressure^|4^|bar^|
echo ^|H2^|0.1^|Molar fraction^|
echo ^|O2^|0.1^|Molar fraction^|
echo ^|C3H8^|0.1^|Molar fraction^|
echo ^|C2H6^|0.1^|Molar fraction^|
echo ^|CH4^|0.1^|Molar fraction^|
echo ^|CO2^|0.1^|Molar fraction^|
echo ^|HE^|0.1^|Molar fraction^|
echo ^|N2^|0.1^|Molar fraction^|
echo ^|NH3^|0.2^|Molar fraction^|
echo.
echo * Number of runs: %N%
echo * Initialization not considered
echo ## Results
echo ^|Language^|Initialization (s)^|Calculation (s)^|
echo ^|--------^|----------------^|-------------------^|
goto :eof


REM =========================
REM PRINT ON FILE
REM =========================
:printOnFile
call :markdownFileHead %1 %2 %3

call :parseSingleFileOutput Cpp.txt
call :parseSingleFileOutput C.txt
call :parseSingleFileOutput Fortran.txt
call :parseSingleFileOutput Java.txt
call :parseSingleFileOutput Rust.txt
call :parseSingleFileOutput Octave.txt
call :parseSingleFileOutput Python.txt
call :parseSingleFileOutput Julia.txt
goto :eof


REM =========================
REM PARSE ARGS
REM =========================
:parse_args
if "%1"=="" goto after_args
if "%1"=="-h" goto Help
if "%1"=="--help" goto Help

if "%1"=="--compile" (
    set compile_source=true
    shift
    goto parse_args
)

if "%1"=="-n" (
    set number_of_runs=%2
    shift
    shift
    goto parse_args
)

if "%1"=="--number-of-runs" (
    set number_of_runs=%2
    shift
    shift
    goto parse_args
)

if "%1"=="-f" (
    set file_output=%2
    shift
    shift
    goto parse_args
)

if "%1"=="--file" (
    set file_output=%2
    shift
    shift
    goto parse_args
)

shift
goto parse_args

:after_args

if "%number_of_runs%"=="" (
    echo ERROR: missing -n argument.
    echo.
    call :Help
    exit /b 1
)

if "%file_output%"=="" (
    echo ERROR: missing -f argument.
    echo.
    call :Help
    exit /b 1
)

if "%compile_source%"=="true" call :compile

call :run %number_of_runs%

if "%screen_output%"=="true" call :printOnScreen %number_of_runs% "%processor_model%" %osname%

call :printOnFile %number_of_runs% "%processor_model%" %osname% > %file_output%

del /f /q Cpp.txt C.txt Fortran.txt Java.txt Rust.txt Octave.txt Python.txt Julia.txt 2>nul

endlocal
exit /b 0