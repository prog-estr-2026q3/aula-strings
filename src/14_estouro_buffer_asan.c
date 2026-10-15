#include <stdio.h>
#include <string.h>

int main(void) {
    char buffer_pequeno[8];
    const char *texto_longo = "Estruturas de Dados";

    printf("Tentando copiar string longa para buffer insuficiente...\n");
    strcpy(buffer_pequeno, texto_longo); // Estouro de 12 bytes!
    printf("Resultado: %s\n", buffer_pequeno);

    return 0;
}

