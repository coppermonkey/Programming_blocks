### Check if the current terminal is Administrator or not
```powershell
[bool](([System.Security.Principal.WindowsIdentity]::GetCurrent()).groups -match "S-1-5-32-544")
```


### Force delete a folder
Sometimes a folder/file can't be deleted and Windows may complain saying file no longer exist. run something like below in that case in cmd prompt
```powershell
rd /s "\\?\D:\DsMainDev\<remaining-path>"
```

### Find holding proccess and kill it
```powershell
https://stackoverflow.com/questions/45713467/how-to-force-delete-an-open-file-using-powershell
$allProcesses = Get-Process
#$lockedFile is the file path
foreach ($process in $allProcesses) { 
$process.Modules | where {$_.FileName -eq $lockedFile} | Stop-Process
-Force -ErrorAction SilentlyContinue
    }
Remove-Item $lockedFile
```

### Some commands alternative to linux
```powershell
gc log.txt | select -first 10 # head
gc -TotalCount 10 log.txt     # also head
gc log.txt | select -last 10  # tail
gc -Tail 10 log.txt           # also tail (since PSv3), also much faster than above option
gc log.txt | more             # or less if you have it installed
gc log.txt | %{ $_ -replace '\d+', '($0)' }         # sed
```

### Links
[Native Win32 ports of some GNU utilities (sourceforge.net)](http://unxutils.sourceforge.net/)

#### fd
`fd` an alternative `find` https://microsoft.sharepoint.com/teams/corext/LivingDocs/CorextExe.aspx
`choco install fd`

### ripgrep
https://github.com/BurntSushi/ripgrep/

### tree
https://github.com/dduan/tre

https://github.com/files-community/Files
