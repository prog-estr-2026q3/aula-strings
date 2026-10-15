#include <stdio.h>

int main(void) {
    const char *texto = "Programacao";

    // puts adiciona automaticamente uma quebra de linha ao final
    puts("--- Exibicao com puts (quebra automatica) ---");
    puts(texto);
    puts("Estruturada");

    // fputs envia a cadeia para stdout sem anexar quebra de linha
    puts("\n--- Exibicao com fputs (sem quebra automatica) ---");
    fputs(texto, stdout);
    fputs(" ", stdout);
    fputs("Estruturada\n", stdout);

    return 0;
}
