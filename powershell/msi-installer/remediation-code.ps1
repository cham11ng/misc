<#
.SYNOPSIS
    MSI Software Installation (System Wide\All Users)- Remediation Script
    OS Support: Windows 7 and above
    Required modules: NONE
.DESCRIPTION
    This worklet is designed to grant an Admin the ability to install a system wide (All Users) MSI  with minimal knowledge of the bitness,
    command line, or other MSI properties. By placing the name of the MSI to be uploaded, between the single quotes,
    the worklet will apply the standard command line arguments to silently install the application with logging.
    Once installation has been completed, the script will then check both 32bit and 64bit registry hives to verify
    installation was successful.

    Usage:
    Modify the following variable found in the "Make changes within this block" section of the script below.

    $fileName:
    This is the filename, including extention, of the file to be uploaded into the console. See examples for more information.
    $custArgs:
    This is for customs arguments such as msi properties or additional parameters outside of the standard "/qn /norestart /l*v Path\fileName.log".
    These are included by default in the script.
.EXAMPLE
    $fileName = 'slack-standalone-4.13.0.0.msi'
    $custArgs = 'AllUSERS=1'
.NOTES
    Modified Date: October 5, 2023
#>

######## EDIT WITHIN THIS BLOCK #######
$fileName = ''
$custArgs = ''
#######################################

############### MAIN CODE #############
# MSI/Script location. Joined with filename to pass a single variable to function.
$sPath = Split-Path $Script:MyInvocation.MyCommand.Path -Parent
$fPath = "$sPath\$fileName"
$lPath = "$env:WINDIR\temp"

function Get-MSIPropertyList
{
    <#
    .SYNOPSIS
        Gets the five mandatory properties that all MSI files must contain to be valid and stores them in a table for later use.
    .DESCRIPTION
        This function will capture the 5 mandatory properties that all MSI files require to be considered a valid Windows Installer
        file.

        The following properties are captured:
        ProductCode: The ProductCode property is a unique identifier for the particular product release, represented as a string GUID.
        ProductLanguage: The ProductLanguage property specifies the language the installer will use. 4 digit code. (eg: 1033 for En-US)
        Manufacturer: The Manufacturer property is the name of the manufacturer for the product. Sometimes this is the Author.
        ProductVersion: Version of the MSI/Installation. This is in String format. Set type to [version] when comparing values.
        ProductName: This is the name of the application. This name is generally what displays in App and Features (Add and Remove Programs).

    Usage:
        You can run this function directly or by storing it into a variable for later use. This entire path to the MSI, including filename
        and extension should be supplied. See examples for more information.
    .EXAMPLE
        Get-MSIPropertyList -FilePath C:\Install\slack-standalone-4.13.0.0.msi
    .EXAMPLE
        (Get-MSIPropertyList -FilePath C:\Windows\Temp\7z1900-x64.msi).ProductCode
    .EXAMPLE
        $propTable1 = "Get-MSIPropertyList -FilePath C:\Windows\Temp\7z1900-x64.msi"
        $msiGuid = ($propTable1).ProductCode
    .NOTES
        Date: October 5, 2023
    #>

    param($FilePath)

    # Define input type for comobject
    [System.IO.FileInfo[]]$msiFile = "$FilePath"

    # Build Windows Installer comobject and define $msiProperties hashtable
    $installer = New-Object -ComObject WindowsInstaller.Installer
    $msiDatabase = $installer.GetType().InvokeMember("OpenDatabase","InvokeMethod",$null,$installer,@($msiFile.FullName,0))
    $properties = ("ProductCode","ProductLanguage","Manufacturer","ProductVersion","ProductName")
    $msiProperties = [ordered]@{}

    # Populate hashtable
    ForEach($property in $properties)
    {
        $query = "SELECT Value FROM Property WHERE Property = '$($property)'"
        $openView = $MSIDatabase.GetType().InvokeMember("OpenView","InvokeMethod",$null,$MSIDatabase,($query))
        $openView.GetType().InvokeMember("Execute","InvokeMethod",$null,$openView,$null)
        $fetchVal = $openView.GetType().InvokeMember("Fetch","InvokeMethod",$null,$openView,$null)
        $value = $fetchVal.GetType().InvokeMember("StringData","GetProperty",$null,$fetchVal,1)

    # Return the value to the Property Hash
        $msiProperties.Add($property,$value)
    }
    $proptable = @(New-Object -TypeName PSObject -Property $msiProperties )
    $MSIDatabase.GetType().InvokeMember("Commit", "InvokeMethod", $null, $MSIDatabase, $null)

    # Close view and null
    $openView.GetType().InvokeMember("Close", "InvokeMethod", $null, $openView, $null)
    $MSIDatabase = $null
    $openView = $null

    # return data
    write-output -InputObject $proptable
}
# Parcing varibles into a single string
if($custargs -ne '')
{
    $arglist = '/i "' + "$sPath" + '\' + "$fileName" + '" /qn /norestart ' + "$custArgs " + '/l*v "' + "$lPath" + '\' + "$fileName" + '.log"'
}
else
{
    $arglist = '/i "' + "$sPath" + '\' + "$fileName" + '" /qn /norestart /l*v "' + "$lPath" + '\' + "$fileName" + '.log"'
}

# Kicking off installer
start-process msiexec.exe -ArgumentList "$arglist" -wait

# Store Property Table and define parameters for registry detection
$prop = (Get-MSIPropertyList -FilePath "$fPath")
$guid = ($prop).ProductCode
$unPath = "Software\Microsoft\Windows\CurrentVersion\Uninstall"

# Capture 32bit/64bit registry info
$hklm64 = [Microsoft.Win32.RegistryKey]::OpenBaseKey([Microsoft.Win32.RegistryHive]::LocalMachine,[Microsoft.Win32.RegistryView]::Registry64)
$hklm32 = [Microsoft.Win32.RegistryKey]::OpenBaseKey([Microsoft.Win32.RegistryHive]::LocalMachine,[Microsoft.Win32.RegistryView]::Registry32)
$skey64 = $hklm64.OpenSubKey("$unPath\$guid")
$skey32 = $hklm32.OpenSubKey("$unPath\$guid")

# Check 64bit hive for installation
if($skey64)
{
if([Version]$skey64.GetValue('DisplayVersion') -ge [Version]($prop).ProductVersion)
{
    Write-Output "Installation of $fileName Successful"

# Close and Null
    $skey64.close()
    $hklm64.close()
    Exit 0
}
}

# Check 64bit hive for installation
if($skey32)
{
if([Version]$skey32.GetValue('DisplayVersion') -ge [Version]($prop).ProductVersion)
{
    Write-Output "Installation of $fileName Successful"

# Close and Null
    $skey32.close()
    $hklm32.close()
    Exit 0
}
}

Write-Output "Encountered Errors. See logfile at $lPath\$fileName.log"

Exit 1603