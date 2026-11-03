#ifndef GEOMETRIA_H
#define GEOMETRIA_H
#include "modelo.h"

/* Propietario: integrante 4. No modificar Horizonte.
 * Área: suma (fin - inicio) * altura.
 * Perímetro: horizontales de regiones cubiertas + saltos verticales,
 * incluido 0 al inicio y 0 al final, y huecos entre grupos.
 */
Estado calcular_area(const Horizonte *horizonte, double *area);
Estado calcular_perimetro(const Horizonte *horizonte, double *perimetro);

#endif
