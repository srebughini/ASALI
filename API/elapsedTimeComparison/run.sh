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
	echo "ASALI-API performance test with $N runs"
	cat Cpp.txt | sed 's/,/./g' | sed 's/E/e/g'
	cat C.txt | sed 's/,/./g' | sed 's/E/e/g'
	cat Fortran.txt | sed 's/,/./g' | sed 's/E/e/g'
}


function parseSingleFileOutput()
{
	local filename=$1
	local language=$(cat $filename | sed -n 1p | sed 's/version//g' | sed 's/ //g' | sed 's/,/./g' | sed 's/E/e/g')
	local totaltime=$(cat $filename | sed -n 2p| sed 's/Total (s)://g' | sed 's/ //g'| sed 's/,/./g' | sed 's/E/e/g')
	local singleruntime=$(cat $filename | sed -n 3p | sed 's/Single run (s)://g' | sed 's/ //g'| sed 's/,/./g' | sed 's/E/e/g')
	
	echo "|$language|$totaltime|$singleruntime| "
}

function markdownFileHead()
{
	local N=$1
	echo "# **ASALI: Modeling and beyond**  "
	echo "## *APIs performance comparison*  "
	echo "### 1. Assumptions  "
	echo "This performance comparison has the following assumptions:  "
	echo "* Number of runs: $N  "
	echo "* Elapsed time to initialize **output variables** is **not considered**  "
	echo "* Elapsed time to initialize **operating condition** is **not considered**  "
	echo "### 2. Results  "
	echo "|Language|Total time (s)|Single run time (s)|"
	echo "|--------|----------------|-------------------|"
}


function printOnFile()
{
	local N=$1
	markdownFileHead $N
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
	printOnScreen $number_of_runs
fi

if [ "$file_output" == "true" ]; then
	printOnFile $number_of_runs > README.md
fi

rm -rf *.txt






