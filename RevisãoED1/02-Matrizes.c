/*
O código abaixo recebe do usuário elementos que são inseridos em uma matriz 3x3, em seguida, imprime a soma de sua diagonal principal.
- faça uma modificação para que seja possível dinamizar o tamanho da matriz (utilizar alocação dinâmica de memória usando malloc)
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *linhas = (int*) malloc(sizeof(int));
    int *colunas = (int*) malloc(sizeof(int));
    
    *linhas = 5;
    *colunas = 5;
    
    int matriz[*linhas][*colunas];
    int temp;
    for (int i = 0; i < *linhas; i++) {
        for (int j = 0; j < *colunas; j++) {
            printf("Valor: linha %d e coluna %d = ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    // valores da diagonal principal
    // condição "e" para caso de matriz não quadrada
    int soma = 0;
    for (int n = 0; n < *linhas && n < *colunas; n++) {
        soma = soma + matriz[n][n];
    }
    
    printf("Soma dos elementos da diagonal principal: %d\n", soma);
    
    return 0;
}
