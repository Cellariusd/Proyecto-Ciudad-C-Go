#ifndef GRAFICOS_H
#define GRAFICOS_H
#include "modelo.h"

/* Propietario: integrante 5. Estrategia candidata: generar SVG. */
Estado exportar_svg_edificios(const Ciudad *ciudad, const char *ruta);
Estado exportar_svg_horizonte(const Horizonte *horizonte, const char *ruta);

#endif
