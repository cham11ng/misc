#!/bin/bash
LOGIN_USER=ctf-2024

# if $USER is not LOGIN_USER, exit
if [ "$USER" != "$LOGIN_USER" ]; then
    echo "Please run as '$LOGIN_USER' user."
    exit 0
fi

# Print second flag.
echo "Second part of flag is:"
echo
echo "$USER}"
