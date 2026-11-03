#include "graficos.h"

Estado exportar_svg_edificios(const Ciudad *ciudad, const char *ruta)
{
    (void)ciudad; (void)ruta;
    /* TODO(5): generar SVG con TODOS los rectángulos,
     * ejes X/Y, escala proporcional y etiquetas legibles.
     * Confirmar con docente si acepta SVG externo.
     */
    return ESTADO_PENDIENTE;
}

Estado exportar_svg_horizonte(const Horizonte *horizonte, const char *ruta)
{
    (void)horizonte; (void)ruta;
    /* TODO(5): dibujar contorno por tramos, cambios de altura y huecos. */
    return ESTADO_PENDIENTE;
}
