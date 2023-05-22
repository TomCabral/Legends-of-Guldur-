#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lib.h"

int main() {
    srand(time(NULL));
    personagem *head = NULL;
    inimigo *headI = NULL;

    // Declaração dos personagens
    inserirH(&head, 100, 55, 100, "Guerreiro Infernal");
    inserirH(&head, 80, 32, 140, "Mago de Gelo");
    inserirH(&head, 90, 40, 120, "Arqueira florestal");

    // Declaração dos inimigos
    inserirI(&headI, 140, 4, 15, gerarNumeroAleatorio(1, 40), "Lamina das Sombras");
    inserirI(&headI, 100, 8, 12, gerarNumeroAleatorio(1, 40), "Cavaleiro Espectral");
    inserirI(&headI, 170, 6, 20, gerarNumeroAleatorio(1, 40), "Servo do Abismo");
    inserirI(&headI, 200, 24, 40, "Arauto do Crepúsculo");
    inserirI(&headI, 400, 2, 6, gerarNumeroAleatorio(1, 40), "Guardião das Trevas");
    inserirI(&headI, 220, 24, 17, gerarNumeroAleatorio(1, 40), "Artorias");
    inserirI(&headI, 230, 27, 16, gerarNumeroAleatorio(1, 40), "espreitador sombrio");
    inserirI(&headI, 240, 26, 18, gerarNumeroAleatorio(1, 40), "Legião ardente");
    inserirI(&headI, 250, 29, 19, gerarNumeroAleatorio(1, 40), "Soldado do desespero");
    inserirI(&headI, 270, 30, 20, gerarNumeroAleatorio(1, 40), "Lorde das cinzas gwyn");

    // Sort the enemies based on their ID using Insertion Sort
    insertionSort(&headI);

    // Exibição dos personagens
    printf("Lista de Personagens:\n");
    imprimirH(head);

    // Exibição dos inimigos ordenados por ID
    printf("Lista de Inimigos (ordenados por ID):\n");
    inimigo *tempI = headI;
    while (tempI != NULL) {
        printf("ID: %d\nNome: %s\nHP: %d\nAtaque: %d\nPM: %d\n\n", tempI->id, tempI->nome, tempI->hp, tempI->ataque, tempI->pm);
        tempI = tempI->proxI;
    }

    return 0;
}
