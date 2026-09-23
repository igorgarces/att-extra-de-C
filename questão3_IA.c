#include <stdio.h>

int main() {
    int N;
    int pixel;
    int xmin, xmax;
    double normalizado;

    // Leitura da quantidade de pixels
    printf("Digite a quantidade de pixels N: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Erro: N deve ser maior que zero.\n");
        return 1;
    }

    /*
     * Leitura do primeiro pixel.
     * Ele será utilizado para inicializar
     * xmin e xmax.
     */
    printf("Digite o pixel 1 (0 a 255): ");
    scanf("%d", &pixel);

    if (pixel < 0 || pixel > 255) {
        printf("Erro: a intensidade deve estar entre 0 e 255.\n");
        return 1;
    }

    xmin = pixel;
    xmax = pixel;

    /*
     * Lemos os demais pixels um por vez.
     * Não precisamos armazená-los.
     */
    for (int i = 2; i <= N; i++) {

        printf("Digite o pixel %d (0 a 255): ", i);
        scanf("%d", &pixel);

        if (pixel < 0 || pixel > 255) {
            printf("Erro: a intensidade deve estar entre 0 e 255.\n");
            return 1;
        }

        // Atualiza o menor valor encontrado
        if (pixel < xmin) {
            xmin = pixel;
        }

        // Atualiza o maior valor encontrado
        if (pixel > xmax) {
            xmax = pixel;
        }
    }

    printf("\nMenor intensidade (xmin): %d\n", xmin);
    printf("Maior intensidade (xmax): %d\n", xmax);

    // Solicita o pixel que será normalizado
    printf("\nDigite o valor do pixel a normalizar (0 a 255): ");
    scanf("%d", &pixel);

    if (pixel < 0 || pixel > 255) {
        printf("Erro: a intensidade deve estar entre 0 e 255.\n");
        return 1;
    }

    /*
     * Se xmin == xmax, todos os pixels possuem
     * a mesma intensidade e o denominador seria zero.
     */
    if (xmax == xmin) {
        printf("\nNao e possivel realizar o Min-Max Scaling.\n");
        printf("xmin e xmax possuem o mesmo valor.\n");
        return 0;
    }

    // Aplicação da fórmula Min-Max
    normalizado = (double)(pixel - xmin) / (xmax - xmin);

    printf("\nPixel original: %d\n", pixel);
    printf("Pixel normalizado: %.4f\n", normalizado);

    return 0;
}
