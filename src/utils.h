#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
#endif

#endif

#include <ctype.h>  // para tolower

void normalize_input(char* str) ;