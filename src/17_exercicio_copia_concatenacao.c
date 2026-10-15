#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

bool copiar_seguro(char *dest, size_t cap, const char *origem) {
    if (dest == NULL || cap == 0) {
        return false;
    }
    if (origem == NULL) {
        dest[0] = '\0';
        return false;
    }

    size_t i = 0;
    while (i < cap - 1 && origem[i] != '\0') {
        dest[i] = origem[i];
        i++;
    }
    dest[i] = '\0';
    return (origem[i] == '\0');
}

bool concatenar_seguro(char *dest, size_t cap, const char *origem) {
    if (dest == NULL || cap == 0) {
        return false;
    }
    if (origem == NULL) {
        return true;
    }

    size_t len_dest = 0;
    while (len_dest < cap && dest[len_dest] != '\0') {
        len_dest++;
    }

    if (len_dest >= cap - 1) {
        dest[cap - 1] = '\0';
        return false;
    }

    size_t j = 0;
    while ((len_dest + j) < cap - 1 && origem[j] != '\0') {
        dest[len_dest + j] = origem[j];
        j++;
    }
    dest[len_dest + j] = '\0';
    return (origem[j] == '\0');
}

int main(void) {
    char buf[12];
    bool ok1 = copiar_seguro(buf, sizeof(buf), "Ola ");
    printf("copiar:     [%s] (sucesso: %s)\n", buf, ok1 ? "sim" : "nao");

    bool ok2 = concatenar_seguro(buf, sizeof(buf), "Mundo!");
    printf("concatenar: [%s] (sucesso: %s)\n", buf, ok2 ? "sim" : "nao");

    bool ok3 = concatenar_seguro(buf, sizeof(buf), " Extensao longa demais");
    printf("truncado:   [%s] (sucesso: %s)\n", buf, ok3 ? "sim" : "nao");
    return 0;
}
