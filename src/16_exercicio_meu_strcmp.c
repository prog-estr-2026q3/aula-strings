#include <stdio.h>

int meu_strcmp(const char *s1, const char *s2) {
    // Avanca enquanto os caracteres forem iguais e s1 nao atingir o terminador
    while (*s1 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }
    // Diferenca aritmetica convertida para unsigned char conforme a norma ISO C
    return (int)((unsigned char)*s1) - (int)((unsigned char)*s2);
}

int main(void) {
    printf("meu_strcmp(\"abc\", \"abc\") = %d\n", meu_strcmp("abc", "abc"));
    printf("meu_strcmp(\"abc\", \"abd\") = %d\n", meu_strcmp("abc", "abd"));
    printf("meu_strcmp(\"abd\", \"abc\") = %d\n", meu_strcmp("abd", "abc"));
    printf("meu_strcmp(\"a\", \"A\")     = %d\n", meu_strcmp("a", "A"));
    return 0;
}
