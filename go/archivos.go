package main

// INTEGRANTE 6: formato interoperable con C: xi xf h por línea.
func GuardarCiudad(ciudad *Ciudad, ruta string) error {
	_, _ = ciudad, ruta
	// TODO(6): os.Create, bufio.Writer, Flush, Close; comprobar errores.
	return ErrNoImplementado
}

func CargarCiudad(ciudad *Ciudad, ruta string) error {
	_, _ = ciudad, ruta
	// TODO(6): cargar en slice temporal validando todo; commit atómico.
	return ErrNoImplementado
}
