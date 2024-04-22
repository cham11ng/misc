try {
    Get-Process -Name “App Name” -ErrorAction Stop | Stop-Process -Force
    Write-Output "Closing App…”
}

catch {
    Write-Output “App not open, continuing..."
}
