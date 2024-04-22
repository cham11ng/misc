wmic service get name,pathname,displayname,startmode | findstr /i auto | findstr /i /v "C:\\Windows\\\\" | findstr /i /v "\"

# Computer\HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\ and change path with quotation