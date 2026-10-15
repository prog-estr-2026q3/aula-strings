#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <query_string>\n", argv[0]);
        printf("Exemplo: %s \"termo=algoritmo&ordem=asc&limite=20\"\n", argv[0]);
        return 1;
    }

    char buffer[512];
    snprintf(buffer, sizeof(buffer), "%s", argv[1]);

    char *par = strtok(buffer, "&");
    while (par != NULL) {
        char *igual = strchr(par, '=');
        if (igual != NULL) {
            *igual = '\0';
            char *chave = par;
            char *valor = igual + 1;
            printf("Chave: %-12s | Valor: %s\n", chave, valor);
        } else {
            printf("Aviso: parametro sem atribuicao de valor: [%s]\n", par);
        }
        par = strtok(NULL, "&");
    }

    return 0;
}
