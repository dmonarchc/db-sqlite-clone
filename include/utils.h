#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // para tolower

#ifdef _WIN32
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
#endif

void normalize_input(char* str);

#endif // UTILS_H