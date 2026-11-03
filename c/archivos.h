#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include "modelo.h"

/* Propietario: integrante 6.
 * Formato por línea: xi xf h\n
 * Cargar atómicamente: no sustituir datos si cualquier línea es inválida.
 */
Estado guardar_ciudad(const Ciudad *ciudad, const char *ruta);
Estado cargar_ciudad(Ciudad *ciudad, const char *ruta);

#endif
