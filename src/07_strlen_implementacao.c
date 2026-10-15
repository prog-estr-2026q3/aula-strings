#include <stdio.h>
#include <stddef.h>

// Versao 1: medicao por indexacao de arranjo
size_t my_strlen_idx(const char s[]) {
    size_t len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

// Versao 2: medicao por subtracao de ponteiros (aritmetica de enderecos)
size_t my_strlen_ptr(const char *s) {
    const char *p = s;
    while (*p != '\0') {
        p++;
    }
    return (size_t)(p - s); // Distancia fisica em elementos entre p e s
}

int main(void) {
    const char *frase = "UFABC";
    printf("Comprimento por indice:   %zu\n", my_strlen_idx(frase));
    printf("Comprimento por ponteiro: %zu\n", my_strlen_ptr(frase));
    return 0;
}

