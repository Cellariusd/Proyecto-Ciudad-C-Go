#include "gestion.h"
#include <stdio.h>

/* INTEGRANTE 1: implementar los cuatro contratos.
 * - Validar con validar_edificio() antes de registrar o modificar.
 * - No superar MAX_EDIFICIOS.
 * - Eliminar desplazando los siguientes elementos hacia la izquierda.
 * - Al fallar, conservar la ciudad sin cambios.
 */
Estado registrar_edificio(Ciudad *ciudad, Edificio edificio)
{
    (void)ciudad; (void)edificio;
    /* TODO(1): implementar. */
    return ESTADO_PENDIENTE;
}

Estado modificar_edificio(Ciudad *ciudad, int indice, Edificio nuevo)
{
    (void)ciudad; (void)indice; (void)nuevo;
    /* TODO(1): implementar. */
    return ESTADO_PENDIENTE;
}

Estado eliminar_edificio(Ciudad *ciudad, int indice)
{
    (void)ciudad; (void)indice;
    /* TODO(1): implementar. */
    return ESTADO_PENDIENTE;
}

void listar_edificios(const Ciudad *ciudad)
{
    (void)ciudad;
    puts("[PENDIENTE] Listar edificios: integrante 1");
}
