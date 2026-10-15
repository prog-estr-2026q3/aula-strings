#include <stdio.h>
#include <stddef.h>

const char *meu_strstr(const char *texto, const char *padrao) {
    if (texto == NULL || padrao == NULL) {
        return NULL;
    }

    if (*padrao == '\0') {
        return texto;
    }

    for (size_t i = 0; texto[i] != '\0'; i++) {
        size_t j = 0;
        while (padrao[j] != '\0' && texto[i + j] == padrao[j]) {
            j++;
        }
        if (padrao[j] == '\0') {
            return &texto[i];
        }
    }
    return NULL;
}

int main(void) {
    const char *frase = "Programacao Estruturada em C";
    const char *padrao1 = "Estruturada";
    const char *padrao2 = "Python";

    const char *pos1 = meu_strstr(frase, padrao1);
    if (pos1 != NULL) {
        printf("Padrao '%s' encontrado no indice %td: \"%s\"\n",
               padrao1, pos1 - frase, pos1);
    } else {
        printf("Padrao '%s' nao encontrado.\n", padrao1);
    }

    const char *pos2 = meu_strstr(frase, padrao2);
    if (pos2 != NULL) {
        printf("Padrao '%s' encontrado no indice %td: \"%s\"\n",
               padrao2, pos2 - frase, pos2);
    } else {
        printf("Padrao '%s' nao encontrado.\n", padrao2);
    }

    return 0;
}
