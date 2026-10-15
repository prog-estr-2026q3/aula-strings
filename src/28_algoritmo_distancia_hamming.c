#include <stdio.h>

int distancia_hamming(const char *s1, const char *s2) {
    if (s1 == NULL || s2 == NULL) {
        return -1;
    }

    int diferencas = 0;

    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) {
            diferencas++;
        }
        s1++;
        s2++;
    }

    if (*s1 != '\0' || *s2 != '\0') {
        return -1; // Comprimentos divergentes
    }
    return diferencas;
}

int main(void) {
    const char *p1 = "casa";
    const char *p2 = "caso";
    printf("Distancia entre '%s' e '%s': %d\n", p1, p2, distancia_hamming(p1, p2));

    const char *p3 = "roma";
    const char *p4 = "amor";
    printf("Distancia entre '%s' e '%s': %d\n", p3, p4, distancia_hamming(p3, p4));

    const char *dna1 = "GAGCCTACTAACGGGAT";
    const char *dna2 = "CATCGTAATGACGGCCT";
    printf("Distancia entre sequencias de DNA:\n  %s\n  %s\n  Distancia: %d\n",
           dna1, dna2, distancia_hamming(dna1, dna2));

    const char *diferente = "tamanho_diferente";
    printf("Distancia com comprimentos distintos: %d\n", distancia_hamming(p1, diferente));

    return 0;
}
