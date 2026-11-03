#include "validacion.h"

Estado validar_edificio(Edificio edificio)
{
    (void)edificio;
    /* TODO(2): usar condiciones, isfinite() de math.h y acuerdos del equipo. */
    return ESTADO_PENDIENTE;
}

Estado leer_edificio(Edificio *salida)
{
    (void)salida;
    /* TODO(2): leer 3 números de forma segura con fgets + strtod.
     * Llamar a validar_edificio antes de devolver ESTADO_OK.
     */
    return ESTADO_PENDIENTE;
}

Estado leer_entero(const char *mensaje, int *salida)
{
    (void)mensaje; (void)salida;
    /* TODO(2): entrada segura con fgets + strtol, sin basura al final. */
    return ESTADO_PENDIENTE;
}
