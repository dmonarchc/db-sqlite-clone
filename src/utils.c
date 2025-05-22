#ifdef _WIN32

#include "utils.h"

ssize_t getline(char **lineptr, size_t *n, FILE *stream) {
    char *bufptr = NULL;
    char *p = NULL;
    size_t size;
    int c;

    if (lineptr == NULL || stream == NULL || n == NULL) return -1;

    bufptr = *lineptr;
    size = *n;

    c = fgetc(stream);
    if (c == EOF) return -1;

    if (bufptr == NULL) {
        bufptr = malloc(128);
        if (bufptr == NULL) return -1;
        size = 128;
    }

    p = bufptr;
    while (c != EOF) {
        if ((p - bufptr) > (size - 1)) {
            size = size + 128;
            bufptr = realloc(bufptr, size);
            if (bufptr == NULL) return -1;
        }
        *p++ = c;
        if (c == '\n') break;
        c = fgetc(stream);
    }

    *p = '\0';
    *lineptr = bufptr;
    *n = size;

    return p - bufptr;
}

#endif

#include <ctype.h>  // para tolower

void normalize_input(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}