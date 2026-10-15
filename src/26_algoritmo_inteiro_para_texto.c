#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

void inverter_arranjo(char *str, size_t n) {
    if (str == NULL || n <= 1) {
        return;
    }

    size_t i = 0;
    size_t j = n - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

void inteiro_para_texto(long n, char *buf, size_t cap) {
    if (buf == NULL || cap == 0) {
        return;
    }

    char temp[32];
    size_t pos = 0;
    bool negativo = (n < 0);
    unsigned long abs_n = negativo ? -n : n;

    do {
        temp[pos++] = '0' + (abs_n % 10);
        abs_n /= 10;
    } while (abs_n > 0);

    if (negativo) {
        temp[pos++] = '-';
    }

    inverter_arranjo(temp, pos);

    size_t i = 0;
    while (i < pos && i + 1 < cap) {
        buf[i] = temp[i];
        i++;
    }
    buf[i] = '\0';
}

int main(void) {
    char buffer[32];

    inteiro_para_texto(-1234, buffer, sizeof(buffer));
    printf("Resultado: \"%s\"\n", buffer);

    inteiro_para_texto(0, buffer, sizeof(buffer));
    printf("Resultado: \"%s\"\n", buffer);

    inteiro_para_texto(987654321, buffer, sizeof(buffer));
    printf("Resultado: \"%s\"\n", buffer);

    return 0;
}
