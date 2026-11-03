# Contratos de funciones del equipo

**Este documento es el acuerdo más importante para trabajar en paralelo.**
La declaración real está en los `.h` de `c/` y en las firmas Go correspondientes.

## Datos compartidos
- C: `Edificio`, `Ciudad`, `Tramo`, `Horizonte`, `Estado`, `MAX_EDIFICIOS=100`.
- Go: `Edificio`, `Ciudad{Edificios []Edificio}`, `Tramo`, `Horizonte{Tramos []Tramo}`.
- Coordenadas y alturas: `double` / `float64`.
- Unidades: si `xi`, `xf`, `h` usan unidades de longitud, el área usa unidades².
- Indices internos desde 0. La interfaz puede mostrarlos desde 1 solo si realiza conversión.
- Archivo interoperable: una línea `xi xf h`, usando punto decimal y sin encabezados.
- C: `ESTADO_OK` confirma éxito; `ESTADO_PENDIENTE` NO es éxito.
- Go: `nil` confirma éxito; `ErrNoImplementado` NO es éxito.

## Módulo 1 — Gestión
- Registrar: añade un edificio válido solo si hay espacio; incrementa cantidad.
- Modificar: sustituye un edificio indexado por uno válido.
- Eliminar: desplaza a la izquierda los posteriores y reduce cantidad.
- Listar: presenta el estado actual sin modificarlo.
- Garantía: ante un fallo NO se modifica la ciudad.

## Módulo 2 — Validación
- Validar: `xi < xf`, `h > 0`, valores numéricos finitos; decidir `xi >= 0`.
- Leer edificio: recoge exactamente tres números; no admite texto sobrante.
- Leer entero: controla errores, límites y caracteres de más.
- No se ignoran errores de lectura ni de conversión.

## Módulo 3 — Horizonte
- Entrada: ciudad válida.
- Salida: tramos `(inicio, fin, altura)` en orden ascendente, de ancho > 0.
- En cada intervalo usar la altura MÁXIMA, nunca sumar alturas.
- Fusionar segmentos contiguos con misma altura.
- Preservar espacios vacíos INTERNOS como tramos de altura 0.
- Vacío -> horizonte con 0 tramos y éxito.
- Garantía: en caso de error, no publicar un horizonte parcialmente calculado.

## Módulo 4 — Geometría
- Área: sumar ancho * altura para cada tramo del horizonte.
- Perímetro: 2 * suma de anchos de tramos con altura > 0 más
  suma de cambios verticales absolutos, incluyendo transiciones desde/hacia altura 0.
- Vacío -> área=0 y perímetro=0.
- No sumar perímetros individuales de edificios.

## Módulo 5 — Gráficos
- Dos salidas separadas, `edificios.svg` y `horizonte.svg`.
- Dibujar ejes, escalas, etiquetas, todos los rectángulos y contorno.
- Acordar con el docente si se admite SVG externo; si exige ventana, cambiar interfaz por acuerdo.
- No anunciar archivo generado si la escritura falló.

## Módulo 6 — Archivos
- Guardar: serializar solo edificios, nunca área/horizonte precalculados.
- Cargar: validar todo en ciudad temporal y sustituir solo al terminar exitosamente.
- Archivos inexistentes, vacíos, malformados o grandes: reportar sin corromper estado.
- Detallar la decisión sobre permitir guardar/cargar ciudades vacías.

## Módulo 7 — Menú y pruebas
- Se encarga de conectar dependencias, mensajes, validaciones de estado,
  recálculo después de altas, bajas, modificación y carga.
- Garantizar que errores `ESTADO_PENDIENTE`/`ErrNoImplementado` no parezcan éxito.
- Probar versiones C y Go con las MISMAS ciudades.

## Cambios de interfaces
1. Abrir Issue de propuesta.
2. Documentar por qué es necesario el cambio.
3. Obtener acuerdo de responsables afectados.
4. Integrar primero el contrato y después adaptar implementaciones.
