#include "archivos.h"

Estado guardar_ciudad(const Ciudad *ciudad, const char *ruta)
{
    (void)ciudad; (void)ruta;
    /* TODO(6): fopen, fprintf, verificar errores de escritura y fclose.
     * Una línea por edificio: xi xf h.
     */
    return ESTADO_PENDIENTE;
}

Estado cargar_ciudad(Ciudad *ciudad, const char *ruta)
{
    (void)ciudad; (void)ruta;
    /* TODO(6): fopen, fgets, strtod/lectura validada, fclose.
     * Leer todo primero en Ciudad temporal; si falla cualquier línea,
     * conservar la ciudad previa intacta. Manejar archivo vacío.
     */
    return ESTADO_PENDIENTE;
}
