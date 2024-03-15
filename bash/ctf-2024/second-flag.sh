#!/bin/bash

# if $USER is not ctf-2024, exit
if [ "$USER" != "ctf-2024" ]; then
    echo "Please run as ctf-2024."
    exit 0
fi

# Print second flag.
echo "Second part of flag is:"
echo
echo "$USER}"
