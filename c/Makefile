CC ?= cc
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -Wshadow -Wconversion -O2
SOURCES = main.c modelo.c gestion.c validacion.c horizonte.c geometria.c graficos.c archivos.c
MODULES = modelo.c gestion.c validacion.c horizonte.c geometria.c graficos.c archivos.c

.PHONY: all clean test
all: build/ciudad

build:
	mkdir -p build

build/ciudad: $(SOURCES) | build
	$(CC) $(CFLAGS) $(SOURCES) -o $@ -lm

build/test_modelo: tests/test_modelo.c modelo.c | build
	$(CC) $(CFLAGS) -I. tests/test_modelo.c modelo.c -o $@

test: build/test_modelo
	./build/test_modelo

clean:
	rm -rf build
