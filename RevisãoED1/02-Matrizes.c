/*
O código abaixo recebe do usuário elementos que são inseridos em uma matriz 3x3, em seguida, imprime a soma de sua diagonal principal.
- faça uma modificação para que seja possível dinamizar o tamanho da matriz (utilizar alocação dinâmica de memória usando malloc)
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int linhas = 5;
    int colunas = 5;
    
    int** matriz = (int**) malloc(sizeof(linhas * sizeof(int)));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int*) malloc(sizeof(colunas * sizeof(int)));
    }
    
    int soma = 0;
    printf("Insira os elementos da matriz %dx%d:\n", linhas, colunas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
            if (i == j) {
                soma += matriz[i][j];
            }
        }
    }

    printf("Soma dos elementos da diagonal principal: %d\n", soma);
    return 0;
}