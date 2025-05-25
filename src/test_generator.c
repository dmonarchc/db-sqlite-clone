#include <stdio.h>

int main() {
    FILE *f = fopen("test_script.txt", "w");
    if(f == NULL) {
        perror("No se pudo crear el archivo");
        return 1;
    }

    for (int i = 1; i < 1401; i++) {
        fprintf(f, "insert % user%d person%example.com\n",i, i, i);
    }

    fprintf(f, ".exit\n");
    fclose(f);
    
    printf("Archivo 'test_script.txt' generado con exito.\n");
    return 0;
}
