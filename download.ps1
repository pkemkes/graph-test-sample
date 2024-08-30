# create directories
$codePath = "C:\Code"
if (-Not (Test-Path $codePath)) {
    Write-Output "Create target directory."
    New-Item -Path "C:\" -Name "Code" -ItemType "directory"
}

# download sample files
$downloadOutlookPath = "$codePath\OUTLOOK.EXE"
if (-Not (Test-Path $downloadOutlookPath)) {
	Write-Output "Downloading sample file."
	(New-Object System.Net.WebClient).DownloadFile("https://github.com/pkemkes/graph-test-sample/releases/download/v0.21/outlook.exe", $downloadOutlookPath)
}
$downloadFirefoxPath = "$codePath\firefox.exe"
if (-Not (Test-Path $downloadFirefoxPath)) {
	Write-Output "Downloading sample file."
	(New-Object System.Net.WebClient).DownloadFile("https://github.com/pkemkes/graph-test-sample/releases/download/v0.21/firefox.exe", $downloadFirefoxPath)
}

$programFilesPath = [Environment]::GetFolderPath("ProgramFiles")
$firefoxPath = "$programFilesPath\Mozilla Firefox"
if (-Not (Test-Path $firefoxPath)) {
    Write-Output "Create Mozilla directory."
    New-Item -Path $programFilesPath -Name "Mozilla Firefox" -ItemType "directory"
}

$programFilesX86Path = [Environment]::GetFolderPath("ProgramFilesX86")
$officePath = "$programFilesX86Path\Microsoft Office"
if (-Not (Test-Path $officePath)) {
    Write-Output "Create Office directory."
    New-Item -Path $programFilesX86Path -Name "Microsoft Office" -ItemType "directory"
}
$outlookPath = "$officePath\Office16"
if (-Not (Test-Path $outlookPath)) {
    Write-Output "Create Outlook directory."
    New-Item -Path $officePath -Name "Office16" -ItemType "directory"
}

# copy file
$desktopPath = [Environment]::GetFolderPath("Desktop")
Copy-Item $downloadOutlookPath -Destination $outlookPath
Copy-Item $downloadFirefoxPath -Destination $firefoxPath

# cleanup
Remove-Item -Path $downloadOutlookPath
Remove-Item -Path $downloadFirefoxPath

# zone change
if (Test-Path "$outlookPath\OUTLOOK.EXE") {
    Set-Content -Path $outlookPath\OUTLOOK.EXE -Stream Zone.Identifier -Value '[ZoneTransfer]','ZoneId=3'
}
if (Test-Path "$firefoxPath\firefox.exe") {
    Set-Content -Path $firefoxPath\firefox.exe -Stream Zone.Identifier -Value '[ZoneTransfer]','ZoneId=3'
}
