# GitHub: crear repositorio, invitar a los 7 integrantes y trabajar con ramas

## A. Publicar por primera vez (coordinador)

1. Descomprimir el ZIP entregado, renombrar carpeta a `proyecto-ciudad` si desean.
2. Crear un repositorio VACÍO en GitHub, por ejemplo `proyecto-ciudad-c-go`.
   Si van a usar comandos Git para el primer push, NO seleccionar README/licencia inicial.
3. Abrir terminal en la carpeta descomprimida:

```bash
git init -b main
git add .
git commit -m "Inicializa arquitectura modular de C y Go"
git remote add origin https://github.com/TU-USUARIO/proyecto-ciudad-c-go.git
git push -u origin main
```

4. Crear la rama de integración compartida:

```bash
git switch -c develop
git push -u origin develop
```

5. En GitHub: Settings > Collaborators / Collaborators and teams (según tipo de cuenta),
   invitar a los 6 compañeros restantes por su nombre de usuario.
6. En Settings > Branches / Rulesets: proteger `main` y `develop` para que
   los cambios lleguen mediante Pull Requests. Exigir CI cuando esté disponible.
7. En Settings > General: si es posible, ajustar `develop` como rama predeterminada
   mientras desarrollan; `main` queda como última versión estable.

Alternativa: puede publicarse mediante la interfaz web, pero no subir ZIP cerrado;
GitHub necesita VER los archivos y sus carpetas.

## B. Cada integrante: empezar una tarea desde develop

```bash
git clone https://github.com/TU-USUARIO/proyecto-ciudad-c-go.git
cd proyecto-ciudad-c-go
git switch develop
git pull origin develop
git switch -c feature/c-horizonte
# Editar solamente su módulo y sus pruebas.
git add c/horizonte.c c/tests/
git commit -m "Calcula tramos del horizonte"
git push -u origin feature/c-horizonte
```

En GitHub abrir Pull Request con destino `develop`.
Usar plantilla `.github/PULL_REQUEST_TEMPLATE.md` y enlazar un Issue.

## C. Revisar e integrar

1. Un compañero revisa código y casos de prueba.
2. GitHub Actions verifica compilación (NO valida todavía todos los algoritmos).
3. Integrar PR en `develop` si cumple contrato.
4. Cuando la versión esté terminada y probada, PR de `develop` a `main`.

## D. Al iniciar una nueva tarea

No continuar desarrollando sobre la rama antigua después de fusionarla:

```bash
git switch develop
git pull origin develop
git switch -c feature/go-horizonte
```

## E. Comandos importantes

- `git status`: archivos cambiados.
- `git diff`: qué líneas cambiaste.
- `git log --oneline --graph --all`: historial de ramas.
- `git branch -a`: ramas locales y remotas.
- `git pull origin develop`: traer cambios revisados.

**Atención:** `main.c` no es suficiente para integrar; los contratos de los `.h`
y tipos de `modelo.h` deben mantenerse compatibles.
