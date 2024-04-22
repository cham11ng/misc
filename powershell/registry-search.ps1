# Disk used and disk utilized
(Get-PSDrive -Name 'C' -PSProvider 'FileSystem')

# Disk size
Get-Disk -Number 0

Test-Path 'HKLM:\\SOFTWARE\\'  # Check registry path exist
Get-ItemProperty -Path 'HKLM:\\SOFTWARE\\' | Select-Object -ExpandProperty '' # Get registry value
Get-ChildItem -Path 'HKLM:\\SOFTWARE\\' # Get child value

## Disable Local Admin password management
# HKLM\SOFTWARE\Policies\Microsoft Services\AdmPwd\AdmPwdEnabled
Test-Path 'HKLM:\\SOFTWARE\\Policies\\Microsoft Services\\AdmPwd'
Get-ItemProperty -Path 'HKLM:\\SOFTWARE\\Policies\\Microsoft Services\\AdmPwd' | Select-Object -ExpandProperty 'AdmPwdEnabled'
Get-ChildItem -Path 'HKLM:\\SOFTWARE\\Policies\\Microsoft Services\\'

## Disable "Installation and configuration of Network Bridge on DNS"
# HKLM\SOFTWARE\Policies\Microsoft\Windows\Network Connections\NC_AllowNetBridge_NLA
Test-Path 'HKLM:\\SOFTWARE\\Policies\\Microsoft\\Windows\\Network Connections\\'  # Check registry path exist
Get-ItemProperty -Path 'HKLM:\\SOFTWARE\\Policies\\Microsoft\\Windows\\Network Connections\\' | Select-Object -ExpandProperty 'NC_AllowNetBridge_NLA' # Get registry value
Get-ItemProperty -Path 'HKLM:\\SOFTWARE\\Policies\\Microsoft\\Windows\\Network Connections\\' # Get all properties
Get-ChildItem -Path 'HKLM:\\SOFTWARE\\Policies\\Microsoft\\Windows\\' # Get child value

## Set User Account Control (UAC) to automatically deny elevation requests
# HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System
Get-ItemProperty -Path 'HKLM:\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System' | Select-Object -ExpandProperty 'ConsentPromptBehaviorUser'

## Disable the local storage of passwords and credentials
# HKLM\SYSTEM\CurrentControlSet\Control\Lsa\DisableDomainCreds
Get-ItemProperty -Path 'HKLM:\\SYSTEM\\CurrentControlSet\\Control\\Lsa' | Select-Object -ExpandProperty 'DisableDomainCreds'

Get-ItemProperty -Path 'HKLM:\\SYSTEM\\CurrentControlSet\\Control\\Lsa' | Select-Object -ExpandProperty 'DisableDomainCreds'

# Microsoft Update
Get-ItemProperty -Path 'HKLM:\\SOFTWARE\Policies\Microsoft\office\16.0\common\officeupdate'
