#bin/bash

function compile()
{
	echo "Compiling..."
	rm -rf asali-C.sh
	rm -rf asali-cpp.sh
	rm -rf asali-fortran.sh
	
	gcc -w C-API.c ../C/AsaliVector.c ../C/AsaliMatrix.c ../C/Asali.c -I../C/ -lm -o asali-C.sh

	g++ -std=c++11 -w ../Cpp/Asali.C Cpp-API.cpp -I../Cpp/ -o asali-cpp.sh

	gfortran -o asali-fortran.sh Fortran-API.f90 -I../Fortran/
}

function run()
{
	local N=$1
	./asali-C.sh $N > C.txt
	./asali-cpp.sh $N > Cpp.txt
	./asali-fortran.sh $N > Fortran.txt
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
}


function parseSingleFileOutput()
{
	local filename=$1
	local language=$(sed -n 1p | sed 's/version//g ; s/ //g ; s/,/./g ; s/E/e/g' < $filename)
	local totaltime=$(sed -n 2p| sed 's/Total (s)://g ; s/ //g ; s/,/./g ; s/E/e/g'  < $filename )
	local singleruntime=$(sed -n 3p | sed 's/Single run (s)://g ; s/ //g ; s/,/./g ; s/E/e/g' < $filename)
	
	echo "|$language|$totaltime|$singleruntime| "
}

function markdownFileHead()
{
	local N=$1
	local model=$(echo $2 | sed 's/_/ /g')
	local os=$(echo $3 | sed 's/_/ /g')
	echo "# **ASALI: Modeling and beyond**  "
	echo "## **APIs elapsed time comparison**  "
	echo "These results are obtained with a *$model* with *$os*.  "
	echo "You can run the same test on your own computer using the following command:  "
	echo '`./run.sh -n '"$N"' --compile`  '
	echo "### 1. Assumptions  "
	echo "The performance comparison has the following assumptions:  "
	echo "* Number of runs: **$N**  "
	echo "* Elapsed time to initialize **output variables** is **not considered**  "
	echo "* Elapsed time to initialize **operating condition** is **not considered**  "
	echo "### 2. Results  "
	echo "|Language|Total time (s)|Single run time (s)|"
	echo "|--------|----------------|-------------------|"
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
}

function Help()
{
   echo "Syntax: ./run.sh -n 100 --compile --file"
   echo "   options:"
   echo "          --compile                Compile source code."
   echo "          --file                   Output on file (README.md)."
   echo "          -n                       Number of runs for performance check (e.g. 100)."
   exit
}

screen_output="true"
file_output="false"
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
        --file)
        file_output="true"
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

if [ "$file_output" == "true" ]; then
	printOnFile $number_of_runs $processor_model $os > README.md
fi

rm -rf Cpp.txt
rm -rf C.txt
rm -rf Fortran.txt






