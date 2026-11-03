# Hoja de ruta: trasladar C a Go

No traducir línea por línea sin entender el algoritmo. Reescribir cada contrato
de C de manera idiomática en Go y repetir exactamente los mismos casos.

| C | Go | Diferencia importante |
|---|---|---|
| `typedef struct { ... } Edificio;` | `type Edificio struct {...}` | campos con mayúscula si se exportan |
| `Edificio edificios[100]` | `[]Edificio` | `len` y `cap`; controlar máximo manualmente |
| `int cantidad` | `len(ciudad.Edificios)` | evita duplicar contador |
| `void`, retornos `Estado` | `error`, `(valor, error)` | Go suele retornar errores, no códigos |
| `&ciudad`, `*ciudad` | `&ciudad`, `*Ciudad` | sin aritmética de punteros |
| `for (...)` | `for` / `range` | Go no tiene `while` separado |
| `qsort` | `sort.Float64s` / `sort.Slice` | ordenamiento en stdlib |
| `fopen`/`fprintf`/`fclose` | `os.Create`/`fmt.Fprintf`/`Close` | comprobar errores |
| `fgets`, `strtod` | `bufio.Reader`, `strconv.ParseFloat` | parseo explícito |
| `isfinite` | `math.IsInf` y `math.IsNaN` | verificar ambos casos |
| `fabs` | `math.Abs` | diferencias absolutas |

## Etapas
1. Ejecutar y explicar el módulo en C.
2. Escribir sus entradas, salidas y casos de prueba en lenguaje natural.
3. Estudiar únicamente las herramientas Go necesarias para ese módulo.
4. Implementar el mismo contrato en Go usando las estructuras compartidas.
5. Probarlo con `go test ./...` y los casos oficiales.
6. Abrir PR a `develop` y comparar sus resultados con C.

Go usa `go/` como módulo independiente, con un `go.mod` inicial. Para el curso
se dejó todo en un único paquete `main` a fin de reducir complejidad.
