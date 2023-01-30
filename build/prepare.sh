#!/usr/bin/bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
BASE_DIR=${SCRIPT_DIR}/..
REAL_BASE_DIR=$(realpath ${BASE_DIR})
REAL_PWD=${PWD}
PROJECT_CREATION_MODE=N
PROJECT_NAME=""

while getopts 'p:h' OPT; do
	case "$OPT" in
		p)
			ARG="$OPTARG"
			echo "Processing option 'p' with '${OPTARG}' argument..."
			PROJECT_CREATION_MODE=Y
			PROJECT_NAME=${ARG}
			;;
		?|h)
			echo "[Usage]"
			echo "$(basename $0) [-p project_name]"
			exit 1
			;;
	esac
done
shift "$(($OPTIND -1))"

if [ ${PROJECT_CREATION_MODE} == "Y" ]; then
	echo "Making a directory if one does not exist..."
	PROJECT_PATH=${REAL_BASE_DIR}/${PROJECT_NAME}
	mkdir -p ${REAL_BASE_DIR}/${PROJECT_NAME}
	pushd ${REAL_BASE_DIR}/${PROJECT_NAME}
else
	if [ "$REAL_BASE_DIR" == "$REAL_PWD" ] || [ "$REAL_BASE_DIR/build" == "$REAL_PWD" ] || [ "$REAL_BASE_DIR/template" == "$REAL_PWD" ]; then
    		echo "Project name was not given. Please make a project directory. Then, retry this script."
    		exit 1
	fi
	PROJECT_PATH=${PWD}
fi

echo "Copying a Makefile if one does not exist..."
cp -v --no-clobber ${BASE_DIR}/template/Makefile ${PROJECT_PATH}/Makefile

