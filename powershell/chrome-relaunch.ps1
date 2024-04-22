$chromePath = "C:\Program Files\Google\Chrome\Application\chrome.exe"

if (Test-Path $chromePath) {
    Write-Output "Google Chrome found on the system."

    $chromeInstances = Get-Process chrome -ErrorAction SilentlyContinue | Select-Object -ExpandProperty Id
    
    if ($chromeInstances) {
        Write-Output "Google Chrome is running. Exiting."
        Exit 1
    }

    Write-Output "Starting Google Chrome."

    # Start Google Chrome
    Start-Process -FilePath $chromePath
    
    # Wait for a moment to completely open Google Chrome
    Start-Sleep -Seconds 5
  
    $chromeInstances = Get-Process chrome -ErrorAction SilentlyContinue | Select-Object -ExpandProperty Id
  
    if ($chromeInstances) {
        Write-Output "Stopping Google Chrome."
        Stop-Process -Id $chromeInstances -Force
            
        # Wait for a moment to completely close Google Chrome
        Start-Sleep -Seconds 5
    }
    
    Write-Output "Relaunching Google Chrome."
    
    Start-Process -FilePath $chromePath

    if ($chromeInstances) {
        Write-Output "Stopping Relaunched Google Chrome."
        Stop-Process -Id $chromeInstances -Force
    }

    Write-Output "Google Chrome has been started and relaunched for updating patch."
} else {
    Write-Output "Google Chrome not found on the system."
}
