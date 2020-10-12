#!/usr/bin/env bash

set -e
set -o pipefail

function print_header() {
    echo -e "\n***** ${1} *****"
}

print_header "RUN cpplint.py"
python2.7 ./build/linters/cpplint/cpplint.py --extensions=c --headers=h,hpp --filter=-runtime/references,-legal/copyright,-build/include_subdir,-whitespace/line_length ./include/* ./src/*

print_header "SUCCESS"
