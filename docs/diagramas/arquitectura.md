# Arquitectura modular del programa

GitHub puede representar automáticamente este diagrama Mermaid.

```mermaid
flowchart TD
    UI[main: menu e integracion\nIntegrante 7] --> V[Validacion y lectura\nIntegrante 2]
    UI --> G[Gestion de edificios\nIntegrante 1]
    UI --> H[Calculo de horizonte\nIntegrante 3]
    UI --> A[Geometria: area y perimetro\nIntegrante 4]
    UI --> F[Graficos: edificios y horizonte\nIntegrante 5]
    UI --> P[Guardar y cargar\nIntegrante 6]
    V --> G
    G --> C[(Ciudad)]
    P <--> C
    C --> H
    H --> T[(Horizonte)]
    T --> A
    C --> F
    T --> F
```

## Flujo en GitHub

```mermaid
flowchart LR
    D[develop] -->|crear rama por tarea| F[feature/c-* o feature/go-*]
    F -->|commit y push| PR[Pull Request]
    PR -->|revisar y probar| D
    D -->|version completa y validada| M[main estable]
```

**Nota:** `main` nunca se edita directamente. Los integrantes deben crear ramas DESDE `develop`,
abrir PR a `develop` y reservar los PR `develop -> main` para entregas integradas.
