#include <stdio.h>

int main() {
    int n, pixel, x_min, x_max;
    float x, x_linha;

    printf("Digite N: ");
    scanf("%d", &n);

    printf("Digite o pixel 1: ");
    scanf("%d", &pixel);
    x_min = pixel;
    x_max = pixel;

    for (int i = 2; i <= n; i++) {
        printf("Digite o pixel %d: ", i);
        scanf("%d", &pixel);
        if (pixel < x_min) x_min = pixel;
        if (pixel > x_max) x_max = pixel;
    }

    printf("Menor (Xmin): %d\nMaior (Xmax): %d\n", x_min, x_max);

    printf("Digite X: ");
    scanf("%f", &x);

    x_linha = ((x - x_min) / (float)(x_max - x_min)) * 255.0f;

    printf("X': %.2f\n", x_linha);

    return 0;
}