#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>   // para tolower
#include <stddef.h>  // para size_t

#ifdef __linux__
  #include <sys/types.h> // ssize_t solo en Linux
#endif

void normalize_input(char* str);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

#endif // UTILS_H