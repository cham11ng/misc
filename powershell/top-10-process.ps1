Get-Process | Sort-Object -Property WorkingSet64 -Descending | Select-Object -First 10 -Property Name, Id, @{Name = 'Memory (MB)'; Expression = { "{0:N2}" -f ($_.WorkingSet64 / 1MB) } }
