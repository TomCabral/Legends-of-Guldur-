#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INIMIGOS 10

typedef struct personagem {
  char nome[50];
  int hp;
  int ataque;
  int pm;
  struct personagem *prox;
} personagem;

typedef struct inimigo {
  char nome[50];
  int hp;
  int ataque;
  int pm;
  int id;
  struct inimigo *proxI;
} inimigo;

int gerarNumeroAleatorio(int min, int max);
void inserirH(personagem **head, int hp, int ataque, int pm, char nome[50]);
void inserirI(inimigo **headI, int hp, int ataque, int pm, int id,
              char nome[50]);
void imprimirH(personagem *head);
void imprimirI(inimigo *headI);
void ataque(personagem *personagemAtual, inimigo *inimigoAtual);
void ataqueMagico(personagem *personagemAtual, inimigo *inimigoAtual);
void defesa(personagem *personagemAtual, inimigo *inimigoAtual);
void removerP(personagem **head, char nome[50]);
void removerI(inimigo **headI, int id);
personagem *escolherPersonagem(int escolha, personagem *head);
void insertionSort(int arr[], int n);
void liberarMemoriaH(personagem *head);
void liberarMemoriaI(inimigo *headI);
inimigo *escolherInimigoAleatorio(inimigo *headI);

#endif // LIB_H
