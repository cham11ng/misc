#!/bin/bash
LOGIN_USER=ctf-2024
FLAG_PREFIX=testCTF

# if $USER is not LOGIN_USER, exit
if [ "$USER" != "$LOGIN_USER" ]; then
    echo "Please run as '$LOGIN_USER' user."
    exit 0
fi

# --- Setting up services ---

echo "Hold on..."

# Enabling services and supress output
systemctl enable ssh &> /dev/null
systemctl enable vsftpd &> /dev/null
systemctl enable apache2 &> /dev/null

# Start services
systemctl start ssh
systemctl start vsftpd
systemctl start apache2

# Print second flag.
echo "Congratulations! Here is your second flag:"
echo
echo "${FLAG_PREFIX}{2ndFlagCaptur3dBy$USER}"
