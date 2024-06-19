#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  

struct Node {
    int data;
    struct Node* esquerda;
    struct Node* direita;
};


struct Node* novoNo(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->esquerda = NULL;
    node->direita = NULL;
    return node;
}

void preOrder(struct Node* node, int nivel) {
    if (node == NULL)
        return;
    for (int i = 0; i < nivel; i++) printf("  ");  
    printf("%d\n", node->data); 
    usleep(1000000); 
    preOrder(node->esquerda, nivel + 1);
    preOrder(node->direita, nivel + 1); 
}


void inOrder(struct Node* node, int nivel) {
    if (node == NULL)
        return;
    inOrder(node->esquerda, nivel + 1);  
    for (int i = 0; i < nivel; i++) printf("  "); 
    printf("%d\n", node->data);  
    usleep(1000000);  
    inOrder(node->direita, nivel + 1);}

void postOrder(struct Node* node, int nivel) {
    if (node == NULL)
        return;
    postOrder(node->esquerda, nivel + 1);  
    postOrder(node->direita, nivel + 1);
    for (int i = 0; i < nivel; i++) printf("  ");  
    printf("%d\n", node->data); 
    usleep(1000000); }

int main() {
    // Criação da árvore de exemplo com 10 números
    struct Node* raiz = novoNo(8);
    raiz->esquerda = novoNo(3);
    raiz->direita = novoNo(10);
    raiz->esquerda->esquerda = novoNo(1);
    raiz->esquerda->direita = novoNo(6);
    raiz->direita->direita = novoNo(14);
    raiz->esquerda->direita->esquerda = novoNo(4);
    raiz->esquerda->direita->direita = novoNo(7);
    raiz->direita->direita->esquerda = novoNo(13);
    raiz->direita->direita->direita = novoNo(15);

        printf("Travessia pre-order:\n");
    preOrder(raiz, 0);
    printf("\n");

    printf("Travessia in-order:\n");
    inOrder(raiz, 0);
    printf("\n");

    printf("Travessia post-order:\n");
    postOrder(raiz, 0);
    printf("\n");

    return 0;
}
