#include <stdio.h>

int main () {
    int N;
    float amostra1, amostra2, amostra3, media;

    scanf("%d", &N);
    scanf("%f", &amostra1);
    scanf("%f", &amostra2);

    for (int i = 3; i <= N; i++) {
        scanf("%f", &amostra3);

        media = (amostra1 + amostra2 + amostra3) / 3.0f;
        printf("Media centrada amostra %d: %2f\n", i -1, media);

        amostra1 = amostra2;
        amostra2 = amostra3;
    }
    return 0;

}
