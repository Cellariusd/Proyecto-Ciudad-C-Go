/* Esqueleto del integrante 7. Esta versión compila, pero los módulos
 * retornan ESTADO_PENDIENTE hasta que el equipo los implemente.
 * No confundir "compila" con "funcionalidad terminada".
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <limits.h>

#include "modelo.h"
#include "gestion.h"
#include "validacion.h"
#include "horizonte.h"
#include "geometria.h"
#include "graficos.h"
#include "archivos.h"

static void informar(Estado resultado)
{
    printf("Estado: %s\n", descripcion_estado(resultado));
}

static void mostrar_menu(void)
{
    puts("\n=== CIUDAD: Proyecto Programacion I (C) ===");
    puts("1. Registrar edificio");
    puts("2. Listar edificios");
    puts("3. Modificar edificio");
    puts("4. Eliminar edificio");
    puts("5. Calcular y mostrar horizonte");
    puts("6. Mostrar area y perimetro");
    puts("7. Exportar graficos SVG");
    puts("8. Guardar ciudad en ciudad.txt");
    puts("9. Cargar ciudad desde ciudad.txt");
    puts("0. Salir");
    printf("Opcion: ");
}

/* Solo infraestructura del menú; NO sustituye leer_entero() del módulo 2. */
static int opcion_menu(void)
{
    char linea[64];
    char *fin = NULL;
    long valor;
    if (fgets(linea, sizeof linea, stdin) == NULL) return 0;
    errno = 0;
    valor = strtol(linea, &fin, 10);
    if (fin == linea || errno != 0 || valor < INT_MIN || valor > INT_MAX)
        return -1;
    while (*fin != '\0' && isspace((unsigned char)*fin)) fin++;
    if (*fin != '\0') return -1;
    return (int)valor;
}

static void mostrar_horizonte(const Horizonte *h)
{
    int i;
    if (h->cantidad == 0) { puts("No hay tramos."); return; }
    for (i = 0; i < h->cantidad; i++) {
        Tramo t = h->tramos[i];
        printf("(%.2f, %.2f, %.2f)\n", t.inicio, t.fin, t.altura);
    }
}

static void resumen(const Ciudad *ciudad)
{
    Horizonte h = {0};
    double area = 0.0, perimetro = 0.0;
    Estado e = calcular_horizonte(ciudad, &h);
    if (e != ESTADO_OK) { informar(e); return; }
    mostrar_horizonte(&h);
    e = calcular_area(&h, &area);
    if (e != ESTADO_OK) { informar(e); return; }
    e = calcular_perimetro(&h, &perimetro);
    if (e != ESTADO_OK) { informar(e); return; }
    printf("Area: %.2f u^2 | Perimetro: %.2f u\n", area, perimetro);
}

int main(void)
{
    Ciudad ciudad = {0};
    int cambios_sin_guardar = 0;
    for (;;) {
        int opcion;
        mostrar_menu();
        opcion = opcion_menu();
        switch (opcion) {
            case 0:
                if (cambios_sin_guardar)
                    puts("Aviso: existen cambios no guardados.");
                return 0;
            case 1: {
                Edificio e = {0};
                Estado r = leer_edificio(&e);
                if (r == ESTADO_OK) r = registrar_edificio(&ciudad, e);
                informar(r);
                if (r == ESTADO_OK) { cambios_sin_guardar = 1; resumen(&ciudad); }
                break;
            }
            case 2: listar_edificios(&ciudad); break;
            case 3: {
                int indice = 0;
                Edificio nuevo = {0};
                Estado r = leer_entero("Indice a modificar (desde 0): ", &indice);
                if (r == ESTADO_OK) r = leer_edificio(&nuevo);
                if (r == ESTADO_OK) r = modificar_edificio(&ciudad, indice, nuevo);
                informar(r);
                if (r == ESTADO_OK) { cambios_sin_guardar = 1; resumen(&ciudad); }
                break;
            }
            case 4: {
                int indice = 0;
                Estado r = leer_entero("Indice a eliminar (desde 0): ", &indice);
                if (r == ESTADO_OK) r = eliminar_edificio(&ciudad, indice);
                informar(r);
                if (r == ESTADO_OK) { cambios_sin_guardar = 1; resumen(&ciudad); }
                break;
            }
            case 5: case 6: resumen(&ciudad); break;
            case 7: {
                Horizonte h = {0};
                Estado r = exportar_svg_edificios(&ciudad, "edificios.svg");
                printf("Edificios SVG: "); informar(r);
                r = calcular_horizonte(&ciudad, &h);
                if (r == ESTADO_OK) r = exportar_svg_horizonte(&h, "horizonte.svg");
                printf("Horizonte SVG: "); informar(r);
                break;
            }
            case 8: {
                Estado r = guardar_ciudad(&ciudad, "ciudad.txt");
                informar(r);
                if (r == ESTADO_OK) cambios_sin_guardar = 0;
                break;
            }
            case 9: {
                Estado r = cargar_ciudad(&ciudad, "ciudad.txt");
                informar(r);
                if (r == ESTADO_OK) { cambios_sin_guardar = 0; resumen(&ciudad); }
                break;
            }
            default: puts("Opcion invalida.");
        }
    }
}
