#include "lib.h"

int gerarNumeroAleatorio(int min, int max) {
  return min + rand() % (max - min + 1);
}

void inserirH(personagem **head, int hp, int ataque, int pm, char nome[50]) {
  personagem *novoPersonagem = (personagem *)malloc(sizeof(personagem));
  strcpy(novoPersonagem->nome, nome);
  novoPersonagem->hp = hp;
  novoPersonagem->ataque = ataque;
  novoPersonagem->pm = pm;
  novoPersonagem->prox = NULL;

  if (*head == NULL) {
    *head = novoPersonagem;
  } else {
    personagem *temp = *head;
    while (temp->prox != NULL) {
      temp = temp->prox;
    }
    temp->prox = novoPersonagem;
  }
}

void inserirI(inimigo **headI, int hp, int ataque, int pm, int id,
              char nome[50]) {
  inimigo *novoInimigo = (inimigo *)malloc(sizeof(inimigo));
  strcpy(novoInimigo->nome, nome);
  novoInimigo->hp = hp;
  novoInimigo->ataque = ataque;
  novoInimigo->pm = pm;
  novoInimigo->id = id;
  novoInimigo->proxI = NULL;

  if (*headI == NULL) {
    *headI = novoInimigo;
  } else {
    inimigo *tempI = *headI;
    while (tempI->proxI != NULL) {
      tempI = tempI->proxI;
    }
    tempI->proxI = novoInimigo;
  }
}

void imprimirH(personagem *head) {
  personagem *temp = head;
  while (temp != NULL) {
    printf("Personagem: %s\n |HP: %d\n |Ataque: %d\n |Poder Mágico: %d\n\n",
           temp->nome, temp->hp, temp->ataque, temp->pm);
    temp = temp->prox;
  }
}

void imprimirI(inimigo *headI) {
  inimigo *tempI = headI;
  while (tempI != NULL) {
    printf("Inimigo: %s (HP: %d, Ataque: %d, Poder Mágico: %d, ID: %d)\n",
           tempI->nome, tempI->hp, tempI->ataque, tempI->pm, tempI->id);
    tempI = tempI->proxI;
  }
}

void ataque(personagem *personagemAtual, inimigo *inimigoAtual) {
  if (inimigoAtual == NULL) {
    printf("Erro ao escolher o inimigo\n");
  }
  int dice = gerarNumeroAleatorio(1, 100);
  int danoI;
  if (dice >= 90) {
    danoI = inimigoAtual->pm;
    printf("O inimigo está enfurecido!");
  } else {
    danoI = inimigoAtual->ataque;
  }

  // Lógica de ataque
  int dano = personagemAtual->ataque;

  printf("Você atacou o inimigo %s!\n", inimigoAtual->nome);
  printf("\n|Dano causado: %d\n", dano);
  personagemAtual->hp -= danoI;
  inimigoAtual->hp -= dano; // Reduz a vida do inimigo pelo valor do dano

  printf("|Vida restante do inimigo %s: %d\n", inimigoAtual->nome,
         inimigoAtual->hp);

  printf("|Dano recebido por %s foi: %d\n", inimigoAtual->nome, danoI);
  printf("|Sua vida restante:%d\n", personagemAtual->hp);
}
void ataqueMagico(personagem *personagemAtual, inimigo *inimigoAtual) {
  if (inimigoAtual == NULL) {
    printf("Erro ao escolher o inimigo\n");
  }
  int dice = gerarNumeroAleatorio(1, 100);
  int danoI;
  if (dice >= 90) {
    danoI = inimigoAtual->pm;
    printf("O inimigo está enfurecido!");
  } else {
    danoI = inimigoAtual->ataque;
  }

  // Lógica de ataque
  int dano = personagemAtual->pm;

  printf("\nVocê atacou o inimigo %s!\n", inimigoAtual->nome);
  printf("|Dano causado: %d\n", dano);

  inimigoAtual->hp -= dano;
  personagemAtual->hp -= danoI;

  printf("|Vida restante do inimigo %s: %d\n", inimigoAtual->nome,
         inimigoAtual->hp);
  printf("|Dano recebido por %s foi: %d\n", inimigoAtual->nome, danoI);
  printf("|Sua vida restante: %d\n", personagemAtual->hp);
}

void defesa(personagem *personagemAtual, inimigo *inimigoAtual) {
  if (inimigoAtual == NULL) {
    printf("Erro ao escolher o inimigo\n");
  }

  // Lógica de defesa
  int dice = gerarNumeroAleatorio(1, 100);
  int danoI;
  if (dice >= 90) {
    danoI = inimigoAtual->pm;
    printf("O inimigo está enfurecido!");
  } else {
    danoI = inimigoAtual->ataque;
  }
  int dano = danoI / 2;

  printf("Você se defendeu do ataque do inimigo %s!\n", inimigoAtual->nome);
  printf("Dano recebido: %d\n", dano);

  personagemAtual->hp -= dano;

  printf("Sua vida restante: %d\n", personagemAtual->hp);
}

void removerP(personagem **head, char nome[50]) {
  personagem *temp = *head;
  personagem *anterior = NULL;

  if (temp != NULL && strcmp(temp->nome, nome) == 0) {
    *head = temp->prox;
    free(temp);
    return;
  }

  while (temp != NULL && strcmp(temp->nome, nome) != 0) {
    anterior = temp;
    temp = temp->prox;
  }

  if (temp == NULL) {
    printf("Personagem não encontrado\n");
    return;
  }

  anterior->prox = temp->prox;
  free(temp);
}

void removerI(inimigo **headI, int id) {
  inimigo *tempI = *headI;
  inimigo *anteriorI = NULL;

  if (tempI != NULL && tempI->id == id) {
    *headI = tempI->proxI;
    free(tempI);
    return;
  }

  while (tempI != NULL && tempI->id != id) {
    anteriorI = tempI;
    tempI = tempI->proxI;
  }

  if (tempI == NULL) {
    printf("Inimigo não encontrado\n");
    return;
  }

  anteriorI->proxI = tempI->proxI;
  free(tempI);
}

personagem *escolherPersonagem(int escolha, personagem *head) {
  personagem *personagemAtual = NULL;
  switch (escolha) {
  case 1:
    personagemAtual = (personagem *)malloc(sizeof(personagem));
    strcpy(personagemAtual->nome, head->nome);
    personagemAtual->hp = head->hp;
    personagemAtual->ataque = head->hp;
    personagemAtual->pm = head->hp;
    personagemAtual->prox = NULL;
    break;
  case 2:
    personagemAtual = (personagem *)malloc(sizeof(personagem));
    strcpy(personagemAtual->nome, head->prox->nome);
    personagemAtual->hp = head->prox->hp;
    personagemAtual->ataque = head->prox->ataque;
    personagemAtual->pm = head->prox->pm;
    personagemAtual->prox = NULL;
    break;
  case 3:
    personagemAtual = (personagem *)malloc(sizeof(personagem));
    strcpy(personagemAtual->nome, head->prox->prox->nome);
    personagemAtual->hp = head->prox->prox->hp;
    personagemAtual->ataque = head->prox->prox->ataque;
    personagemAtual->pm = head->prox->prox->pm;
    personagemAtual->prox = NULL;
    break;
  default:
    printf("Escolha inválida. Personagem não definido.\n");
  }

  return personagemAtual;
}

void insertionSort(int arr[], int n) {
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}
void liberarMemoriaH(personagem *head) {
  personagem *temp = head;
  while (temp != NULL) {
    personagem *prox = temp->prox;
    free(temp);
    temp = prox;
  }
}

void liberarMemoriaI(inimigo *head) {
  inimigo *temp = head;
  while (temp != NULL) {
    inimigo *prox = temp->proxI;
    free(temp);
    temp = prox;
  }
}

inimigo *buscarI(inimigo *headI, int id) {
  inimigo *temp = headI;
  while (temp != NULL) {
    if (temp->id == id) {
      return temp;
    }
    temp = temp->proxI;
  }
  return NULL;
}

inimigo *escolherInimigoAleatorio(inimigo *headI) {
  int count = 0;
  inimigo *tempI = headI;
  while (tempI != NULL) {
    count++;
    tempI = tempI->proxI;
  }

  if (count == 0) {
    return NULL;
  }

  int escolha = gerarNumeroAleatorio(1, count);

  tempI = headI;
  while (tempI != NULL && escolha > 1) {
    tempI = tempI->proxI;
    escolha--;
  }

  return tempI;
}
