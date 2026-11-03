#ifndef MODELO_H
#define MODELO_H

/* Contrato compartido. Cambiarlo solo mediante una decisión de equipo/PR. */
#define MAX_EDIFICIOS 100
#define MAX_TRAMOS (2 * MAX_EDIFICIOS + 1)

typedef struct {
    double xi;  /* Abscisa de inicio */
    double xf;  /* Abscisa de fin */
    double h;   /* Altura */
} Edificio;

typedef struct {
    Edificio edificios[MAX_EDIFICIOS];
    int cantidad; /* 0..MAX_EDIFICIOS */
} Ciudad;

typedef struct {
    double inicio;
    double fin;
    double altura; /* 0 si es un espacio vacío interno */
} Tramo;

typedef struct {
    Tramo tramos[MAX_TRAMOS];
    int cantidad; /* 0..MAX_TRAMOS */
} Horizonte;

typedef enum {
    ESTADO_OK = 0,
    ESTADO_PENDIENTE = 1,    /* Módulo todavía no implementado */
    ESTADO_DATOS_INVALIDOS = 2,
    ESTADO_CAPACIDAD = 3,
    ESTADO_INDICE = 4,
    ESTADO_ARCHIVO = 5,
    ESTADO_ERROR_INTERNO = 6
} Estado;

/* Función de infraestructura ya implementada. */
const char *descripcion_estado(Estado estado);

#endif
