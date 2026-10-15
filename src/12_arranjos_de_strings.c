#include <stdio.h>
#include <string.h>

int main(void) {
    // 1. Matriz de caracteres: 3 linhas por 15 colunas = 45 bytes contiguos
    char alunos[3][15] = {
        "Beatriz",
        "Carlos",
        "Daniela"
    };

    // As linhas da matriz sao buffers mutaveis
    snprintf(alunos[0], sizeof(alunos[0]), "Bia");

    // 2. Arranjo de ponteiros para literais: 3 ponteiros de 8 bytes = 24 bytes
    const char *meses[] = {
        "Janeiro",
        "Fevereiro",
        "Marco"
    };

    printf("--- Alunos (Matriz Mutavel, sizeof=%zu bytes) ---\n", sizeof(alunos));
    for (size_t i = 0; i < 3; i++) {
        printf("aluno[%zu] em %p: %s\n", i, (void*)alunos[i], alunos[i]);
    }

    printf("\n--- Meses (Arranjo de Ponteiros, sizeof=%zu bytes) ---\n", sizeof(meses));
    for (size_t i = 0; i < 3; i++) {
        printf("meses[%zu] (ponteiro em %p) aponta para %p: %s\n",
               i, (void*)&meses[i], (void*)meses[i], meses[i]);
    }

    return 0;
}

