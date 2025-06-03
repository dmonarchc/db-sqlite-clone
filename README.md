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

🟢 Parte 05 completada:  
✔ Implementación del sistema de paginación (`Pager`)  
✔ Incorporación del archivo físico `dbfile.db` para persistencia de datos  
✔ Lectura y escritura de páginas con `get_page` y `pager_flush`  
✔ Inclusión de lógica para cerrar y guardar datos (`db_close`)  
✔ Soporte de hasta 100 páginas en memoria  
✔ Separación clara entre memoria y almacenamiento en disco  

🟢 Parte 06 completada:  
✔ Abstracción de la posición de lectura/escritura a través del `Cursor`  
✔ Definición de operaciones `table_start()`, `table_end()` y `cursor_advance()`  
✔ Sustitución de la lógica de posicionamiento manual por el uso de `Cursor`  
✔ Iteración simplificada de filas con un cursor desde `execute_select()`  
✔ Escritura de datos utilizando `cursor_value(cursor)`

🟢 Parte 07 completada:  
✔ Introducción del encabezado de página (`page header`) con `num_rows` persistente  
✔ Cálculo de `num_rows` a partir del encabezado del archivo si existe  
✔ Escritura de `num_rows` en disco desde `db_close()`  
✔ Carga de `num_rows` al abrir un archivo existente  
✔ Persistencia completa del estado de la tabla en el archivo binario

🟢 Parte 08 completada:  
✔ Se implementa la función `leaf_node_find` que realiza una búsqueda binaria dentro del nodo hoja para localizar la posición exacta de una clave (key).  
✔ Esta función devuelve un cursor apuntando a la celda donde la clave se encuentra o donde debería insertarse, facilitando inserciones y búsquedas eficientes.  
✔ Se maneja correctamente el caso donde la clave no existe, posicionando el cursor en el lugar adecuado para mantener el orden.  
✔ Esta etapa sienta las bases para operaciones de inserción y búsqueda rápidas dentro del nodo hoja, incrementando la eficiencia del motor.  

🟢 Parte 09 completada:  
✔ Se desarrolla la función `execute_insert` que coordina la inserción de una fila nueva en la base de datos.  
✔ La inserción se realiza usando el cursor obtenido por `leaf_node_find`, validando previamente que no existan claves duplicadas para evitar inconsistencias.  
✔ Cuando la posición de inserción está en medio del nodo hoja, se desplazan las celdas existentes para abrir espacio y mantener el orden.  
✔ Se realiza la serialización del `Row` y su almacenamiento en la posición adecuada dentro del nodo hoja, persistiendo los datos correctamente.  
✔ Se corrige la aritmética de punteros y el manejo de offsets para asegurar portabilidad y evitar corrupción de datos, fundamental para la integridad de la base de datos.  

---

## ⚙ Compilación

```bash
make
```

Esto generará el ejecutable `db` en la carpeta `build/`.

---

## 🧪 Ejecución de pruebas


# Pruebas básicas sin validación automática
```bash
./build/db < test/test_script.txt

```

# Pruebas con rspec (recomendado)
```bash
rspec
```
---

## 📌 Notas

Este proyecto es educativo y está basado en la guía de construcción de una base de datos paso a paso.