#include "horizonte.h"

Estado calcular_horizonte(const Ciudad *ciudad, Horizonte *resultado)
{
    (void)ciudad; (void)resultado;
    /* TODO(3):
     * 1) Extraer xi y xf en arreglo temporal (hasta 2*n).
     * 2) Ordenar y quitar extremos duplicados.
     * 3) Para cada par consecutivo, hallar la máxima h de edificios
     *    que cubren TODO el intervalo.
     * 4) Fusionar intervalos adyacentes con la misma altura.
     * 5) Incluir huecos de h=0 entre grupos de edificios.
     * 6) Respetar MAX_TRAMOS y no escribir fuera del arreglo.
     */
    return ESTADO_PENDIENTE;
}
