#!/bin/bash

# Check if $USER is not root
if [ "$USER" != "root" ]; then
    echo "Please run as root."
    exit 1
fi

echo "First part of flag is:"
echo

# Check if ctf-2024 user exists in password file exit
if grep -q "ctf-2024" /etc/passwd; then
    # Print first flag with $USER
    echo "triOS{$USER-to-"
    exit 0
fi

# --- Setting up Default Kali Linux ---

# Remove read, write, execute permission for group and others
# for all files in /home directory
# This is to prevent other users from reading, writing, or executing
sudo chmod go-rwx /home/* 

# Change password silently to triOSCTF2024
echo "root:triOSCTF2024" | chpasswd
echo "kali:triOSCTF2024" | chpasswd

# ---- Setting up user "john" ----

# Delete user john with home directory if exists
# Check john user if exists in password file
if grep -q "john" /etc/passwd; then
    # Delete user john
    userdel john
    rm -rf /home/john
fi

# Add user john
# Set default shell for john to bash
# Set the ownership of the .ssh directory to john
# Change the password for the user john
useradd -m john
usermod -s /bin/bash john
echo "john:password12345" | chpasswd

# Installing ufw, apache2, vsftpd.
apt-get -qqq update
apt-get -qqq install -y ufw vsftpd apache2

# --- Configuring FTP ---
# Create a directory for FTP user
mkdir /var/ftp
cp /etc/vsfptd.conf /etc/vsftpd.conf.bak
sed -i 's/anonymous_enable=NO/anonymous_enable=YES/g' /etc/vsftpd.conf
sed -i 's/#anon_upload_enable=YES/anon_upload_enable=YES/g' /etc/vsftpd.conf
echo "triOS{FTP-Was-Not-Secure}" > /var/ftp/flag.txt
chown nobody:nogroup /var/ftp/*

# Generate ssh on current directy and copy to john's home directory
mkdir /home/john/.ssh
ssh-keygen -t rsa -f "/home/john/.ssh/id_rsa" -q -N "secret"
chown -R john:john /home/john/.ssh

# --- Setting up services ---

# Start ssh, ftp service in Kali linux
systemctl enable ssh
systemctl enable vsftpd
service ssh start
service vsftpd start

# enable service of apache2
systemctl enable apache2
systemctl start apache2

# --- Setting up firewall ---
ufw enable
ufw allow ssh
ufw allow http
ufw allow 20/tcp
ufw allow 21/tcp

# --- Setting up CTF-2024 user ---

# Add user ctf-2024
# Set default shell for john to bash
# Change the password for the user ctf-2024 to trios
useradd -m ctf-2024
usermod -s /bin/bash ctf-2024
echo "ctf-2024:trios" | chpasswd

# --- Print flag ---

# Print first flag with $USER
echo "triOS{$USER-to-"
