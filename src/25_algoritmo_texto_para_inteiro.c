#include <stdio.h>
#include <stdbool.h>

bool eh_digito(char c) {
    return c >= '0' && c <= '9';
}

int para_digito(char c) {
    if (!eh_digito(c)) {
        return -1;
    }
    return c - '0';
}

bool texto_para_inteiro(const char *str, long *resultado) {
    if (str == NULL || resultado == NULL) {
        return false;
    }

    int sinal = 1;
    if (*str == '-') {
        sinal = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    if (!eh_digito(*str)) {
        return false;
    }

    long valor = 0;

    while (eh_digito(*str)) {
        valor = valor * 10 + para_digito(*str);
        str++;
    }

    if (*str != '\0') {
        return false;
    }

    *resultado = valor * sinal;
    return true;
}

int main(void) {
    long valor;

    if (texto_para_inteiro("-1234", &valor)) {
        printf("Sucesso: %ld\n", valor);
    } else {
        printf("Falha na conversao de -1234\n");
    }

    if (!texto_para_inteiro("12a4", &valor)) {
        printf("Entrada invalida rejeitada\n");
    } else {
        printf("Erro: '12a4' deveria ter sido rejeitada\n");
    }

    if (texto_para_inteiro("+42", &valor)) {
        printf("Sucesso com sinal positivo: %ld\n", valor);
    }

    return 0;
}
