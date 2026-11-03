package main

import "bufio"

// INTEGRANTE 2: validar también números no finitos (math.IsNaN/IsInf).
func ValidarEdificio(e Edificio) error {
	_ = e
	// TODO(2): Xi < Xf, H > 0, números finitos y xi>=0 si acuerdan.
	return ErrNoImplementado
}

func LeerEdificio(lector *bufio.Reader) (Edificio, error) {
	_ = lector
	// TODO(2): lectura segura con bufio y strconv.ParseFloat.
	return Edificio{}, ErrNoImplementado
}

func LeerEntero(lector *bufio.Reader, mensaje string) (int, error) {
	_, _ = lector, mensaje
	// TODO(2): entrada de entero segura con strconv.Atoi.
	return 0, ErrNoImplementado
}
