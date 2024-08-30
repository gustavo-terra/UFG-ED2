/*
O código abaixo apresenta a implementação de uma fila e suas operações básicas.

1 - comente o código
2 - implemente uma função para contar o número de elementos na fila.
3 - implemente uma função para limpar todos os elementos da fila, liberando memória apropriadamente.
*/

#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó na fila
typedef struct Node {
    int data; // Dados armazenados no nó
    struct Node* next; // Ponteiro para o próximo nó na fila
} Node;

// Estrutura para representar a fila
typedef struct Queue {
    Node* front; // Ponteiro para o início da fila
    Node* rear;  // Ponteiro para o final da fila
} Queue;

// Função para contar o número de elementos da fila
int qtdElementos(Queue* p) {
    int qtd = 0;
    Node* q = p->front;

    while (q != NULL) { // Condição de quebra é o final da fila -> ponteiro nulo
        qtd++; // Somar +1 para cada nó percorrido na fila
        q = q->next; // Ponteiro aponta para o sucessor, repetir loop
    };

    return qtd; // retorna a quantidade
}

// Função para criar uma nova fila
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue)); // Aloca memória para a fila
    if (q == NULL) {
        printf("Falha na alocação de memória para a fila.\n");
        return NULL;
    }
    q->front = q->rear = NULL; // Inicializa a fila vazia
    return q;
}

// Função para adicionar um elemento à fila
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Cria um novo nó
    if (newNode == NULL) {
        printf("Falha na alocação de memória para o novo nó.\n");
        return;
    }
    newNode->data = value; // Define o valor do novo nó
    newNode->next = NULL; // O novo nó será o último, então seu próximo é NULL
    if (q->rear == NULL) { 
        q->front = q->rear = newNode; // Se a fila está vazia, o novo nó é o início e o final
    } else { 
        q->rear->next = newNode; // O antigo final da fila aponta para o novo nó
        q->rear = newNode; // O novo nó é agora o final da fila
    }
}

// Função para remover e retornar um elemento da fila
int dequeue(Queue* q) {
    if (q->front == NULL) { // Verifica se a fila está vazia
        printf("Fila está vazia.\n");
        return -1; // Retorna -1 para indicar erro
    }
    Node* temp = q->front; // Nó temporário para armazenar o início da fila
    int data = temp->data; // Dados do nó a ser removido
    q->front = q->front->next; // Atualiza o início da fila
    if (q->front == NULL) {
        q->rear = NULL; // Se a fila ficar vazia, atualiza o final também
    }
    free(temp); // Libera a memória do nó removido
    return data; // Retorna o valor removido
}

// Função para verificar se a fila está vazia
int isEmpty(Queue* q) {
    return q->front == NULL; // Retorna 1 se a fila estiver vazia, caso contrário 0
}

void limparFila(Queue *p) {
    while (p->front != NULL) { // Enquanto houver elemento na fila...
        dequeue(p); // Remover nó dela
    }
}

// Função para imprimir os elementos da fila
void printQueue(Queue* q) {
    if (isEmpty(q)) { // Verifica se a fila está vazia
        printf("A fila está vazia.\n");
        return;
    }
    Node* temp = q->front; // Nó temporário para percorrer a fila
    printf("Elementos da fila: ");
    while (temp != NULL) { // Percorre e imprime todos os elementos da fila
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Função principal
int main() {
    Queue* q = createQueue(); // Cria uma nova fila

    enqueue(q, 10); // Adiciona 10 à fila
    enqueue(q, 20); // Adiciona 20 à fila
    enqueue(q, 30); // Adiciona 30 à fila
    printQueue(q); // Imprime o conteúdo da fila
    printf("Quantidade de elementos na fila = %d\n", qtdElementos(q));
    printf("Limpando fila...\n");
    limparFila(q);
    printQueue(q);
    

    return 0;
}
