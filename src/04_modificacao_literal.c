#include <stdio.h>

int main(void) {
    char local[] = "Texto";
    local[0] = 't';           // Plenamente valido: mutacao na pilha local
    printf("Local: %s\n", local);

    // Uso incorreto: ponteiro nao qualificado como const
    char *literal = "Texto";  

    printf("Tentando alterar a primeira letra do literal...\n");
    literal[0] = 't';         // Comportamento indefinido: Falha de segmentacao!
    printf("Nao alcancara esta linha: %s\n", literal);

    return 0;
}

