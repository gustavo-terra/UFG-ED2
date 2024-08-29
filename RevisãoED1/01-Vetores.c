#include <stdio.h>
#include <stdlib.h>

int main() {
    // variável tamanho do vetor N
    unsigned int N;
    
    // receber tamanho do vetor
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &N);
    
    // declaração do vetor, receber valores
    int vetor[N];
    int i;
    for (i = 0; i < N; i++) {
        scanf("%d", &vetor[i]);
    }
    
    int vetor_invertido[N];
    int temp;
    
    for (i = 0; i < N; i++) {
        vetor_invertido[i] = vetor[N-1-i];
    }
    
    printf("Vetor invertido: ");
    for (i = 0; i < N; i++) {
        printf("%d ", vetor_invertido[i]);
    }
    
    
    
    
    
    return 0;
}
