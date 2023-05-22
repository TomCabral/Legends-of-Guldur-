#include "lib.h"

int gerarNumeroAleatorio(int min, int max) {
    int numero = (rand() % (max - min + 1)) + min;
    return numero;
}

void inserirH(personagem **head, int hp, int ataque, int pm, char nome[50]) {
    personagem *novo = (personagem *)malloc(sizeof(personagem));
    if (novo != NULL) {
        strcpy(novo->nome, nome);
        novo->hp = hp;
        novo->ataque = ataque;
        novo->pm = pm;
        novo->prox = *head;
        *head = novo;
    }
}

void inserirI(inimigo **headI, int hp, int ataque, int pm, int id, char nome[50]) {
    inimigo *novoI = (inimigo *)malloc(sizeof(inimigo));
    if (novoI != NULL) {
        strcpy(novoI->nome, nome);
        novoI->hp = hp;
        novoI->ataque = ataque;
        novoI->pm = pm;
        novoI->id = id;
        novoI->proxI = *headI;
        *headI = novoI;
    }
}

void imprimirH(personagem *head) {
    if (head == NULL)
        printf("\nErro na inserção de personagens.");
    else {
        while (head != NULL) {
            printf("Nome: %s\n HP: %d\n Ataque: %d\n PM: %d\n\n", head->nome, head->hp, head->ataque, head->pm);
            head = head->prox;
        }
    }
}

void insertionSort(inimigo **headI) {
    if (*headI == NULL || (*headI)->proxI == NULL) {
        return;  // No need to sort if the list is empty or has only one element
    }

    inimigo *sorted = NULL;  // Sorted list
    inimigo *current = *headI;  // Current node to be sorted

    while (current != NULL) {
        inimigo *next = current->proxI;  // Next node to be sorted
        // Find the correct position to insert the current node in the sorted list
        if (sorted == NULL || current->id < sorted->id) {
            // Insert at the beginning of the sorted list
            current->proxI = sorted;
            sorted = current;
        } else {
            inimigo *temp = sorted;
            while (temp->proxI != NULL && current->id > temp->proxI->id) {
                temp = temp->proxI;
            }
            // Insert current node between temp and temp->proxI
            current->proxI = temp->proxI;
            temp->proxI = current;
        }
        current = next;  // Move to the next node
    }

    *headI = sorted;  // Update the head of the list
}
