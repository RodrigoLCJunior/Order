#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  

struct No {
    int data;
    struct No* esquerda;
    struct No* direita;
};


struct No* novoNo(int data) {
    struct No* No = (struct No*)malloc(sizeof(struct No));
    No->data = data;
    No->esquerda = NULL;
    No->direita = NULL;
    return No;
}

void preOrder(struct No* No, int nivel) {
    if (No == NULL)
        return;
    for (int i = 0; i < nivel; i++) printf("  ");  
    printf("%d\n", No->data); 
    usleep(1000000); 
    preOrder(No->esquerda, nivel + 1);
    preOrder(No->direita, nivel + 1); 
}


void inOrder(struct No* No, int nivel) {
    if (No == NULL)
        return;
    inOrder(No->esquerda, nivel + 1);  
    for (int i = 0; i < nivel; i++) printf("  "); 
    printf("%d\n", No->data);  
    usleep(1000000);  
    inOrder(No->direita, nivel + 1);}

void postOrder(struct No* No, int nivel) {
    if (No == NULL)
        return;
    postOrder(No->esquerda, nivel + 1);  
    postOrder(No->direita, nivel + 1);
    for (int i = 0; i < nivel; i++) printf("  ");  
    printf("%d\n", No->data); 
    usleep(1000000); }

int main() {
    // Criação da árvore de exemplo com 10 números
    struct No* raiz = novoNo(8);
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
