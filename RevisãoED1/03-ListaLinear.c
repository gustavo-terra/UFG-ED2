/*
O código abaixo apresenta a implementação de uma lista linear.

Para esse exemplo, faça:
- Implemente funções adicionais como buscar(int elemento) para encontrar a posição de um elemento na lista.
ou 
- Adicione métodos para inverter a lista, encontrar o máximo/mínimo, ou ordenar a lista.
*/

#include <stdio.h>
#define MAX_SIZE 10

int lista[MAX_SIZE];
int tamanho = 0;

int minimo() {
    int val_minimo = lista[0];
    for (int i = 0; i < tamanho; i++) {
        if (lista[i] < val_minimo) {
            val_minimo = lista[i];
        }
    }
    return val_minimo;
}

int maximo() {
    int val_maximo = lista[0];
    for (int i = 0; i < tamanho; i++) {
        if (lista[i] > val_maximo) {
            val_maximo = lista[i];
        }
    }
    return val_maximo;
}

void inverter() {
    int lista_aux[tamanho];
    for (int i = 0; i < tamanho; i++) {
        lista_aux[i] = lista[i];
    }
    
    for (int i = 0; i < tamanho; i++) {
        lista[i] = lista_aux[tamanho-1-i];
    }
}

int buscar(int elemento) {
    int posicao = -1;
    for (int i = 0; i < tamanho; i++) {
        if (lista[i] == elemento) {
            posicao = i;
        }
    }
    
    return posicao;
}

void inserir(int elemento) {
    if (tamanho < MAX_SIZE) {
        lista[tamanho++] = elemento;
    } else {
        printf("Lista cheia!\n");
    }
}

void remover(int index) {
    if (index < 0 || index >= tamanho) {
        printf("Índice inválido!\n");
    } else {
        for (int i = index; i < tamanho - 1; i++) {
            lista[i] = lista[i + 1];
        }
        tamanho--;
    }
}

void imprimir() {
    printf("Elementos da lista:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main() {
    inserir(10);
    inserir(20);
    inserir(30);
    imprimir();
    printf("%d\n", buscar(20));
    inverter();
    imprimir();
    printf("%d\n", maximo());
    printf("%d\n", minimo());
    return 0;
}
