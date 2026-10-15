#include <stdio.h>
#include <stdbool.h>

int main(void) {
    const char *primeiro = "Ada";
    const char *ultimo = "Lovelace";

    char destino[16];
    char curto[8];

    // 1. Operacao de Copia Segura
    snprintf(destino, sizeof(destino), "%s", primeiro);
    printf("Copia: [%s]\n", destino);

    // 2. Operacao de Concatenacao Segura
    snprintf(destino, sizeof(destino), "%s %s", primeiro, ultimo);
    printf("Concatenacao: [%s]\n", destino);

    // 3. Deteccao de Truncamento em Buffer Pequeno
    int necessarios = snprintf(curto, sizeof(curto), "%s %s", primeiro, ultimo);

    printf("Resultado no buffer curto: [%s]\n", curto);
    printf("Caracteres necessarios: %d | Capacidade do buffer: %zu\n",
           necessarios, sizeof(curto));

    if (necessarios >= (int)sizeof(curto)) {
        printf("AVISO: O texto foi truncado! Perderam-se %d caracteres.\n",
               necessarios - (int)sizeof(curto) + 1);
    }

    return 0;
}

