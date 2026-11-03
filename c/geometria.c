#include "geometria.h"

Estado calcular_area(const Horizonte *horizonte, double *area)
{
    (void)horizonte; (void)area;
    /* TODO(4): sumar áreas de tramos de h > 0; ciudad vacía -> 0. */
    return ESTADO_PENDIENTE;
}

Estado calcular_perimetro(const Horizonte *horizonte, double *perimetro)
{
    (void)horizonte; (void)perimetro;
    /* TODO(4): NO sumar perímetros de edificios individuales.
     * Contar 2*ancho de cada tramo de altura positiva y los cambios
     * verticales absolutos de altura (incluidas subidas y bajadas a 0).
     */
    return ESTADO_PENDIENTE;
}
