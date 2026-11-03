#ifndef GESTION_H
#define GESTION_H
#include "modelo.h"

/* Propietario: integrante 1. Indices desde 0. ESTADO_OK solo si se realizó el cambio. */
Estado registrar_edificio(Ciudad *ciudad, Edificio edificio);
Estado modificar_edificio(Ciudad *ciudad, int indice, Edificio nuevo);
Estado eliminar_edificio(Ciudad *ciudad, int indice);
void listar_edificios(const Ciudad *ciudad);

#endif
