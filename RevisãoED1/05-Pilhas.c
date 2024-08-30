#include <stdio.h>
#include <stdlib.h> // Necessário para alocação dinâmica

#define INICIAL_SIZE 3 // Tamanho inicial da pilha

int *pilha; // Ponteiro para o array da pilha
int topo = -1;
int capacidade = INICIAL_SIZE; // Capacidade atual da pilha

// Função para inicializar a pilha
void inicializarPilha() {
    pilha = (int *)malloc(capacidade * sizeof(int)); // Aloca memória para a pilha
    if (pilha == NULL) {
        printf("Erro na alocação de memória!\n");
        exit(1);
    }
}

// Função para expandir a capacidade da pilha
void expandirPilha() {
    capacidade *= 2; // Dobra a capacidade da pilha
    pilha = (int *)realloc(pilha, capacidade * sizeof(int)); // Realoa memória com a nova capacidade
    if (pilha == NULL) {
        printf("Erro na realocação de memória!\n");
        exit(1);
    }
}

// Função para adicionar um elemento na pilha
void push(int elemento) {
    if (topo >= capacidade - 1) { // Verifica se a pilha está cheia
        expandirPilha(); // Expande a capacidade da pilha
    }
    pilha[++topo] = elemento; // Adiciona o elemento e incrementa o topo
}

// Função para remover e retornar o elemento do topo da pilha
int pop() {
    if (topo == -1) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return pilha[topo--]; // Retorna o elemento do topo e decrementa o topo
    }
}

// Função para retornar o elemento do topo da pilha sem removê-lo
int top() {
    if (topo == -1) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return pilha[topo]; // Retorna o elemento do topo
    }
}

// Função para verificar se a pilha está vazia
int estaVazia() {
    return topo == -1;
}

// Função para imprimir o conteúdo da pilha
void imprimir() {
    printf("Conteúdo da pilha:\n");
    for (int i = topo; i >= 0; i--) {
        printf("%d ", pilha[i]); // Imprime cada elemento
    }
    printf("\n");
}

// Função para liberar a memória da pilha
void liberarPilha() {
    free(pilha); // Libera a memória alocada para a pilha
}

int main() {
    inicializarPilha(); // Inicializa a pilha

    push(10);
    push(20);
    push(30);
    imprimir();
    printf("Elemento no topo: %d\n", top());
    printf("Elemento removido: %d\n", pop());
    imprimir();

    liberarPilha(); // Libera a memória antes de terminar o programa
    return 0;
}
