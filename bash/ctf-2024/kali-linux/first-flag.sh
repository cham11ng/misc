#!/bin/bash
FLAG_PREFIX=testCTF
FLAG_FTP=FTPNotSecure
FLAG_SSH=PoorPassword
FLAG_ROOT=RootFlag

ROOT_PASS=CTF2024
FLAW_USER=john
FLAW_PASS=password
LOGIN_USER=ctf-2024
LOGIN_PASS=kali

# Check if $USER is not root
if [ "$USER" != "root" ]; then
    echo "Please run as 'root' user."
    exit 1
fi

# ---- Setting up user "FLAW_USER" ----

echo "Managing your VM..."

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

# Create a flag.txt file in FLAW_USER's home directory
echo "${FLAG_PREFIX}{${FLAG_SSH}}" > /home/${FLAW_USER}/flag.txt
chown ${FLAW_USER}:${FLAW_USER} /home/${FLAW_USER}/flag.txt

# --- Installing packages ---

echo "Decrypting your network..."

# Installing ufw, apache2, vsftpd.
apt-get -qqq update &> /dev/null
apt-get -qqq install -y ufw vsftpd apache2 &> /dev/null

# --- Misconfiguring FTP ---
# Create a directory for FTP user
cp /etc/vsftpd.conf /etc/vsftpd.conf.bak
sed -i 's/anonymous_enable=NO/anonymous_enable=YES/g' /etc/vsftpd.conf
sed -i 's/#anon_upload_enable=YES/anon_upload_enable=YES/g' /etc/vsftpd.conf
echo "anon_root=/var/www/" >> /etc/vsftpd.conf

mkdir /var/www/static
chown nobody:nogroup /var/www/static
echo "${FLAG_PREFIX}{${FLAG_FTP}}" > /var/www/static/flag.txt
chown nobody:nogroup /var/www/static/flag.txt

# --- Setting up firewall ---
ufw enable &> /dev/null
ufw allow ssh &> /dev/null
ufw allow http &> /dev/null
ufw allow 20/tcp &> /dev/null
ufw allow 21/tcp &> /dev/null

# --- Setting up LOGIN_USER user ---

echo "Setting up login user: '${LOGIN_USER}'..."

# Delete user FLAW_USER with home directory if exists
# Check if LOGIN_USER user exists in password file exit
if grep -q "${LOGIN_USER}" /etc/passwd; then
    # Delete user LOGIN_USER
    userdel ${LOGIN_USER}
    rm -rf /home/${LOGIN_USER}
fi

# Add user LOGIN_USER
# Set default shell for LOGIN_USER to bash
useradd -m ${LOGIN_USER}
usermod -s /bin/bash ${LOGIN_USER}
echo "${LOGIN_USER}:${LOGIN_PASS}" | chpasswd
echo "------------------------------------------------------"
echo "      Password for user '${LOGIN_USER}' is: '${LOGIN_PASS}'"
echo "------------------------------------------------------"

# --- Setting up Default Kali Linux ---

# Remove read, write, execute permission for group and others
# for all files in /home directory
# This is to prevent other users from reading, writing, or executing
sudo chmod go-rwx /home/* 

# Change password silently to ${ROOT_PASS}
echo "root:${ROOT_PASS}" | chpasswd
echo "kali:${ROOT_PASS}" | chpasswd

# Create a flag.txt file using FLAG_ROOT
echo "${FLAG_PREFIX}{${FLAG_ROOT}}" > /root/flag.txt

# --- Print flag ---

echo
echo "Congratulations, agent!. You've captured your first flag."
echo

# Print first flag with $USER
echo "${FLAG_PREFIX}{1stFlagCaptur3dBy$USER}"
