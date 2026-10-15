#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
    int c;
    size_t total_linhas = 0;
    size_t total_palavras = 0;
    size_t total_bytes = 0;
    bool dentro_de_palavra = false;

    while ((c = getchar()) != EOF) {
        total_bytes++;

        if (c == '\n') {
            total_linhas++;
        }

        if (isspace((unsigned char)c)) {
            dentro_de_palavra = false;
        } else if (!dentro_de_palavra) {
            dentro_de_palavra = true;
            total_palavras++;
        }
    }

    printf("%7zu %7zu %7zu\n", total_linhas, total_palavras, total_bytes);
    return 0;
}
