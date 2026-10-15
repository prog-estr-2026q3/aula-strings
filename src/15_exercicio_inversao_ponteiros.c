#include <stdio.h>
#include <string.h>

int main(void) {
    char cadeia[] = "ESTRUTURA";
    char *inicio = cadeia;
    char *fim = cadeia + strlen(cadeia) - 1;

    while (inicio < fim) {
        char temp = *inicio;
        *inicio++ = *fim;
        *fim-- = temp;
    }
    printf("%s | deslocamento: %td\n", cadeia, inicio - cadeia);
    return 0;
}
