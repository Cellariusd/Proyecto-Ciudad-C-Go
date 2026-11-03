package main

import "errors"

// Contratos compartidos. El Go idiomático usa slices, a diferencia del
// arreglo fijo + cantidad en C. El máximo se controla explícitamente.
const MaxEdificios = 100
const MaxTramos = 2*MaxEdificios + 1

var ErrNoImplementado = errors.New("funcionalidad pendiente de implementar")
var ErrDatosInvalidos = errors.New("datos invalidos")
var ErrCapacidad = errors.New("capacidad excedida")
var ErrIndice = errors.New("indice fuera de rango")
var ErrArchivo = errors.New("error de archivo")

type Edificio struct {
	Xi float64
	Xf float64
	H  float64
}

type Ciudad struct {
	Edificios []Edificio
}

type Tramo struct {
	Inicio float64
	Fin    float64
	Altura float64
}

type Horizonte struct {
	Tramos []Tramo
}

func NuevaCiudad() Ciudad {
	return Ciudad{Edificios: make([]Edificio, 0, MaxEdificios)}
}
