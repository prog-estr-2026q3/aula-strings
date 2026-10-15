#include <stdio.h>

#define MAX_SIGLA 5

int main(void) {
    // Inicializacao elemento por elemento com sentinela explicito
    char s1[] = {'O', 'l', 'a', '\0'};

    // Inicializacao abreviada por literal (tamanho inferido: 3 + 1 = 4 bytes)
    char s2[] = "Ola";

    // Buffer pre-dimensionado (regra N+1) com preenchimento parcial
    char sigla[MAX_SIGLA + 1] = "UFABC";

    // Buffer com cadeia vazia
    char vazia[10] = "";

    // Concatenacao automatica de literais adjacentes
    const char *aviso = "Programacao " "Estruturada";

    printf("s1:    \"%s\" (sizeof = %zu bytes)\n", s1, sizeof(s1));
    printf("s2:    \"%s\" (sizeof = %zu bytes)\n", s2, sizeof(s2));
    printf("sigla: \"%s\" (sizeof = %zu bytes)\n", sigla, sizeof(sigla));
    printf("vazia: \"%s\" (sizeof = %zu bytes)\n", vazia, sizeof(vazia));
    printf("aviso: \"%s\"\n", aviso);

    return 0;
}

