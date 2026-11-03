// Esqueleto del integrante 7: compila sin afirmar que los módulos estén terminados.
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func menu() {
	fmt.Println("\n=== CIUDAD: Proyecto Programacion I (Go) ===")
	fmt.Println("1. Registrar edificio")
	fmt.Println("2. Listar edificios")
	fmt.Println("3. Modificar edificio")
	fmt.Println("4. Eliminar edificio")
	fmt.Println("5. Calcular y mostrar horizonte")
	fmt.Println("6. Mostrar area y perimetro")
	fmt.Println("7. Exportar graficos SVG")
	fmt.Println("8. Guardar ciudad en ciudad.txt")
	fmt.Println("9. Cargar ciudad desde ciudad.txt")
	fmt.Println("0. Salir")
	fmt.Print("Opcion: ")
}

func informar(err error) {
	if err != nil {
		fmt.Println("Estado:", err)
	} else {
		fmt.Println("Estado: Correcto")
	}
}

func resumen(ciudad *Ciudad) {
	h, err := CalcularHorizonte(ciudad)
	if err != nil {
		informar(err)
		return
	}
	if len(h.Tramos) == 0 {
		fmt.Println("No hay tramos.")
	}
	for _, t := range h.Tramos {
		fmt.Printf("(%.2f, %.2f, %.2f)\n", t.Inicio, t.Fin, t.Altura)
	}
	a, err := CalcularArea(&h)
	if err != nil {
		informar(err)
		return
	}
	p, err := CalcularPerimetro(&h)
	if err != nil {
		informar(err)
		return
	}
	fmt.Printf("Area: %.2f u^2 | Perimetro: %.2f u\n", a, p)
}

func main() {
	ciudad := NuevaCiudad()
	cambiosSinGuardar := false
	lector := bufio.NewReader(os.Stdin)
	for {
		menu()
		linea, err := lector.ReadString('\n')
		if err != nil && len(linea) == 0 {
			return
		}
		opcion, err := strconv.Atoi(strings.TrimSpace(linea))
		if err != nil {
			fmt.Println("Opcion invalida.")
			continue
		}
		switch opcion {
		case 0:
			if cambiosSinGuardar {
				fmt.Println("Aviso: existen cambios no guardados.")
			}
			return
		case 1:
			nuevo, err := LeerEdificio(lector)
			if err == nil {
				err = RegistrarEdificio(&ciudad, nuevo)
			}
			informar(err)
			if err == nil {
				cambiosSinGuardar = true
				resumen(&ciudad)
			}
		case 2:
			ListarEdificios(&ciudad)
		case 3:
			indice, err := LeerEntero(lector, "Indice a modificar (desde 0): ")
			var nuevo Edificio
			if err == nil {
				nuevo, err = LeerEdificio(lector)
			}
			if err == nil {
				err = ModificarEdificio(&ciudad, indice, nuevo)
			}
			informar(err)
			if err == nil {
				cambiosSinGuardar = true
				resumen(&ciudad)
			}
		case 4:
			indice, err := LeerEntero(lector, "Indice a eliminar (desde 0): ")
			if err == nil {
				err = EliminarEdificio(&ciudad, indice)
			}
			informar(err)
			if err == nil {
				cambiosSinGuardar = true
				resumen(&ciudad)
			}
		case 5, 6:
			resumen(&ciudad)
		case 7:
			err := ExportarSVGEdificios(&ciudad, "edificios.svg")
			fmt.Print("Edificios SVG: ")
			informar(err)
			h, err := CalcularHorizonte(&ciudad)
			if err == nil {
				err = ExportarSVGHorizonte(&h, "horizonte.svg")
			}
			fmt.Print("Horizonte SVG: ")
			informar(err)
		case 8:
			err := GuardarCiudad(&ciudad, "ciudad.txt")
			informar(err)
			if err == nil {
				cambiosSinGuardar = false
			}
		case 9:
			err := CargarCiudad(&ciudad, "ciudad.txt")
			informar(err)
			if err == nil {
				cambiosSinGuardar = false
				resumen(&ciudad)
			}
		default:
			fmt.Println("Opcion invalida.")
		}
	}
}
