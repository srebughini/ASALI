#bin/bash

folder_api=$(cd '../../API/Cpp'; pwd)

function Help()
{
    echo " "
    echo "Syntax: ./build.sh --cantera-path /usr/local/ --os ubuntu"
    echo "   options:"
    echo "          -h|--help                Help"
    echo "          -c|--clean               Clean installation folder"
    echo "          --cantera-path           Cantera path     (Default: /usr/local/)"
    echo "          --os                     Operating system (Default: ubuntu)"
    echo "          --without-cantera        Install ASALI without cantera"
    echo " "
    echo "   available options:"
    echo "          --os                     ubuntu/windows"
    echo " "
    exit
}

function Clean()
{
    python_config_command=$(PythonVersion)

    make clean -f Makefile.cantera PYTHON_CONFIG=$python_config_command
    make clean -f Makefile.asali PYTHON_CONFIG=$python_config_command
    exit
}

function BuildingOptions()
{
    echo " "
    echoGreen "Building options:"
    echoGreen "- operating system: $1"
    echoGreen "- python version:   $2"
    if [ "$3" == "true" ]; then
        echoGreen "- cantera:          yes"
        echoGreen "- cantera path:     $4"
    else
        echoGreen "- cantera:          no"
    fi
    echo " "
}

function Continue()
{
    question=$(echoYellow "Do you want to continue? [y/N] ")
    
    read -r -p "$question"  response
    case "$response" in
        [yY][eE][sS]|[yY]) 
            echo "true"
            ;;
        *)
            echo "false"
            ;;
    esac
}

function CheckCommand()
{
    if ! command -v $1 &> /dev/null
    then
        echo " "
        echoRed "$1 could not be found"
        echo " "
        Help
        exit
    fi
}


function PythonVersion()
{
    python_version=$(python3 --version | sed 's/Python //g')

    if [[ $python_version == *"not found"* ]]; then
        echoRed 'python3 not found'
        
    fi

    if [[ $python_version == *"3.8"* ]]; then
        echo 'python3-config --embed'
    else
        echo 'python3-config'
    fi
}

function echoRed {
    echo -e "\e[31m$1\e[0m"
}

function echoGreen {
    echo -e "\e[32m$1\e[0m"
}

function echoYellow {
    echo -e "\e[93m$1\e[0m"
}

POSITIONAL=()
cantera_path="/usr/local/"
operating_system="ubuntu"
with_cantera="true"
while [[ $# -gt 0 ]]
do
    key="$1"
    case $key in
        -h|--help)
        Help
        ;;
        -c|--clean)
        CheckCommand python3
        CheckCommand python-config
        CheckCommand make
        Clean
        ;;
        --cantera-path)
        cantera_path="$2"
        shift # past argument
        shift # past value
        ;;
        --os)
        operating_system="$2"
        shift # past argument
        shift # past value
        ;;
        --without-cantera)
        with_cantera="false"
        shift # past argument
        ;;
        *)    # unknown option
        POSITIONAL+=("$1") # save it in an array for later
        shift # past argument
        ;;
    esac
done
set -- "${POSITIONAL[@]}" # restore positional parameters

CheckCommand python3
CheckCommand python-config
CheckCommand make

if [ "$operating_system" == "ubuntu" ]; then
    asali_on_window=0
elif [ "$operating_system" == "windows" ]; then
    asali_on_window=1
else
    Help
fi

if [ "$with_cantera" == "true" ]; then
    if [ ! -d "$cantera_path/include/cantera" ]; then
        echo " "
        echoRed "Cantera is missing in: $cantera_path"
        Help
    else
    asali_using_cantera=1
    fi
else
    cp -u $folder_api/shared/* include/shared/.
    cp -u $folder_api/Asali.cpp src/.
    cp -u $folder_api/Asali.hpp include/.
    asali_using_cantera=0
fi

python_config_command=$(PythonVersion)

BuildingOptions $operating_system $python_version $with_cantera $cantera_path

compile=$(Continue)

if [ "$compile" == "true" ]; then
    if [ "$with_cantera" == "true" ]; then
        make all -f Makefile.cantera CANTERA_PREFIX=$cantera_path ASALI_USING_CANTERA=$asali_using_cantera ASALI_ON_WINDOW=$asali_on_window PYTHON_CONFIG=$python_config_command
    else
        make all -f Makefile.asali ASALI_USING_CANTERA=$asali_using_cantera ASALI_ON_WINDOW=$asali_on_window PYTHON_CONFIG=$python_config_command
    fi
fi

