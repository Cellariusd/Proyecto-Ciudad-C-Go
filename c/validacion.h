#ifndef VALIDACION_H
#define VALIDACION_H
#include "modelo.h"

/* Propietario: integrante 2.
 * Validar: xi < xf, h > 0, números finitos; decidir/documentar xi >= 0.
 * Lecturas: evitar aceptar texto no numérico o líneas incompletas.
 */
Estado validar_edificio(Edificio edificio);
Estado leer_edificio(Edificio *salida);
Estado leer_entero(const char *mensaje, int *salida);

#endif
