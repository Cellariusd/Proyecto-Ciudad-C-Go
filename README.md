# Proyecto Programación I: Ciudad de edificios (C + Go)

**Repositorio inicial para 7 integrantes — arquitectura y funciones pendientes.**

Este repositorio parte del documento oficial incluido en
[`docs/enunciado/Proyecto_Programacion_I.pdf`](docs/enunciado/Proyecto_Programacion_I.pdf).
Representa edificios `(xi, xf, h)`, calcula su horizonte, área/perímetro de la
unión, genera dos gráficos y guarda/carga la ciudad.

> **Estado: ESQUELETO COMPILABLE, NO SOLUCIÓN TERMINADA.**
> Las funciones de los 6 módulos de negocio devuelven `ESTADO_PENDIENTE`
> o `ErrNoImplementado`. El menú muestra estos estados con claridad.
> Compilar o superar las pruebas iniciales NO significa aprobar los casos geométricos.

## Empezar aquí

1. [`docs/GITHUB_PASO_A_PASO.md`](docs/GITHUB_PASO_A_PASO.md): publicar el repositorio e invitar compañeros.
2. [`docs/DECISIONES.md`](docs/DECISIONES.md): decisiones que deben aprobar antes de cambiar código.
3. [`docs/CONTRATOS.md`](docs/CONTRATOS.md): estructuras, funciones y resultados acordados.
4. [`docs/ASIGNACIONES.md`](docs/ASIGNACIONES.md): 7 módulos y responsabilidades únicas.
5. [`docs/ISSUES_PARA_CREAR.md`](docs/ISSUES_PARA_CREAR.md): Issues iniciales listos para copiar.
6. [`docs/GO_DESDE_C.md`](docs/GO_DESDE_C.md): migración de conceptos C a Go.
7. [`docs/PRUEBAS.md`](docs/PRUEBAS.md): escenarios oficiales y casos manuales.
8. [`docs/diagramas/arquitectura.md`](docs/diagramas/arquitectura.md): diagramas Mermaid.

## Estructura del repositorio

```text
proyecto-ciudad/
├── .github/             # CI, Issue templates y PR template
├── c/
│   ├── modelo.h/c        # Contratos de estructuras y estados
│   ├── gestion.h/c       # Integrante 1
│   ├── validacion.h/c    # Integrante 2
│   ├── horizonte.h/c     # Integrante 3
│   ├── geometria.h/c     # Integrante 4
│   ├── graficos.h/c      # Integrante 5
│   ├── archivos.h/c      # Integrante 6
│   ├── main.c            # Integrante 7: menú de integración
│   ├── Makefile
│   └── tests/
├── go/                   # Las mismas responsabilidades en Go
├── tests/                # Ciudades y resultados esperados
└── docs/                 # Contratos, guía, enunciado y pruebas
```

## Compilar C

Desde la raíz en Linux/macOS o Windows con `make`/GCC disponibles:

```bash
make -C c
make -C c test
./c/build/ciudad
```

En Windows con GCC instalado y sin `make`:

```bash
cd c
gcc -std=c11 -Wall -Wextra -Wpedantic main.c modelo.c gestion.c validacion.c horizonte.c geometria.c graficos.c archivos.c -o ciudad.exe -lm
ciudad.exe
```

## Compilar Go

```bash
cd go
go test ./...
go run .
```

`go.mod` usa un nombre de módulo local genérico; pueden actualizarlo si crean
paquetes adicionales o publican un módulo externo.

## Reglas de colaboración

- `main` = estable; `develop` = integración.
- Ramas `feature/c-*` y después `feature/go-*`, creadas desde `develop`.
- Cada PR debe incluir pruebas reales y explicación del algoritmo.
- Cambios en `modelo.h`/`modelo.go` se acuerdan entre todos antes de fusionar.
- No añadir funcionalidades incompletas como si estuvieran terminadas.
- Los siete responsables implementan el MISMO problema en C y Go.

## Casos de referencia

| Caso | Área | Perímetro |
|---|---:|---:|
| 1 edificio `(0,4,3)` | 12 | 14 |
| 2 consecutivos con h=3 | 15 | 16 |
| 2 superpuestos de distinta altura | 26 | 22 |
| 2 separados | 10 | 18 |
| Oficial del documento | 95 | 74 |

Ver los datos exactos en [`docs/PRUEBAS.md`](docs/PRUEBAS.md).

**Importante:** el enunciado exige gráficos de TODOS los edificios y el horizonte,
con ejes y escala; la decisión de utilizar SVG debe confirmarse con el docente.
