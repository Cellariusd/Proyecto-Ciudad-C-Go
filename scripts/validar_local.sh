#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
echo "== C: compilación y pruebas de infraestructura =="
make -C c
make -C c test
echo "== Go: formato, compilación y pruebas de infraestructura =="
(cd go && test -z "$(gofmt -l .)" && go test ./... && go build -o /tmp/ciudad-go-local .)
echo "OK: ambos esqueletos compilan. ALGORITMOS PENDIENTES."
