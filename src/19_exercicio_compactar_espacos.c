#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>

void compactar_espacos(char *str) {
    if (str == NULL) {
        return;
    }

    size_t escrita = 0;
    bool em_espaco = false;
    size_t i = 0;

    // Ignora espacos iniciais
    while (str[i] != '\0' && isspace((unsigned char)str[i])) {
        i++;
    }

    // Varredura linear com cursor de leitura (i) e cursor de escrita
    for (; str[i] != '\0'; i++) {
        if (isspace((unsigned char)str[i])) {
            if (!em_espaco) {
                str[escrita++] = ' ';
                em_espaco = true;
            }
        } else {
            str[escrita++] = str[i];
            em_espaco = false;
        }
    }

    // Remove eventual espaco final sobressalente
    if (escrita > 0 && str[escrita - 1] == ' ') {
        escrita--;
    }

    str[escrita] = '\0';
}

int main(void) {
    char texto[] = "   Programacao    Estruturada   na   UFABC   ";
    printf("Antes:  \"%s\"\n", texto);
    compactar_espacos(texto);
    printf("Depois: \"%s\"\n", texto);
    return 0;
}
