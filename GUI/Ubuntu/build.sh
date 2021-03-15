#bin/bash

folder_api=$(cd '../../API/Cpp'; pwd)

function echoRed {
    echo -e "\e[31m$1\e[0m"
}

function echoGreen {
    echo -e "\e[32m$1\e[0m"
}

function echoYellow {
    echo -e "\e[93m$1\e[0m"
}

function Help()
{
    echo " "
    echo "Syntax: ./build.sh --cantera-path /usr/local/ --os ubuntu"
    echo "   options:"
    echo "          -h|--help                Help"
    echo "          -c|--clean               Clean installation folder"
    echo "          --cantera-path           Cantera path     (Default: /usr/local/)"
    echo "          --os                     Operating system (Default: ubuntu)"
    echo "          --output-folder          Target folder    (Default: .)"
    echo "          --symbolic-link          Create symbolic link in /usr/local/bin/"
    echo "          --without-cantera        Install ASALI without cantera"
    echo "          --no-interaction         Ignore human interaction"
    echo " "
    echo "   available options:"
    echo "          --os                     ubuntu/windows"
    echo " "
    exit
}

function BuildingOptions()
{
    echo " "
        echoGreen "Building options:"
        echoGreen "- operating system:  $1"
        echoGreen "- python version:    $2"
    if [ "$3" == "true" ]; then
        echoGreen "- cantera:           yes"
        echoGreen "- cantera path:      $4"
    else
        echoGreen "- cantera:           no"
    fi
    
    if [ "$5" == "actual" ]; then
        echoGreen "- output folder:     $PWD"
    else
        echoGreen "- output folder:     $5"
    fi
    
    if [ "$6" == "true" ]; then
        echoGreen "- symbolic link:     yes"
    else
        echoGreen "- symbolic link:     no"
    fi

    if [ "$7" == "true" ]; then
        echoGreen "- human interaction: yes"
    else
        echoGreen "- human interaction: no"
    fi

    echo " "
}

function Continue()
{
    if [ "$human_interaction" == "true" ]; then
        local question=$(echoYellow "Do you want to continue? [y/N] ")
        
        read -r -p "$question"  response
        case "$response" in
            [yY][eE][sS]|[yY]) 
                echo "true"
                ;;
            *)
                echo "false"
                ;;
        esac
    else
        echo "true"
    fi
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

function CheckOperatingSystem()
{
    if [ "$1" == "ubuntu" ]; then
        asali_on_windows=0
    elif [ "$1" == "windows" ]; then
        asali_on_windows=1
    else
        Help
    fi
}

function CheckCantera()
{
    if [ "$1" == "true" ]; then
        if [ ! -d "$2/include/cantera" ]; then
        echo " "
        echoRed "Cantera is missing in: $2"
        Help
        else
        asali_using_cantera=1
        fi
    else
        mkdir -p ext/shared/
        cp -u $3/shared/* ext/shared/.
        cp -u $3/Asali.cpp ext/.
        cp -u $3/Asali.hpp ext/.
        asali_using_cantera=0
    fi
}

function CheckPython()
{
    python_version=$(python3 --version | sed 's/Python //g')
    
    if [[ $python_version == *"not found"* ]]; then
        echoRed 'python3 not found'
        echo " "
        exit
    fi

    if [[ $python_version == *"3.8"* ]]; then
        python_config_command='--embed'
    else
        python_config_command=' '
    fi
}

function CheckSymbolicLink()
{
    if [[ "$1" == "false" ]]; then
        compiling_folder=""
    else
        make clean -f Makefile.cantera PYTHON_CONFIG=$2
        make clean -f Makefile.asali PYTHON_CONFIG=$2
        make clean -f Makefile.libs
    fi
}

function CreateSymbolicLink()
{
    if [[ $1 == "true" ]]; then
        echo " "
        echoYellow "Please, enter sudo password to create the symbolic link in /usr/local/bin "
        sudo ln -s $2/Asali /usr/local/bin/Asali
    fi
}

function Compile()
{
    if [ "$1" == "true" ]; then
        make all -f Makefile.cantera CANTERA_PREFIX=$2 ASALI_USING_CANTERA=$3 ASALI_ON_WINDOW=$4 PYTHON_CONFIG=$5 COMPILING_PATH=$6
    else
        echoRed "This version is not available, yet :)"
        make all -f Makefile.libs
        make all -f Makefile.asali ASALI_USING_CANTERA=$3 ASALI_ON_WINDOW=$4 PYTHON_CONFIG=$5 COMPILING_PATH=$6
    fi
}

function MakeOutputFolder()
{
    mkdir -p $1
    echo $(cd $1; pwd)
}

function Copy()
{
    if [ "$1" != "$PWD" ]; then
        mkdir -p $1
        cp -f Asali $1/.
        cp -rf images $1/.
        cp -rf database $1/.
        cd $1
    fi
}

function Clean()
{
    python_version=$(python3 --version | sed 's/Python //g')
    python_config_command=$(CheckPython $python_version)

    make clean -f Makefile.cantera PYTHON_CONFIG=$python_config_command
    make clean -f Makefile.asali PYTHON_CONFIG=$python_config_command
    make clean -f Makefile.libs
    exit
}

POSITIONAL=()
cantera_path="/usr/local/"
operating_system="ubuntu"
with_cantera="true"
output_folder=$PWD
symbolic_link="false"
compiling_folder=$output_folder
human_interaction="true"
while [[ $# -gt 0 ]]
do
    key="$1"
    case $key in
        -h|--help)
        Help
        ;;
        -c|--clean)
        CheckCommand python3
        CheckCommand python3-config
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
        --output-folder)
        output_folder=$(MakeOutputFolder "$2")
        shift # past argument
        shift # past value
        ;;
        --without-cantera)
        with_cantera="false"
        shift # past argument
        ;;
        --symbolic-link)
        symbolic_link="true"
        shift # past argument
        ;;
        --no-interaction)
        human_interaction="false"
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
CheckCommand python3-config
CheckCommand make
CheckOperatingSystem "$operating_system"
CheckCantera "$with_cantera" "$cantera_path" "$folder_api"
CheckPython
BuildingOptions "$operating_system" "$python_version" "$with_cantera" "$cantera_path" "$output_folder" "$symbolic_link" "$human_interaction"
CheckSymbolicLink "$symbolic_link" "$python_config_command"

compile=$(Continue)

if [ "$compile" == "true" ]; then
   Compile "$with_cantera" "$cantera_path" "$asali_using_cantera" "$asali_on_windows" "$python_config_command" "$compiling_folder"
   Copy "$output_folder"
   CreateSymbolicLink "$symbolic_link" "$output_folder"
else
   echoRed "Stopped"
fi







