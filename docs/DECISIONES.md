# Decisiones que el equipo debe cerrar ANTES de programar

Estado inicial: propuestas de arquitectura, no reglas literales del profesor.

| Decisión | Propuesta inicial | Aprobada por equipo |
|---|---|---|
| Tipo de coordenadas y altura | `double` / `float64` | [ ] |
| Máximo de edificios | 100 | [ ] |
| Coordenada de inicio | `xi >= 0` por eje X positivo | [ ] |
| Edificios duplicados | Permitirlos; no duplicar área | [ ] |
| Ciudad vacía al guardar/cargar | Definir convención, no carga parcial | [ ] |
| Gráficos | SVG externos con ejes/escala | [ ] confirmar con docente |
| Formato de archivo | `xi xf h` en texto | [ ] |
| Indices en interfaz | Mostrar 1..n o 0..n-1; documentar | [ ] |
| Flujo GitHub | feature -> develop -> main | [ ] |

Si cambian una decisión, actualizar contratos, pruebas, pseudocódigo y código de ambos lenguajes.
