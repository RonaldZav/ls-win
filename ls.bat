@echo off
set "params="

:: Revisar si el primer argumento es "-a"
if "%~1"=="-a" (
    set "params=-Force"
    shift
)

:: Si no se pasa un directorio, usar el actual
if "%~1"=="" (
    set "dir=."
) else (
    set "dir=%~1"
)

:: Ejecutar PowerShell con detección de archivos ejecutables
powershell -NoProfile -ExecutionPolicy Bypass -Command ^
    "$items = Get-ChildItem '%dir%' %params% | Sort-Object Name; $columns = 4; $width = [console]::WindowWidth / $columns; $i = 0; foreach ($item in $items) { $ext = $item.Extension.ToLower(); if ($item.PSIsContainer) { Write-Host ($item.Name.PadRight($width)) -ForegroundColor Blue -NoNewline; } elseif ($ext -in ('.exe', '.msi', '.bat', '.cmd', '.jar')) { Write-Host ($item.Name.PadRight($width)) -ForegroundColor Green -BackgroundColor Black -NoNewline; } else { Write-Host ($item.Name.PadRight($width)) -ForegroundColor White -NoNewline; } $i++; if ($i %% $columns -eq 0) { Write-Host '' } }; Write-Host ''"

