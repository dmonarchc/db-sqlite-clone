# sqlite-clone

Construyendo una base de datos tipo SQLite desde cero en C, como ejercicio de aprendizaje siguiendo el tutorial [Let's Build a Simple Database](https://cstack.github.io/db_tutorial/).

Este proyecto implementa un intérprete de comandos SQL básico (REPL), un sistema de almacenamiento simple y otras estructuras internas que simulan el funcionamiento de SQLite, con el objetivo de aprender:

- Cómo se estructuran los motores de bases de datos
- Cómo funciona el parsing, almacenamiento y ejecución de comandos SQL
- Manejo de memoria, buffers y estructuras de bajo nivel en C

---

## 🔧 Estado actual

🟢 **Parte 01 completada**:  
✔ REPL funcional  
✔ Lectura de comandos desde consola (`read_input`)  
✔ Implementación multiplataforma de `getline()` (con fallback para Windows)  
✔ Estructura de proyecto con separación en módulos  
✔ Documentación y control de versiones limpio

---

## 📁 Estructura del proyecto

```
sqlite-clone/
├── main.c                # Punto de entrada principal
├── utils.c / utils.h     # Funciones de soporte como getline (Windows)
├── doc/                  # Explicaciones teóricas por parte
│   ├── parte01_teoria.txt
│   └── explicacion_utils.txt
├── .gitignore
└── README.md
```

---

## ⚙️ Compilación

Compilar en Windows (usando GCC o MinGW):

```bash
gcc main.c utils.c -o db
```

Compilar en Linux/macOS:

```bash
gcc main.c -o db
```

---

## 🚀 Ejecución

```bash
./db
```

Esto abrirá un REPL donde podrás ingresar comandos como:

```
> .exit
```

(En las siguientes partes se agregarán comandos como `insert`, `select`, etc.)

---

## 📚 Créditos y fuente

Este proyecto sigue la guía de [cstack/db_tutorial](https://cstack.github.io/db_tutorial/).  
Desarrollado como práctica personal por [dmonarchc](https://github.com/dmonarchc).

---

## 📌 Próximos pasos

- [ ] Agregar soporte para comandos `insert` y `select`  
- [ ] Serialización en archivo `.db`  
- [ ] Implementar estructura de páginas (pager y B-trees)  
