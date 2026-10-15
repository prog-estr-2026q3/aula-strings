#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

void cifrar_linha(char *str, int k) {
    for (size_t i = 0; str[i] != '\0'; i++) {
        unsigned char c = (unsigned char)str[i];
        if (isupper(c)) {
            str[i] = (char)('A' + (c - 'A' + k) % 26);
        } else if (islower(c)) {
            str[i] = (char)('a' + (c - 'a' + k) % 26);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3 || strcmp(argv[1], "-k") != 0) {
        fprintf(stderr, "Uso: %s -k <deslocamento>\n", argv[0]);
        return 1;
    }

    char *fim;
    errno = 0;
    long k_bruto = strtol(argv[2], &fim, 10);
    if (errno != 0 || fim == argv[2] || *fim != '\0') {
        fprintf(stderr, "Erro: deslocamento '%s' invalido.\n", argv[2]);
        return 2;
    }

    // Normaliza o deslocamento ciclico no intervalo 0 a 25
    int k = (int)(((k_bruto % 26) + 26) % 26);

    char linha[512];
    while (fgets(linha, sizeof(linha), stdin) != NULL) {
        cifrar_linha(linha, k);
        fputs(linha, stdout);
    }

    return 0;
}
