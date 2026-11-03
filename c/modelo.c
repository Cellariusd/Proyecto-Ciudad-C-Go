#include "modelo.h"

const char *descripcion_estado(Estado estado)
{
    switch (estado) {
        case ESTADO_OK: return "Correcto";
        case ESTADO_PENDIENTE: return "Funcionalidad pendiente de implementar";
        case ESTADO_DATOS_INVALIDOS: return "Datos invalidos";
        case ESTADO_CAPACIDAD: return "Capacidad de la ciudad excedida";
        case ESTADO_INDICE: return "Indice fuera de rango";
        case ESTADO_ARCHIVO: return "Error de archivo";
        case ESTADO_ERROR_INTERNO: return "Error interno";
        default: return "Estado desconocido";
    }
}
