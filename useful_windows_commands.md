### Check if the current terminal is Administrator or not
```powershell
[bool](([System.Security.Principal.WindowsIdentity]::GetCurrent()).groups -match "S-1-5-32-544")
```


### Force delete a folder
Sometimes a folder/file can't be deleted and Windows may complain saying file no longer exist. run something like below in that case in cmd prompt
```bash
rd /s "\\?\D:\DsMainDev\<remaining-path>"
```
