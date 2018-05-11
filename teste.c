#include "teste.h"


void inicializar(LISTA *l){

    l->inicio = NULL;

}

void exibir(LISTA *l){

PONT aux=l->inicio;

while(aux != NULL){

    printf("[%d]",aux->reg.chave);
    aux=aux->prox;
}
}

void reinicializar(LISTA *l){

PONT aux=l->inicio;

while(aux != NULL){

    l->inicio = l->inicio->prox;
    free(aux);
    aux=l->inicio;

}


}

void setFim(LISTA *l){
PONT aux=l->inicio;

while(aux != NULL){

if(aux->prox==NULL){
    l->fim=aux;
}
aux=aux->prox;
}
}


void insereElemOrd(LISTA *l, REGISTRO reg){

PONT atual = NULL;
PONT ant = NULL;
PONT novo = NULL;

novo = (PONT) malloc (sizeof (ELEMENTO));

if(novo == NULL){

    printf("\n\n Erro de alocacao: inserir elemento");
    return;

}

novo->reg = reg;
novo->prox = NULL;
novo->ant = NULL;

atual = l-> inicio;

while(atual != NULL && atual -> reg.chave < reg.chave){

    ant = atual;
    atual = atual->prox;

}

novo->prox = atual;
novo->ant = ant;

if(ant == NULL){
    l->inicio = novo;
    if(atual != NULL){
        atual->ant = novo;
    }
}
else{
    ant->prox = novo;
    if(atual != NULL){
        atual -> ant=novo;
    }
}
}

void insereElemOrdDecres(LISTA *l, REGISTRO reg){

PONT atual = NULL;
PONT ant = NULL;
PONT novo = NULL;

novo = (PONT) malloc (sizeof (ELEMENTO));

if(novo == NULL){

    printf("\n\n Erro de alocacao: inserir elemento");
    return;

}

novo->reg = reg;
novo->prox = NULL;
novo->ant = NULL;

atual = l-> inicio;

while(atual != NULL && atual -> reg.chave > reg.chave){

    ant = atual;
    atual = atual->prox;

}

novo->prox = atual;
novo->ant = ant;

if(ant == NULL){
    l->inicio = novo;
    if(atual != NULL){
        atual->ant = novo;
    }
}
else{
    ant->prox = novo;
    if(atual != NULL){
        atual -> ant=novo;
    }
}


}

void fusaoLista(LISTA *l1, LISTA *l2){

PONT atual1;
PONT ant;
PONT atual2;
PONT ant2;

atual1 = l1->inicio;
atual2 = l2->fim;
ant=NULL;
ant2=l2->fim->ant;

while(atual1 != NULL && atual1 -> reg.chave < atual2->reg.chave){
    ant=atual1;
    atual1=atual1->prox;
    ant2=atual2;
    atual2=atual2->ant;
}

atual1->ant=atual2;
atual2->prox=atual1;
if(atual2->prox==NULL){
l1->inicio=atual2;
}
l2->fim=atual2->ant;

l1->inicio=NULL;
l1->fim=NULL;
}

void setLista(LISTA *l1, LISTA *l2){

  PONT i, j, min, aux;

  for (i = l1->inicio; i!=NULL; i=i->prox) {
    min = i;
    for (j = i->prox; j!=NULL; j=j->prox) {
      if (j->reg.chave < min->reg.chave) {
        min = j;
      }
    }
    if (i->reg.chave != min->reg.chave) {
      aux->reg.chave = i->reg.chave;
      i->reg.chave = min->reg.chave;
      min->reg.chave = aux->reg.chave;
    }
  }
l2->inicio=l1->inicio;
l2->fim=l1->fim;
}

void desaloc(LISTA *l){
    PONT atual;
    PONT ant;
    PONT aux;

 for(atual = l->inicio; atual != NULL; atual = atual -> prox ){
        ant = NULL;

        for(aux = atual -> prox; aux != NULL; ){ //sem incremento
            if(atual->reg.chave==aux->reg.chave){ //teste de igual
                if(ant == NULL){ //remove do inicio
                    atual -> prox = aux -> prox;
                }
                else{ //ou do meio/fim
                    ant -> prox = aux -> prox;
                }

                PONT remover = aux;
                aux = aux -> prox;
                free(remover);
            }
            else { //so atualiza o anterior quando não é igual
                ant = aux;
                aux = aux->prox;
            }
        }
    }

}

void limpa(LISTA *l){
l->inicio=NULL;
l->fim=NULL;
}


void excluiElem(LISTA *l, TIPOCHAVE ch){

    PONT atual = l->inicio;
    PONT ant = NULL;

    while(atual != NULL && atual->reg.chave < ch){
        ant = atual;
        atual = atual->prox;
    }

    if(atual == NULL){
        printf("\n\nElemento nao esta na lista");
    }

    else{

        if(atual -> reg.chave != ch){
            printf("\n\nElemento nao foi excluido");
        }

        else{
            if(ant == NULL){
                l->inicio = atual->prox;
                l->inicio->ant = NULL;
            }
            else{
                ant->prox = atual->prox;
                if(atual->prox != NULL){
                        atual->prox->ant = ant;
                }

            free(atual);
            printf("\n\nElemento %d excluido com sucesso\n", ch);
            }
    }
}
}



