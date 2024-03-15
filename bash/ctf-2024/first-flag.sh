#!/bin/bash
FLAG_PREFIX=testCTF
FLAG_FTP=FTPNotSecure
ROOT_PASS=CTF2024
FLAW_USER=john
FLAW_PASS=password12345
LOGIN_USER=ctf-2024
LOGIN_PASS=trios

# Check if $USER is not root
if [ "$USER" != "root" ]; then
    echo "Please run as `root`."
    exit 1
fi

echo "First part of flag is:"
echo

# Check if LOGIN_USER user exists in password file exit
if grep -q "${LOGIN_USER}" /etc/passwd; then
    # Print first flag with $USER
    echo "${FLAG_PREFIX}{$USER-to-"
    exit 0
fi

# --- Setting up Default Kali Linux ---

# Remove read, write, execute permission for group and others
# for all files in /home directory
# This is to prevent other users from reading, writing, or executing
sudo chmod go-rwx /home/* 

# Change password silently to ${ROOT_PASS}
echo "root:${ROOT_PASS}" | chpasswd
echo "kali:${ROOT_PASS}" | chpasswd

# ---- Setting up user "FLAW_USER" ----

# Delete user FLAW_USER with home directory if exists
# Check FLAW_USER user if exists in password file
if grep -q "${FLAW_USER}" /etc/passwd; then
    # Delete user FLAW_USER
    userdel ${FLAW_USER}
    rm -rf /home/${FLAW_USER}
fi

# Add user FLAW_USER
# Set default shell for FLAW_USER to bash
# Set the ownership of the .ssh directory to FLAW_USER
# Change the password for the user FLAW_USER
useradd -m ${FLAW_USER}
usermod -s /bin/bash ${FLAW_USER}
echo "${FLAW_USER}:${FLAW_PASS}" | chpasswd

# Generate ssh on current directy and copy to FLAW_USER's home directory
mkdir /home/${FLAW_USER}/.ssh
ssh-keygen -t rsa -f "/home/${FLAW_USER}/.ssh/id_rsa" -q -N "secret"
chown -R ${FLAW_USER}:${FLAW_USER} /home/${FLAW_USER}/.ssh

# --- Installing packages ---

# Installing ufw, apache2, vsftpd.
apt-get -qqq update
apt-get -qqq install -y ufw vsftpd apache2

# --- Misconfiguring FTP ---
# Create a directory for FTP user
mkdir /var/ftp
cp /etc/vsfptd.conf /etc/vsftpd.conf.bak
sed -i 's/anonymous_enable=NO/anonymous_enable=YES/g' /etc/vsftpd.conf
sed -i 's/#anon_upload_enable=YES/anon_upload_enable=YES/g' /etc/vsftpd.conf
echo "${FLAG_PREFIX}{${FLAG_FTP}}" > /var/ftp/flag.txt
chown nobody:nogroup /var/ftp/*

# --- Setting up services ---

# Enabling services
systemctl enable ssh
systemctl enable vsftpd
systemctl enable apache2

# Start services
systemctl start ssh
systemctl start vsftpd
systemctl start apache2

# --- Setting up firewall ---
ufw enable
ufw allow ssh
ufw allow http
ufw allow 20/tcp
ufw allow 21/tcp

# --- Setting up LOGIN_USER user ---

# Add user LOGIN_USER
# Set default shell for LOGIN_USER to bash
useradd -m ${LOGIN_USER}
usermod -s /bin/bash ${LOGIN_USER}
echo "${LOGIN_USER}:${LOGIN_PASS}" | chpasswd

# --- Print flag ---

# Print first flag with $USER
echo "${FLAG_PREFIX}{$USER-to-"
