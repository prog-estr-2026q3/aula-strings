#include <stdio.h>

int main(void) {
    char str_arranjo[]   = "Engenharia"; // Caso 1: arranjo na pilha
    const char *str_ptr1 = "Engenharia"; // Caso 2: ponteiro para .rodata
    const char *str_ptr2 = "Engenharia"; // Caso 3: segundo ponteiro para .rodata

    printf("--- Enderecos das variaveis na Pilha (Stack) ---\n");
    printf("&str_arranjo: %p\n", (void*)str_arranjo);
    printf("&str_ptr1:    %p\n", (void*)&str_ptr1);
    printf("&str_ptr2:    %p\n", (void*)&str_ptr2);

    printf("\n--- Enderecos apontados pelos ponteiros (.rodata) ---\n");
    printf("str_ptr1:     %p\n", (void*)str_ptr1);
    printf("str_ptr2:     %p\n", (void*)str_ptr2);

    printf("\n--- Comparacoes de ponteiros ---\n");
    printf("str_ptr1 == str_ptr2:    %s (apontam para o mesmo literal unificado)\n",
           (str_ptr1 == str_ptr2) ? "VERDADEIRO" : "FALSO");
    printf("&str_ptr1 == &str_ptr2:  %s (variaveis distintas na pilha)\n",
           (&str_ptr1 == &str_ptr2) ? "VERDADEIRO" : "FALSO");
    printf("str_ptr1 == str_arranjo: %s (arranjo possui copia independente na pilha)\n",
           (str_ptr1 == str_arranjo) ? "VERDADEIRO" : "FALSO");

    return 0;
}
