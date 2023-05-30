#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INIMIGOS 10

int main() {
  srand(time(NULL));
  personagem *head = NULL;
  inimigo *headI = NULL;

  // Declaração dos personagens
  inserirH(&head, 140, 55, 100, "Guerreiro Infernal");
  inserirH(&head, 4777770, 1000000, 160, "Mago de Gelo");
  inserirH(&head, 110, 40, 114, "Arqueira florestal");

  // Declaração dos inimigos
  inserirI(&headI, 140, 4, 15, 1, "Lamina das Sombras");
  inserirI(&headI, 100, 8, 12, 2, "Cavaleiro Espectral");
  inserirI(&headI, 170, 6, 20, 3, "Servo do Abismo");
  inserirI(&headI, 200, 24, 40, 4, "Arauto do Crepúsculo");
  inserirI(&headI, 400, 2, 6, 5, "Guardião das Trevas");
  inserirI(&headI, 220, 24, 17, 6, "Artorias");
  inserirI(&headI, 230, 27, 16, 7, "Espreitador sombrio");
  inserirI(&headI, 240, 26, 18, 8, "Legião ardente");
  inserirI(&headI, 250, 29, 19, 9, "Soldado do desespero");
  inserirI(&headI, 270, 30, 20, 10, "Lorde das cinzas gwyn");

  printf("Lista de Personagens:\n");
  imprimirH(head);

  int aux;
  personagem *personagemAtual = NULL;
  inimigo *inimigoAtual;
  inimigoAtual = escolherInimigoAleatorio(headI);
  int escolha;
  do {
    int aux = 0;
    printf("Escolha o seu personagem:\n");
    printf("1. Personagem 1\n");
    printf("2. Personagem 2\n");
    printf("3. Personagem 3\n");
    printf("0. Sair\n");
    scanf("%d", &escolha);

    switch (escolha) {
    case 1:
      personagemAtual = escolherPersonagem(1, head);
      break;
    case 2:
      personagemAtual = escolherPersonagem(2, head);
      break;
    case 3:
      personagemAtual = escolherPersonagem(3, head);
      break;
    case 0:
      printf("Encerrando o jogo.\n");
      break;
    default:
      printf("Escolha inválida. Tente novamente.\n");
      aux = 1;
      break;
    }
  } while (aux);
  printf("\nPersonagem escolhido: %s\n", personagemAtual->nome);
  int ids[MAX_INIMIGOS];
  char inimigosBatalhados[MAX_INIMIGOS][50];
  int numInimigosBatalhados = 0;
  printf("inimigo atual: %s", inimigoAtual->nome);
  do {
    printf("\nOpções de ação:\n");
    printf("1. Atacar\n");
    printf("2. Atacar com poder mágico\n");
    printf("3. Defender\n");
    printf("Opção: ");
    scanf("%d", &escolha);

    switch (escolha) {
    case 1: {
      if (personagemAtual->hp > 0) {
        int confirmacao;
        printf("\nVocê escolheu atacar. Confirme a ação (1 para confirmar, 0 "
               "para cancelar): ");
        scanf("%d", &confirmacao);
        if (confirmacao == 1) {
          ataque(personagemAtual, inimigoAtual);
          if (inimigoAtual->hp <= 0) {
            ids[numInimigosBatalhados] = inimigoAtual->id;
            strcpy(inimigosBatalhados[ids[numInimigosBatalhados] - 1],
                   inimigoAtual->nome);
            numInimigosBatalhados++;
            removerI(&headI, inimigoAtual->id);
            inimigoAtual = escolherInimigoAleatorio(headI);
            if (headI == NULL) {
              printf("\nTodos os inimigos foram derrotados!\n");
              break;
            }
          }
          printf("\nPersonagem: %s |HP: %d\n", personagemAtual->nome,
                 personagemAtual->hp);
          printf("Inimigo: %s |HP: %d\n", inimigoAtual->nome, inimigoAtual->hp);
        } else {
          printf("Ação cancelada.\n");
        }
      }
      break;
    }
    case 2: {
      if (personagemAtual->hp > 0) {
        int confirmacao;
        printf("Você escolheu atacar com poder mágico. Confirme a ação (1 para "
               "confirmar, 0 para cancelar): ");
        scanf("%d", &confirmacao);
        if (confirmacao == 1) {
          ataqueMagico(personagemAtual, inimigoAtual);
          if (inimigoAtual->hp <= 0) {
            // eu sou um monstro em C
            ids[numInimigosBatalhados] = inimigoAtual->id;
            strcpy(inimigosBatalhados[ids[numInimigosBatalhados]],
                   inimigoAtual->nome);
            numInimigosBatalhados++;
            removerI(&headI, inimigoAtual->id);
            if (headI != NULL) {
              inimigoAtual = escolherInimigoAleatorio(headI);
            }
            if (headI == NULL) {
              printf("\nTodos os inimigos foram derrotados!\n");
              break;
            }
          }
          printf("\nPersonagem: %s |HP: %d\n", personagemAtual->nome,
                 personagemAtual->hp);
          printf("Inimigo: %s |HP: %d\n", inimigoAtual->nome, inimigoAtual->hp);
        } else {
          printf("Ação cancelada.\n");
        }
      }
      break;
    }
    case 3: {
      if (personagemAtual->hp > 0) {
        int confirmacao;
        printf("Você escolheu defender. Confirme a ação (1 para confirmar, 0 "
               "para cancelar): ");
        scanf("%d", &confirmacao);
        if (confirmacao == 1) {
          defesa(personagemAtual, inimigoAtual);
          printf("\nPersonagem: %s (HP: %d)\n", personagemAtual->nome,
                 personagemAtual->hp);
          printf("Inimigo: %s (HP: %d)\n", inimigoAtual->nome,
                 inimigoAtual->hp);
        } else {
          printf("Ação cancelada.\n");
        }
      }
      break;
    }
    default:
      printf("\nOpção inválida. Tente novamente.\n");
      break;
    }
  } while (personagemAtual->hp > 0 && headI != NULL);

  if (personagemAtual->hp <= 0) {
    printf("\nVocê foi derrotado. Fim de jogo.\n");
    free(personagemAtual);
  } else {
    printf("\nParabéns! Você derrotou todos os inimigos. Fim de jogo.\n");
  }
  insertionSort(ids, numInimigosBatalhados);
  if (numInimigosBatalhados == 0) {
    printf("Nenhum inimigo foi vencido.\n");
  } else {
    printf("\nLista de inimigos vencidos:\n");
    insertionSort(ids, numInimigosBatalhados);
    for (int i = 0; i < numInimigosBatalhados; i++) {
      printf("%d. %s\n", i + 1, inimigosBatalhados[ids[i] - 1]);
    }
  }

  liberarMemoriaH(head);
  liberarMemoriaI(headI);

  return 0;
}
