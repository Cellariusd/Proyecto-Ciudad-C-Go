#ifndef HORIZONTE_H
#define HORIZONTE_H
#include "modelo.h"

/* Propietario: integrante 3.
 * Devuelve tramos de ancho positivo y fusiona adyacentes de igual altura.
 * Incluye altura 0 en huecos INTERNOS. No inventa huecos fuera de la ciudad.
 * En ciudad vacía: devolver horizonte vacío (ESTADO_OK).
 */
Estado calcular_horizonte(const Ciudad *ciudad, Horizonte *resultado);

#endif
