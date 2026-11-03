/* Prueba inicial de INFRAESTRUCTURA, no comprueba algoritmos pendientes. */
#include <assert.h>
#include <stdio.h>
#include "modelo.h"

int main(void)
{
    Ciudad c = {0};
    Horizonte h = {0};
    Edificio e = {0.0, 4.0, 7.0};
    assert(c.cantidad == 0);
    assert(h.cantidad == 0);
    assert(MAX_TRAMOS >= 2 * MAX_EDIFICIOS);
    c.edificios[0] = e;
    c.cantidad = 1;
    assert(c.edificios[0].xf == 4.0);
    assert(ESTADO_OK != ESTADO_PENDIENTE);
    puts("OK: infraestructura de modelos C. Algoritmos aun pendientes.");
    return 0;
}
