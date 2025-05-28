CC = gcc
CFLAGS = -std=c99 -Wall -Iinclude
LDFLAGS = -static

# Listado manual de fuentes
SRC = \
	src/main.c \
	src/core/inputbuffer.c \
	src/core/meta_command.c \
	src/core/utils.c \
	src/parser/statement.c \
	src/backend/row.c \
	src/backend/table.c \
	src/backend/pager.c \
	src/backend/cursor.c

# Carpeta de salida
BUILD_DIR = build
TARGET = $(BUILD_DIR)/db

# Convertir archivos fuente a objetos
OBJS = $(SRC:.c=.o)
OBJS := $(patsubst src/%, $(BUILD_DIR)/%, $(OBJS))

# Regla por defecto
all: $(TARGET)

# Crear ejecutable
$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

# Compilar cada .c a .o
$(BUILD_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar
clean:
	rm -rf $(BUILD_DIR) dbfile.db mydb.db

# Ejecutar
run: all
	./build/db mydb.db

.PHONY: all clean run
