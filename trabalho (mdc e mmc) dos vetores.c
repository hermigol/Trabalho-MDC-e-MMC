#include <stdio.h>


int MDC(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int MMC(int a, int b) {
    return (a * b) / MDC(a, b);
}

int calcularMDC(int vetor[], int tamanho) {
    int resultado = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        resultado = MDC(resultado, vetor[i]);
    }
    return resultado;
}

int calcularMMC(int vetor[], int tamanho) {
    int resultado = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        resultado = MMC(resultado, vetor[i]);
    }
    return resultado;
}

int main() {
    int tamanho;

    printf("Digite o número de elementos do vetor: ");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    for (int i = 0; i < tamanho; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    int mdc = calcularMDC(vetor, tamanho);
    int mmc = calcularMMC(vetor, tamanho);

    printf("O MDC dos valores digitados e %d\n", mdc);
    printf("O MMC dos valores digitados e %d\n", mmc);

    return 0;
}
