#!/bin/bash
LOGIN_USER=ctf-2024
FLAG_PREFIX=testCTF

# if $USER is not LOGIN_USER, exit
if [ "$USER" != "$LOGIN_USER" ]; then
    echo "Please run as '$LOGIN_USER' user."
    exit 0
fi

# Print second flag.
echo "Congratulations! Here is your second flag:"
echo
echo "${FLAG_PREFIX}{2ndFlagCaptur3dBy$USER}"
