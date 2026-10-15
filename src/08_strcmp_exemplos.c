#include <stdio.h>
#include <string.h>

int main(void) {
    // Analise de ordem lexicografica com strcmp
    printf("strcmp(\"abacate\", \"banana\"): %d\n", strcmp("abacate", "banana"));
    printf("strcmp(\"banana\", \"abacate\"): %d\n", strcmp("banana", "abacate"));
    printf("strcmp(\"casa\", \"casa\"): %d\n", strcmp("casa", "casa"));

    // Comparacao correta de conteudo com strcmp
    char a[] = "algoritmo";
    char b[] = "algoritmo";
    if (strcmp(a, b) == 0) {
        printf("Cadeias identicas em conteudo!\n");
    }

    // Verificacao de prefixo com strncmp
    const char *comando = "get_temperatura";
    if (strncmp(comando, "get_", 4) == 0) {
        printf("Comando de leitura reconhecido!\n");
    }

    return 0;
}
