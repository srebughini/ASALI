#bin/bash

function compile()
{
	echo "Compiling..."
	rm -rf ../C/elapsed-time.sh
	rm -rf ../Cpp/elapsed-time.sh
	rm -rf ../Fortran/elapsed-time.sh
	
	echo "...C version..."
	cd ../C
	gcc elapsed-time.c AsaliVector.c AsaliMatrix.c Asali.c -lm -o elapsed-time.sh
	cd ../elapsedTimeComparison

	echo "...Cpp version..."
	cd ../Cpp
	g++ -std=c++11 -Wall -Wextra -Wunused-but-set-variable Asali.cpp elapsed-time.cpp -o elapsed-time.sh
	cd ../elapsedTimeComparison

	echo "...Fortran version..."
	cd ../Fortran
	gfortran elapsed-time.f90 -o elapsed-time.sh
	cd ../elapsedTimeComparison

	echo "...Java version..."
	cd ../Java
	javac -Xlint ThermoDatabase.java TransportDatabase.java OmegaDatabase.java Asali.java ElapsedTime.java
	cd ../elapsedTimeComparison

	echo "...Rust version..."
	cd ../Rust
	cargo build --release
	cd ../elapsedTimeComparison 
}

function run()
{
	local N=$1
	./../C/elapsed-time.sh $N > C.txt
	
	./../Cpp/elapsed-time.sh $N > Cpp.txt
	
	./../Fortran/elapsed-time.sh $N > Fortran.txt
	
	cd ../Java
	java ElapsedTime $N > ../elapsedTimeComparison/Java.txt
	cd ../elapsedTimeComparison
	
	cd ../Rust
	cargo run --bin elapsedtime $N > ../elapsedTimeComparison/Rust.txt
	cd ../elapsedTimeComparison
}

function printOnScreen()
{
	local N=$1
	local model=$(echo $2 | sed 's/_/ /g')
	local os=$(echo $3 | sed 's/_/ /g')
	echo "ASALI-API performance test"
	echo " "
	echo "Number of runs:   $N"
	echo "Processor model:  $model"
	echo "Operating system: $os"
	echo " "
	sed 's/,/./g ; s/E/e/g' < Cpp.txt
	sed 's/,/./g ; s/E/e/g' < C.txt
	sed 's/,/./g ; s/E/e/g' < Fortran.txt
	sed 's/,/./g ; s/E/e/g' < Java.txt
	sed 's/,/./g ; s/E/e/g' < Rust.txt
}


function parseSingleFileOutput()
{
	local filename=$1
	local language=$(sed 's/version//g ; s/ //g ; s/,/./g ; s/E/e/g' < $filename | sed -n 1p)
	local initime=$(sed 's/Initialization (s)://g ; s/ //g ; s/,/./g ; s/E/e/g'  < $filename | sed -n 2p)
	local estitime=$(sed 's/Calculation (s)://g ; s/ //g ; s/,/./g ; s/E/e/g' < $filename | sed -n 3p)

	echo "|$language|$initime|$estitime| "
}

function markdownFileHead()
{
	local N=$1
	local model=$(echo $2 | sed 's/_/ /g')
	local os=$(echo $3 | sed 's/_/ /g')
	echo "# **ASALI: Modeling and beyond**  "
	echo "## **APIs elapsed time comparison**  "
	echo "These results are obtained with a *$model* with *$os*.  "
	echo "If you download ASALI, you can run the same test on your own computer using the following commands:  "
	echo '```bash  '
	echo "cd API/elapsedTimeComparison/  "
	echo "./run.sh -n $N -f test.md --compile  "
	echo '```  '
	echo "## Assumptions and operating conditions  "
	echo "The gas mixture operating conditions are reported in the following table:  " 
	echo "|Property|Value|Unit dimension|  "
	echo "|--------|-----|--------------|  "
	echo "|Temperature|393.15|K|  "
	echo "|Pressure|4|bar|  "
	echo "|H<sub>2</sub>|0.1|Molar fraction|  "
	echo "|O<sub>2</sub>|0.2|Molar fraction|  "
	echo "|N<sub>2</sub>|0.7|Molar fraction|  "
	echo " "
	echo "The performance comparison has the following assumptions:  "
	echo "* Number of runs: **$N**  "
	echo "* Elapsed time to initialize **output variables** is **not considered**  "
	echo "## Results  "
	echo "The table reports the compatutational time required to **estimate all thermodynamic and transport properties** and the computational time required to **initialize ASALI**.  "
	echo "|Language|Initialization (s)|Calculation (s)|  "
	echo "|--------|----------------|-------------------|  "

}

function printOnFile()
{
	local N=$1
	local model=$2
	local os=$3
	markdownFileHead $N $model $os
	parseSingleFileOutput Cpp.txt
	parseSingleFileOutput C.txt
	parseSingleFileOutput Fortran.txt
	parseSingleFileOutput Java.txt
	parseSingleFileOutput Rust.txt
}

function Help()
{
   echo "Syntax: ./run.sh -n 100 -f test.md --compile "
   echo "   options:"
   echo "          --compile                Compile source code."
   echo "          -f                       Output file (README.md)."
   echo "          -n                       Number of runs (e.g. 100)."
   exit
}

screen_output="true"
processor_model=$(lscpu | grep 'Model name' | sed 's/Model name://g' | xargs | sed 's/ /_/g')
os=$(hostnamectl | grep 'Operating System' | sed 's/Operating System://g' | xargs | sed 's/ /_/g')

POSITIONAL=()
while [[ $# -gt 0 ]]
do
    key="$1"

    case $key in
        -h|--help)
        Help
        ;;
        --compile)
        compile_source="true"
        shift # past argument
        ;;
        -n|--number-of-runs)
        number_of_runs="$2"
        shift # past argument
        shift # past value
        ;;
        -f|--file)
        file_output="$2"
        shift # past argument
        ;;
        *)    # unknown option
        POSITIONAL+=("$1") # save it in an array for later
        shift # past argument
        ;;
    esac
done
set -- "${POSITIONAL[@]}" # restore positional parameters

if [ -z "$number_of_runs" ]; then
	Help	
fi

if [ -z "$file_output" ]; then
	Help
fi

if [ -z "$compile_source" ]; then
	FILE=asali-C.sh
	if [ ! -f "$FILE" ]; then
		Help	
	fi
	compile_source="false"
fi

if [ "$compile_source" == "true" ]; then
	compile
fi

run $number_of_runs

if [ "$screen_output" == "true" ]; then
	printOnScreen $number_of_runs $processor_model $os
fi

printOnFile $number_of_runs $processor_model $os > $file_output

rm -rf Cpp.txt
rm -rf C.txt
rm -rf Fortran.txt
rm -rf Java.txt
rm -rf Rust.txt






