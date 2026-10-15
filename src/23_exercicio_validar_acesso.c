#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool validar_acesso_seguro(void) {
    char senha[16];
    printf("Digite a senha de administrador: ");

    if (fgets(senha, sizeof(senha), stdin) == NULL) {
        return false;
    }

    // Remove a quebra de linha residual
    senha[strcspn(senha, "\n")] = '\0';

    return (strcmp(senha, "segredo") == 0);
}

int main(void) {
    printf("--- Teste de Validacao Segura de Senha ---\n");
    if (validar_acesso_seguro()) {
        printf("Acesso concedido!\n");
    } else {
        printf("Acesso negado!\n");
    }
    return 0;
}
