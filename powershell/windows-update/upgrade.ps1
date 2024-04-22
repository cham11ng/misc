$DLPath = "C:\Win11UpgradeTemp"
$LogPath = "C:\Win11UpgradeTemp\Logs"
$DLLink = "https://go.microsoft.com/fwlink/?linkid=2171764"
$PackagePath = "$DLPath\Win11_WIA.exe"

function DownloadAssistant {
  #If the Download or Log file path is not found, create it and suppress the output of the New-Item cmdlet.
  if (!(Test-Path -Path $DLPath)) { $null = New-Item -ItemType Directory -Path $DLPath -Force }
  if (!(Test-Path -Path $LogPath)) { $null = New-Item -ItemType Directory -Path $LogPath -Force }

  try {
    Write-Output "Attempting to download the Windows Installation Assistant media from Microsoft."
		(New-Object System.Net.WebClient).DownloadFile($DLLink, "$PackagePath")
  }

  catch {
    if ($_.Exception.InnerException.Message.Contains('Could not create SSL/TLS secure channel')) {
      Write-Output "Unable to download the Windows Installation Assistant due to TLS12 being disabled."
      Write-Output 'Enabling TLS 1.2 and attempting to re-download...'
      [Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12
			(New-Object System.Net.WebClient).DownloadFile($DLLink, "$PackagePath")
    }

    else {
      Write-Output "Download failed with the following error:"
      $Exception = $error[0].Exception.Message + "`nAt Line " + $error[0].InvocationInfo.ScriptLineNumber
      Write-Error $Exception
      Write-Output "Now exiting."
      Exit 1
    }
  }
}

function Win11UpgradeWIA {
  try {
    Write-Output "Invoking Windows Installation Assistant silently."

    # Check if the Windows Installation Assistant executable exists
    if (-not (Test-Path $PackagePath -PathType Leaf)) {
      Write-Host "Windows Installation Assistant not found. Downloading."
      
      DownloadAssistant 
    }
    
    # Run the Windows Installation Assistant to upgrade to Windows 11
    Start-Process -FilePath "$PackagePath" -ArgumentList ('/copylogs $LogPath', '/quietinstall', '/skipeula', '/auto upgrade')
    Write-Output "Windows Installation Assistant has been ran and the Feature Update is now in the process of downloading."
    Write-Output "This process may take several hours."
    Write-Output "The device will be rebooted automatically to finalize the upgrade once it is fully cached."
    
    Exit 0
  }

  catch {
    Write-Output "The Windows Update Assistant failed to run."
    $Exception = $error[0].Exception.Message + "`nAt Line " + $error[0].InvocationInfo.ScriptLineNumber
    Write-Error $Exception
    Write-Output "Now exiting."
    Exit 1
  }
}

Win11UpgradeWIA