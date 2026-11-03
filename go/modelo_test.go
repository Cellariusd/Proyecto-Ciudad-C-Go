package main

import "testing"

// Solo comprueba infraestructura. Los módulos pendientes AÚN NO están probados.
func TestInfraestructuraInicial(t *testing.T) {
	ciudad := NuevaCiudad()
	if len(ciudad.Edificios) != 0 {
		t.Fatal("ciudad debe comenzar vacia")
	}
	if cap(ciudad.Edificios) < MaxEdificios {
		t.Fatal("capacidad inicial inesperada")
	}
	if MaxTramos < 2*MaxEdificios {
		t.Fatal("limite de tramos insuficiente")
	}
}
