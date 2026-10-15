#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool comeca_com(const char *str, const char *prefixo) {
    if (str == NULL || prefixo == NULL) {
        return false;
    }

    size_t tam_str = strlen(str);
    size_t tam_pref = strlen(prefixo);

    if (tam_pref > tam_str) {
        return false;
    }

    while (*prefixo != '\0') {
        if (*str != *prefixo) {
            return false;
        }
        str++;
        prefixo++;
    }
    return true;
}

bool termina_com(const char *str, const char *sufixo) {
    if (str == NULL || sufixo == NULL) {
        return false;
    }

    size_t tam_str = strlen(str);
    size_t tam_suf = strlen(sufixo);

    if (tam_suf > tam_str) {
        return false;
    }

    const char *p = str + (tam_str - tam_suf);
    while (*sufixo != '\0') {
        if (*p != *sufixo) {
            return false;
        }
        p++;
        sufixo++;
    }
    return true;
}

int main(void) {
    const char *texto = "programa";

    printf("--- Verificacao de Prefixos ---\n");
    printf("comeca_com(\"%s\", \"prog\"): %s\n",
           texto, comeca_com(texto, "prog") ? "true" : "false");
    printf("comeca_com(\"%s\", \"projeto\"): %s\n",
           texto, comeca_com(texto, "projeto") ? "true" : "false");

    const char *url = "https://ufabc.edu.br";
    printf("comeca_com(\"%s\", \"https://\"): %s\n",
           url, comeca_com(url, "https://") ? "true" : "false");

    printf("\n--- Verificacao de Sufixos ---\n");
    printf("termina_com(\"%s\", \"grama\"): %s\n",
           texto, termina_com(texto, "grama") ? "true" : "false");
    printf("termina_com(\"%s\", \"grana\"): %s\n",
           texto, termina_com(texto, "grana") ? "true" : "false");

    const char *arquivo = "relatorio.pdf";
    printf("termina_com(\"%s\", \".pdf\"): %s\n",
           arquivo, termina_com(arquivo, ".pdf") ? "true" : "false");

    return 0;
}
