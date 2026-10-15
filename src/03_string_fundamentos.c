#include <stdio.h>

int main(void) {
    char saudacao[4] = "Ola";
    char buffer[8]   = "C-lang";

    printf("saudacao: \"%s\" (capacidade: %zu bytes)\n", saudacao, sizeof(saudacao));
    printf("buffer:   \"%s\" (capacidade: %zu bytes)\n", buffer, sizeof(buffer));

    printf("\nBytes de saudacao:\n");
    for (size_t i = 0; i < sizeof(saudacao); i++) {
        printf("  saudacao[%zu] | endereco %p | char: '%c' | ASCII: %3d (0x%02X)\n",
               i, (void*)&saudacao[i], saudacao[i], (int)saudacao[i], (unsigned char)saudacao[i]);
    }

    printf("\nBytes de buffer:\n");
    for (size_t i = 0; i < sizeof(buffer); i++) {
        char c = (buffer[i] >= 32 && buffer[i] <= 126) ? buffer[i] : ' ';
        printf("  buffer[%zu]   | endereco %p | char: '%c' | ASCII: %3d (0x%02X)\n",
               i, (void*)&buffer[i], c, (int)buffer[i], (unsigned char)buffer[i]);
    }

    return 0;
}

