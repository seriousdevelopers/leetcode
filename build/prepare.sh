#!/usr/bin/bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
BASE_DIR=${SCRIPT_DIR}/..
REAL_BASE_DIR=$(realpath ${BASE_DIR})
REAL_PWD=${PWD}

if [ "$REAL_BASE_DIR" == "$REAL_PWD" ] || [ "$REAL_BASE_DIR/build" == "$REAL_PWD" ] || [ "$REAL_BASE_DIR/template" == "$REAL_PWD" ]; then
    echo "Make a problem directory. Then, retry this script."
    exit 1
fi

echo Copying a Makefile if it does not exist...
cp --no-clobber ${BASE_DIR}/template/Makefile ${PWD}/Makefile

