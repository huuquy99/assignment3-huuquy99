#!/bin/bash

writefile="$1"
writestr="$2"

if [ -z "$1" ] || [ -z "$2" ]; then
    echo "Error: Both arguments are required."
    exit 1
fi

mkdir -p "$(dirname "$writefile")"

if [ $? -ne 0 ]; then
    echo "Error: Could not create directory."
    exit 1
fi

echo "$writestr" > "$writefile"

if [ $? -ne 0 ]; then
    echo "Error: Could not write to file."
    exit 1
fi