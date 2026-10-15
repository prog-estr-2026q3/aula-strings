#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

// Converte confiavelmente uma cadeia para long.
// Retorna true em sucesso estrito ou false diante de qualquer anomalia.
bool converter_para_long(const char *texto, long *saida) {
    if (texto == NULL || *texto == '\0') {
        return false;
    }

    char *fim;
    errno = 0; // Zera a variavel global de diagnostico da biblioteca padrao
    long val = strtol(texto, &fim, 10);

    // Validacoes essenciais de erro
    if (errno != 0) {
        return false; // Estouro de capacidade (overflow / underflow)
    }
    if (fim == texto) {
        return false; // Nenhum caractere numerico foi encontrado
    }
    if (*fim != '\0') {
        return false; // Caracteres nao-numericos residuais no final da cadeia
    }

    *saida = val;
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Uso: %s <operacao: add|sub|mul> <num1> <num2>\n", argv[0]);
        return 1;
    }

    const char *op = argv[1];
    long n1, n2;

    if (!converter_para_long(argv[2], &n1) || !converter_para_long(argv[3], &n2)) {
        fprintf(stderr, "Erro: argumentos '%s' e '%s' devem ser inteiros validos.\n",
                argv[2], argv[3]);
        return 2;
    }

    if (strcmp(op, "add") == 0) {
        printf("Resultado: %ld\n", n1 + n2);
    } else if (strcmp(op, "sub") == 0) {
        printf("Resultado: %ld\n", n1 - n2);
    } else if (strcmp(op, "mul") == 0) {
        printf("Resultado: %ld\n", n1 * n2);
    } else {
        fprintf(stderr, "Erro: operacao '%s' nao reconhecida.\n", op);
        return 3;
    }

    return 0; // Encerramento bem-sucedido repassado ao sistema operacional
}

