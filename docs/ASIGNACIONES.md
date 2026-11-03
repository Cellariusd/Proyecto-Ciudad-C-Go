# Reparto para 7 integrantes

| # | Responsabilidad única | Archivos C | Archivos Go | Prerrequisitos | Entrega mínima |
|---|---|---|---|---|---|
| 1 | Gestión | gestion.c/h | gestion.go | struct, arreglos, punteros | CRUD y lista |
| 2 | Validación y entrada | validacion.c/h | validacion.go | fgets, strtod/strtol, strconv | números seguros, edificios válidos |
| 3 | Horizonte | horizonte.c/h | horizonte.go | sort, ciclos anidados, máximos | tramos fusionados y huecos |
| 4 | Área y perímetro | geometria.c/h | geometria.go | funciones, matemáticas, valor absoluto | áreas y perímetros exactos |
| 5 | Gráficos | graficos.c/h | graficos.go | SVG, coordenadas, escalas | dos archivos legibles |
| 6 | Persistencia | archivos.c/h | archivos.go | fopen/fgets/fprintf, os/bufio | guardar/cargar atómicamente |
| 7 | Menú, integración y pruebas | main.c, tests | main.go, pruebas | API, compilación, GitHub Actions | navegación, casos y revisión |

El archivo `modelo.h`/`modelo.go` es compartido y no debe editarse unilateralmente.
La revisión cruzada de pruebas está permitida; el autor responsable conserva cada módulo.

## Secuencia de trabajo

1. Coordinar `docs/DECISIONES.md` y `docs/CONTRATOS.md`.
2. Cada integrante desarrolla C, abre PR a `develop` y responde observaciones.
3. Un módulo de geometría puede usar un horizonte escrito manualmente en pruebas sin esperar al módulo 3.
4. El responsable 7 conecta el menú, activa pruebas de integración y corrige dependencias.
5. Verificar TODOS los casos obligatorios del PDF y documentar trazado manual.
6. Cada responsable crea una nueva rama para el mismo módulo en Go.
7. Reutilizar fixtures para comparar C vs Go y producir el informe.

## Tabla de habilidades C -> Go por módulo

| # | Antes en C | Después en Go |
|---|---|---|
| 1 | structs, arreglos, índices | structs, append, slices |
| 2 | fgets, strtod, strtol, isfinite | bufio.Reader, strconv, math.IsNaN/IsInf |
| 3 | ordenar extremos, arreglo de tramos | sort.Float64s, slices |
| 4 | abs con fabs, bucles | math.Abs, range |
| 5 | fprintf y coordenadas SVG | fmt.Fprintf, os.Create |
| 6 | fopen, fclose, validación por línea | os.Open, Scanner/Reader, error |
| 7 | .h/.c, Makefile, menú | paquete main, go.mod, go test |
