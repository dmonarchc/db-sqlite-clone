#ifndef INPUT_BUFFER_H
#define INPUT_BUFFER_H

#include "utils.h" // Asegura que ssize_t esté definido en Windows
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char *buffer;           // Apunta al texto ingresado por el usuario
    size_t buffer_length;   // Tamaño total reservado para buffer
    ssize_t input_length;   // Cantidad de caracteres ingresados
} InputBuffer;

InputBuffer* new_input_buffer(void);

void read_input(InputBuffer* input_buffer);
void close_input_buffer(InputBuffer* input_buffer);

#endif // INPUT_BUFFER_H