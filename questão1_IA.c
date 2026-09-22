#include <stdio.h>

int main() {
    int R, G, B;
    int M;
    int bitR, bitG, bitB;
    int recuperada;

    // Leitura e validação dos valores RGB
    printf("Digite o valor de R (0 a 255): ");
    scanf("%d", &R);

    printf("Digite o valor de G (0 a 255): ");
    scanf("%d", &G);

    printf("Digite o valor de B (0 a 255): ");
    scanf("%d", &B);

    if (R < 0 || R > 255 ||
        G < 0 || G > 255 ||
        B < 0 || B > 255) {

        printf("Erro: os valores RGB devem estar entre 0 e 255.\n");
        return 1;
    }

    // Leitura e validação da mensagem de 3 bits
    printf("Digite a mensagem M (0 a 7): ");
    scanf("%d", &M);

    if (M < 0 || M > 7) {
        printf("Erro: M deve estar entre 0 e 7.\n");
        return 1;
    }

    /*
     * Extração dos bits da mensagem:
     * bit 2 -> R
     * bit 1 -> G
     * bit 0 -> B
     */
    bitR = (M >> 2) & 1;
    bitG = (M >> 1) & 1;
    bitB = M & 1;

    /*
     * Limpa o último bit de cada componente
     * e coloca o bit correspondente da mensagem.
     */
    R = (R & ~1) | bitR;
    G = (G & ~1) | bitG;
    B = (B & ~1) | bitB;

    printf("\nRGB modificado:\n");
    printf("R = %d\n", R);
    printf("G = %d\n", G);
    printf("B = %d\n", B);

    /*
     * Recuperação da mensagem:
     * LSB de R -> bit 2
     * LSB de G -> bit 1
     * LSB de B -> bit 0
     */
    recuperada = ((R & 1) << 2) |
                 ((G & 1) << 1) |
                 (B & 1);

    printf("\nMensagem recuperada: %d\n", recuperada);

    return 0;
}
