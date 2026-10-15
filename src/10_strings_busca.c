#include <stdio.h>
#include <string.h>

int main(void) {
    const char *caminho = "/home/aluno/documentos/relatorio.final.pdf";

    // Busca reversa da extensao do arquivo
    const char *ponto = strrchr(caminho, '.');
    if (ponto != NULL) {
        printf("Extensao identificada: %s (indice %td)\n", ponto + 1, ponto - caminho);
    }

    // Busca da ultima barra de diretorio para extrair o nome do arquivo
    const char *barra = strrchr(caminho, '/');
    if (barra != NULL) {
        printf("Nome do arquivo: %s\n", barra + 1);
    }

    // Busca de subcadeia
    const char *termo = "relatorio";
    const char *ocorrencia = strstr(caminho, termo);
    if (ocorrencia != NULL) {
        printf("Termo '%s' localizado na posicao relativa %td\n",
               termo, ocorrencia - caminho);
    }

    return 0;
}

