# Pruebas geométricas y de requisitos

El profesor pide probar varios escenarios, no solo el ejemplo. Revisar PDF en `docs/enunciado/`.
**Atención:** el repositorio inicial SOLO prueba compilación e infraestructura. Todavía NO
certifica que los cálculos, validaciones ni gráficos estén implementados.

## Valores de referencia calculados manualmente

| ID | Edificios `(xi,xf,h)` | Horizonte esperado | Área | Perímetro |
|---|---|---|---:|---:|
| UNO | `(0,4,3)` | `(0,4,3)` | 12 | 14 |
| TOCAN | `(0,2,3); (2,5,3)` | `(0,5,3)` | 15 | 16 |
| SUPERPUESTOS | `(0,4,3); (2,6,5)` | `(0,2,3); (2,6,5)` | 26 | 22 |
| SEPARADOS | `(0,2,3); (4,6,2)` | `(0,2,3); (2,4,0); (4,6,2)` | 10 | 18 |
| OFICIAL | `(0,4,7); (4,7,4); (7,12,5); (8,17,2); (19,21,10)` | `(0,4,7); (4,7,4); (7,12,5); (12,17,2); (17,19,0); (19,21,10)` | 95 | 74 |

## Casos adicionales de aceptación

- Edificios iguales o totalmente duplicados: contar unión una sola vez.
- Edificio completamente oculto y parcialmente oculto.
- Varios edificios con el mismo xi o xf.
- Fin e inicio compartidos en la misma coordenada.
- Cambios de altura sucesivos, altos y bajos.
- 3 o más componentes separados.
- Ciudad vacía y límite de MAX_EDIFICIOS.
- xi >= xf, h <= 0, NaN/infinito, texto inválido.
- Guardar, terminar, ejecutar, cargar, recalcular y comparar.
- Archivo inexistente, línea incompleta y error de escritura.
- Gráficos de TODOS los edificios y del contorno, con ejes.

## Cuándo activar pruebas algorítmicas en CI

El integrante 7 creará `c/tests/test_geometria.c`, etc., y equivalentes
`go/*_test.go`. Deben FALLAR cuando una implementación está mal y ser incluidos
en el job CI después de desarrollar el módulo correspondiente.
No marcar un módulo como listo solo porque el esqueleto compila.

## Informe

Por algoritmo documentar: objetivo, parámetros, entradas/salidas, precondiciones,
idea, pseudocódigo, trazado manual, complejidad, casos límite, pruebas y limitaciones.
