#include <stdio.h>

int main() {
    int N;
    double anterior, atual, proximo;
    double media;

    // Leitura e validação de N
    printf("Digite o numero de amostras N: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Erro: N deve ser maior que zero.\n");
        return 1;
    }

    // Para menos de 3 amostras não existe janela completa
    if (N < 3) {
        printf("Nao e possivel calcular a media movel centrada ");
        printf("com uma janela de tamanho 3 para N < 3.\n");
        return 0;
    }

    /*
     * Leitura das duas primeiras amostras.
     * Precisamos delas para formar a primeira janela.
     */
    printf("Digite a amostra 1: ");
    scanf("%lf", &anterior);

    printf("Digite a amostra 2: ");
    scanf("%lf", &atual);

    /*
     * A partir da terceira amostra conseguimos
     * formar uma janela completa:
     *
     * anterior | atual | proximo
     */
    for (int i = 3; i <= N; i++) {

        printf("Digite a amostra %d: ", i);
        scanf("%lf", &proximo);

        // Média da janela centrada
        media = (anterior + atual + proximo) / 3.0;

        /*
         * A média calculada corresponde à posição central.
         * Por exemplo:
         * x1 x2 x3 -> média para x2
         */
        printf("Media centrada para a posicao %d: %.2f\n",
               i - 1, media);

        /*
         * Deslocamos a janela:
         *
         * anterior <- atual
         * atual     <- proximo
         */
        anterior = atual;
        atual = proximo;
    }

    /*
     * A primeira e a última amostra não possuem
     * vizinhos dos dois lados, portanto não possuem
     * média móvel centrada.
     */
    printf("\nA primeira e a ultima amostra nao possuem ");
    printf("media movel centrada.\n");

    return 0;
}
