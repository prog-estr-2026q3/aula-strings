#include <stdio.h>
#include <string.h>

int main(void) {
    // Arranjo modificavel na pilha: strtok alterara este bloco
    char registro[] = "102030;Carlos Silva;Engenharia;8.75";
    const char *delimitador = ";";

    printf("Registro original: %s\n\n", registro);

    // Primeira chamada passando o arranjo original
    char *token = strtok(registro, delimitador);
    int campo = 1;

    while (token != NULL) {
        printf("Campo %d: [%s]\n", campo++, token);
        // Chamadas subsequentes passando NULL
        token = strtok(NULL, delimitador);
    }

    // Observando o efeito de mutacao no arranjo original
    printf("\nPrimeiro byte do registro apos tokenizacao: %s\n", registro);

    return 0;
}

