#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int gerarNumeroAleatorio(int min, int max) {
    int numero = (rand() % (max - min + 1)) + min;
    return numero;
}

typedef struct personagem{
    char nome[50];
    int hp;
    int ataque;
    int pm;
    struct personagem *prox;
} personagem;

typedef struct inimigo{
    char nome[50];
    int hp;
    int ataque;
    int pm;
    int id;
    struct inimigo *proxI;
} inimigo;

//insere o um heroi em uma lista simplesmente encadeada 
void inserirH(personagem **head, int hp, int ataque, int pm, char nome[50]) {
  personagem *novo = (personagem *) malloc(sizeof(personagem));
  if (novo != NULL){
    strcpy(novo->nome, nome);  
    novo->hp = hp;
    novo->ataque = ataque;
    novo->pm = pm;
    novo->prox = *head;
    *head = novo;
  }
}
//insere um inimigo em uma lista simplesmente encadeada
void inserirI(inimigo **headI, int hp, int ataque, int pm, char nome[50]) {
  inimigo *novoI = (inimigo *) malloc(sizeof(inimigo));
  if (novoI != NULL){
    int id = gerarNumeroAleatorio(1, 40);
    strcpy(novoI->nome, nome);  
    novoI->hp = hp;
    novoI->ataque = ataque;
    novoI->pm = pm;
    novoI->id = id;
    novoI->proxI = *headI;
    *headI = novoI;
  }
}

//imprime a lista de herois
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




int main() {
    srand(time(NULL));
    personagem *head = NULL;
    inimigo *headI = NULL;

    
    //Declaração dos personagens
    inserirH(&head, 100, 55, 100, "Guerreiro Infernal");
    inserirH(&head, 80, 32, 140, "Mago de Gelo");
    inserirH(&head, 90, 40, 120, "Arqueira florestal");
  
    //Declaração dos inimigos
    inserirI(&head, 140, 4, 15, gerarNumeroAleatorio(1, 40),"Lamina das Sombras");
    inserirI(&head, 100, 8, 12, gerarNumeroAleatorio(1, 40),"Cavaleiro Espectral");
    inserirI(&head, 170, 6, 20, gerarNumeroAleatorio(1, 40),"Servo do Abismo");
    inserirI(&head, 200, 24, 40,"Arauto do Crepúsculo");
    inserirI(&head, 400, 2, 6, gerarNumeroAleatorio(1, 40),"Guardião das Trevas");
    

  
      inserirI(&headI, 220, 24, 17, "Artorias");

inserirI(&headI, 230, 27, 16,  "Espreitador sombrio");

inserirI(&headI, 240, 26, 18, "Legião ardente");

inserirI(&headI, 250, 29, 19, "Soldado do desespero");

inserirI(&headI, 270, 30, 20, "Lorde das cinzas gwyn");
        
   


  
   //Exibição dos personagens 
    imprimirH(head);
    return 0;
}
