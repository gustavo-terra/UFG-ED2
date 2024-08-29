/*
O código apresenta uma lista duplamente ligada com operações básicas para inserir, deletar e imprimir.

1 - comente o código.
2 - Modifique a operação de inserção de dados, para que o usuário seja capaz de inserir valores para a lista.
3 - Faça uma operação de buscar por um valor específico, informado pelo usuário, onde o programa deve apresentar se o valor foi encontrado e, em caso afirmativo, exibir detalhes(vizinhos) do nó correspondente.
*/

#include <stdio.h>
#include <stdlib.h>

// tipo abstrato de dado Node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
// Node possui: valor inteiro; ponteiro pra sucessor; ponteiro pra antecessor

Node* head = NULL;

void buscarValor() {
    printf("Insira um valor para ser procurado: ");
    int value;
    scanf("%d", &value);
    Node* percorre = head;
    do {
        if (percorre->data == value) {
            printf("No encontrado\n");
            if (percorre->prev != NULL) {
                printf("Vizinho anterior = %d\n", percorre->prev->data);
            }
            if (percorre->next != NULL) {
                printf("Vizinho sucessor = %d\n", percorre->next->data);
            }
            break;
        }
        percorre = percorre->next;
    } while (percorre != head);
}

// inserir no ao inicio
void insertFront() {
    printf("Insira um valor para criação do nó: ");
    int value;
    scanf("%d", &value);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

// deletar nó recebido
void deleteNode(Node* node) {
    if (node == head)
        head = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;
    if (node->prev != NULL)
        node->prev->next = node->next;
    free(node);
}


// imprimir valores de "data" de cada nó
void printList() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insertFront();
    insertFront();
    insertFront();
    printList();
    buscarValor();
    
    return 0;
}
