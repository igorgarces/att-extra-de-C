#include <stdio.h>

int main() {
    unsigned char R, G, B;
    unsigned char M;

    printf("Digite o valor de R (0-255): ");
    scanf("%hhu", &R);
    printf("Digite o valor de G (0-255): ");
    scanf("%hhu", &G);
    printf("Digite o valor de B (0-255): ");
    scanf("%hhu", &B);

    printf("Digite a mensagem M (0-7, correspondente a 3 bits): ");
    scanf("%hhu", &M);

    unsigned char bit2_M = (M >> 2) & 1; // Bit 2 de M
    unsigned char bit1_M = (M >> 1) & 1; // Bit 1 de M
    unsigned char bit0_M = (M >> 0) & 1; // Bit 0 de M

    R = (R & 0xFE) | bit2_M;
    G = (G & 0xFE) | bit1_M;
    B = (B & 0xFE) | bit0_M;

    printf("\n--- Valores Modificados com Esteganografia ---\n");
    printf("R modificado: %u\n", R);
    printf("G modificado: %u\n", G);
    printf("B modificado: %u\n", B);

    unsigned char M_recuperado = (((R & 1) << 2) | ((G & 1) << 1) | (B & 1));
    printf("Mensagem recuperada dos bits LSB: %u\n", M_recuperado);

    return 0;
}