#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool eh_palindromo(const char *frase) {
    if (frase == NULL) {
        return false;
    }

    size_t n = strlen(frase);
    if (n == 0) {
        return true;
    }

    const char *inicio = frase;
    const char *fim = frase + n - 1;

    while (inicio < fim) {
        if (!isalnum((unsigned char)*inicio)) {
            inicio++;
            continue;
        }
        if (!isalnum((unsigned char)*fim)) {
            fim--;
            continue;
        }
        if (tolower((unsigned char)*inicio) != tolower((unsigned char)*fim)) {
            return false;
        }
        inicio++;
        fim--;
    }
    return true;
}

int main(void) {
    const char *testes[] = {
        "Ame o poema!",
        "Socorram-me, subi no onibus em Marrocos",
        "A grama e amarga.",
        "Programacao Estruturada"
    };

    for (size_t i = 0; i < sizeof(testes)/sizeof(testes[0]); i++) {
        printf("\"%s\" -> %s\n", testes[i], eh_palindromo(testes[i]) ? "PALINDROMO" : "NAO PALINDROMO");
    }
    return 0;
}
