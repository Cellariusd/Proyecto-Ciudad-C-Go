package main

import "fmt"

// INTEGRANTE 1: portar a Go el módulo gestion.c una vez validado en C.
// len(ciudad.Edificios) reemplaza el campo cantidad de C.
func RegistrarEdificio(ciudad *Ciudad, edificio Edificio) error {
	_, _ = ciudad, edificio
	// TODO(1): validar, capacidad MaxEdificios, append.
	return ErrNoImplementado
}

func ModificarEdificio(ciudad *Ciudad, indice int, nuevo Edificio) error {
	_, _, _ = ciudad, indice, nuevo
	// TODO(1): validar antes de reemplazar.
	return ErrNoImplementado
}

func EliminarEdificio(ciudad *Ciudad, indice int) error {
	_, _ = ciudad, indice
	// TODO(1): slices, conservar orden.
	return ErrNoImplementado
}

func ListarEdificios(ciudad *Ciudad) {
	_ = ciudad
	fmt.Println("[PENDIENTE] Listar edificios: integrante 1")
}
