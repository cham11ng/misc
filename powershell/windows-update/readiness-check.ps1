# Check if the OS version is Windows 10
if ([System.Environment]::OSVersion.Version.Major -eq 10) {
  Write-Host "Operating system: Windows 10"
  
  # Check for TPM (Trusted Platform Module)
  $tpm = Get-WmiObject -Namespace "Root\CIMv2\Security\MicrosoftTpm" -Class Win32_Tpm
  if ($tpm) {
      $tpmVersion = $tpm.SpecVersion
      Write-Host "TPM version: $tpmVersion"
  } else {
      Write-Host "TPM not found. Device is not eligible for Windows 11."
      Exit
  }

  # Check for Secure Boot
  $secureBoot = Get-WmiObject -Namespace "Root\CIMv2\Security\MicrosoftVolumeEncryption" -Class Win32_EncryptableVolume
  if ($secureBoot) {
      Write-Host "Secure Boot: Enabled"
  } else {
      Write-Host "Secure Boot: Disabled. Device is not eligible for Windows 11."
      Exit
  }

  # Check for supported CPU architecture (64-bit)
  $cpuArchitecture = (Get-WmiObject -Class Win32_Processor).AddressWidth
  if ($cpuArchitecture -eq 64) {
      Write-Host "CPU architecture: 64-bit"
  } else {
      Write-Host "Unsupported CPU architecture. Device is not eligible for Windows 11."
      Exit
  }

  # Check for minimum RAM requirement (4 GB)
  $ram = (Get-WmiObject -Class Win32_ComputerSystem).TotalPhysicalMemory / 1GB
  if ($ram -ge 4) {
      Write-Host "RAM: $ram GB"
  } else {
      Write-Host "Insufficient RAM. Device is not eligible for Windows 11."
      Exit
  }

  Write-Host "Device meets the minimum requirements for Windows 11 upgrade."
} else {
  Write-Host "Operating system: Not Windows 10. Windows 11 upgrade is not applicable."
}
