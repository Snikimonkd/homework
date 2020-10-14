#!/usr/bin/env bash

set -e
set -o pipefail

function print_header() {
    echo -e "\n***** ${1} *****"
}

print_header "RUN cppcheck"
if [ "${1}" == "--local" ]; then
	CPPCHECK="cppcheck"
else
	CPPCHECK="./build/linters/cppcheck/cppcheck"
fi
${CPPCHECK} project --enable=all --error-exitcode=1 -I include --suppress=missingIncludeSystem # --check-config

print_header "RUN cpplint.py"
python2.7 ./build/linters/cpplint/cpplint.py --extensions=c include/* src/*

print_header "SUCCESS"
