#include <stdio.h>

int main() {
    FILE *entrada;

    if ((entrada = fopen("entrada.txt", "r")) == NULL) {
        printf("Error while opening read file.");
        return 1;
    }

    printf("Hello World");
    fclose(entrada);
    return 0;
}