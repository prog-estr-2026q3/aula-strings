#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Le uma linha para o buffer, remove o '\n' e limpa excedentes se truncado.
// Retorna true em sucesso ou false caso atinja EOF sem ler caracteres.
bool ler_linha_segura(char *buffer, size_t capacidade) {
    if (buffer == NULL || capacidade == 0) {
        return false;
    }

    if (fgets(buffer, (int)capacidade, stdin) == NULL) {
        return false;
    }

    size_t len = strlen(buffer);

    // Verifica se a quebra de linha foi capturada
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0'; // Remove o '\n'
    } else if (len == capacidade - 1) {
        // Buffer foi saturado: consome os caracteres excedentes do fluxo
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
            // descarta
        }
    }

    return true;
}

int main(void) {
    char nome[12]; // Capacidade para 11 caracteres uteis + '\0'

    printf("Digite um nome completo: ");
    if (ler_linha_segura(nome, sizeof(nome))) {
        printf("Nome armazenado com seguranca: [%s]\n", nome);
    }

    return 0;
}

