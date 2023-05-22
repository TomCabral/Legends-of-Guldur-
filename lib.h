#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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
void inserirI(inimigo **headI, int hp, int ataque, int pm, int id, char nome[50]);
void imprimirH(personagem *head);
void insertionSort(inimigo **headI);

#endif  // LIB_H
