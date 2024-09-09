# create directory
if (-Not (Test-Path "C:\Code")) {
    Write-Output "Create target directory."
    New-Item -Path "C:\" -Name "Code" -ItemType "directory"
}

# download sample zip files
if (-Not (Test-Path "C:\Code\sample.7z")) {
	Write-Output "Downloading sample file."
	(New-Object System.Net.WebClient).DownloadFile("https://github.com/pkemkes/graph-test-sample/releases/latest/download/sample.7z", "C:\Code\sample.7z")
}

# unzip files
$desktopPath = [Environment]::GetFolderPath("Desktop")
7z e -o"$desktopPath" -y -pinfected C:\Code\sample.7z

# cleanup
Remove-Item -Path C:\Code\sample.7z

# zone change
if (Test-Path "$desktopPath\sample.exe") {
    Set-Content -Path $desktopPath\sample.exe -Stream Zone.Identifier -Value '[ZoneTransfer]','ZoneId=3'
}
