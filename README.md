# 🗄 sqlite-clone

Repositorio que implementa una base de datos relacional tipo SQLite desde cero en C, siguiendo el proyecto [Let's Build a Simple Database](https://cstack.github.io/db_tutorial/).

---

## 📁 Estructura del proyecto

```
db-sqlite-clone/
├── Makefile
├── README.md
├── build/
│   └── (archivos binarios)
├── src/
│   ├── constants.h
│   ├── input_buffer.c
│   ├── input_buffer.h
│   ├── main.c
│   ├── row.c
│   ├── row.h
│   ├── statement.c
│   ├── statement.h
│   ├── table.c
│   └── table.h
└── test/
    └── test_script.txt
```

---

## ✅ Progreso por partes

🟢 Parte 01 completada:
✔ REPL funcional  
✔ Lectura de comandos desde consola (`read_input`)  
✔ Implementación multiplataforma de `getline()` (con fallback para Windows)  
✔ Estructura de proyecto con separación en módulos  
✔ Documentación y control de versiones limpio  

🟢 Parte 02 completada:
✔ Introducción de estructuras `MetaCommand` y `Statement`  
✔ Implementación del compilador de sentencias SQL simples  
✔ Ejecución básica de `insert` y `select` desde memoria directa  
✔ Comienzo de la máquina virtual con funciones como `execute_insert()` y `execute_select()`  

🟢 Parte 03 completada:
✔ Implementación de la estructura `Row`  
✔ Serialización y deserialización de filas  
✔ Introducción del concepto de página (4KB) y paginación en memoria  
✔ Almacenamiento de filas serializadas en un arreglo de páginas  
✔ Capacidad máxima definida por número de páginas y filas por página  

🟢 Parte 04 completada:
✔ Pruebas automatizadas con scripts (`test_script.txt`)  
✔ Validaciones de longitud en `username` y `email`  
✔ Manejo de errores por tabla llena o entradas inválidas  
✔ Ejecución de pruebas con: `./build/db < test/test_script.txt`  
✔ Corrección de errores por terminadores nulos faltantes en strings (`\0`)  

---

## ⚙ Compilación

```bash
make
```

Esto generará el ejecutable `db` en la carpeta `build/`.

---

## 🧪 Ejecución de pruebas

```bash
./build/db < test/test_script.txt
```

---

## 📌 Notas

Este proyecto es educativo y está basado en la guía de construcción de una base de datos paso a paso.