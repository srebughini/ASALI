#bin/bash

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
    make clean -f Makefile.cantera
    make clean -f Makefile.asali
    exit
}

function BuildingOptions()
{
    echo " "
    echoGreen "Building options:"
    echoGreen "- operating system: $1"
    if [ "$2" == "true" ]; then
        echoGreen "- cantera:          yes"
        echoGreen "- cantera path:     $3"
    else
        echoGreen "- cantera:          no"
    fi
    echo " "
}


function echoRed {
    echo -e "\e[31m$1\e[0m"
}

function echoGreen {
    echo -e "\e[92m$1\e[0m"
}

POSITIONAL=()
cantera_path="/usr/local"
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

if [ "$operating_system" == "ubuntu" ]; then
    asali_on_window=0
elif [ "$operating_system" == "windows" ]; then
    asali_on_window=1
else
    Help
fi

if [ "$with_cantera" == "true" ]; then
    if [ ! -f "$cantera_path/cantera" ]; then
        echo " "
        echoRed "Cantera is missing in: $cantera_path"
        Help
    else
    asali_using_cantera=1
    fi
else
    asali_using_cantera=0
fi

BuildingOptions $operating_system $with_cantera $cantera_path

if [ "$with_cantera" == "true" ]; then
    make all -f Makefile.cantera CANTERA_PREFIX=$cantera_path ASALI_USING_CANTERA=$asali_using_cantera ASALI_ON_WINDOW=$asali_on_window
else
    make all -f Makefile.asali ASALI_USING_CANTERA=$asali_using_cantera ASALI_ON_WINDOW=$asali_on_window
fi
