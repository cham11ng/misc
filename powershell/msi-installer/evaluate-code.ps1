<#
.SYNOPSIS
    MSI Software Installation (System Wide\All Users) - Evaluation Script
    OS Support: Windows 7 and above
    Required modules: NONE
.DESCRIPTION
    This worklet is designed to grant an Admin the ability to install a system wide (All Users) MSI with minimal knowledge of the bitness,
    command line, or other MSI properties. By placing an application name between the single quotes, the worklet will
    scan the registry for the matching application. If the application is not found, it will return an Exit code of '1'
    and flag the device for remediation.

    Usage:
    Modify the following variable found in the "Make changes within this block" section of the script below.

    $appName:
    The application name provided should match closly as it is displayed in "Programs and Features" (Add or Remove Programs)
    for Win7/8.1, and "Apps and Features" for Win10. Universal Windows Platform (UWP) applications are not currently
    supported in this worklet.

    $dispVer:
    This is the version of the application you are detecting. This version should match the displayversion in the registry.
.EXAMPLE
    $appName = '7-Zip'
    $dispVer = '1.0.2'
.NOTES
    Modified Date: October 5, 2023
#>

######## Make changes within the block ########
# Add Application name exactly as it appears in Add/Remove Programs, Programs and Features, or Apps and Features between single quotes.
$appName = ''
$dispVer = ''
###############################################

# Check 64bit hive on x64 devices
if([System.Environment]::Is64BitOperatingSystem)
{
    $hklm64 = [Microsoft.Win32.RegistryKey]::OpenBaseKey([Microsoft.Win32.RegistryHive]::LocalMachine,[Microsoft.Win32.RegistryView]::Registry64)
    $skey64 = $hklm64.OpenSubKey("Software\Microsoft\Windows\CurrentVersion\Uninstall")
    $unkeys64 = $skey64.GetSubKeyNames()
    foreach($key in $unkeys64)
    {
        if($skey64.OpenSubKey($key).getvalue('DisplayName') -like "*$AppName*" -and [Version]$skey64.OpenSubKey($key).getvalue('DisplayVersion') -ge [Version]$dispVer)
        {
            $installed += 1
            # Close and Null
            $skey64.close()
            $hklm64.close()
        }
    }
}
# Check 32bit hive on 32 bit devices
$skey32 = "HKLM:\Software\Microsoft\Windows\CurrentVersion\Uninstall"
foreach($key in Get-ChildItem $skey32 -ErrorAction SilentlyContinue | Get-ItemProperty | Where-Object {($_.DisplayName -like $appName -and [Version]$_.DisplayVersion -ge [Version]$dispVer)})
{
    $installed += 1
}
# If any matches were found, $installed will return a "1" and pass it to $exitCode flagging the device for remediation.
if ($installed)
{
    Exit 0
}
else
{
    Exit 1
}
