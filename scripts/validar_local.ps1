$ErrorActionPreference = 'Stop'
Set-Location (Join-Path $PSScriptRoot '..')
Write-Host '== C: compilacion ==' 
Push-Location c
try {
    gcc -std=c11 -Wall -Wextra -Wpedantic main.c modelo.c gestion.c validacion.c horizonte.c geometria.c graficos.c archivos.c -o ciudad.exe -lm
    if ($LASTEXITCODE -ne 0) { throw 'Fallo compilacion C' }
} finally { Pop-Location }
Write-Host '== Go: compilacion y pruebas de infraestructura =='
Push-Location go
try {
    go test ./...
    if ($LASTEXITCODE -ne 0) { throw 'Fallo go test' }
    go build -o ciudad-go.exe .
    if ($LASTEXITCODE -ne 0) { throw 'Fallo go build' }
} finally { Pop-Location }
Write-Host 'OK: esqueletos compilados; algoritmos pendientes.'
