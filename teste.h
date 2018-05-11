#ifndef TESTE_H_INCLUDED
#define TESTE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int TIPOCHAVE;

typedef struct{

TIPOCHAVE chave;

}REGISTRO;

typedef struct aux{

REGISTRO reg;
struct aux* prox;
struct aux* ant;

}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{

PONT inicio;
PONT fim;

}LISTA;

//PROTOTIPO

void inicializar(LISTA *l);

void exibir(LISTA *l);

void reinicializar(LISTA *l);

void insereElemOrd(LISTA *l, REGISTRO reg);

void insereElemOrdDecres(LISTA *l, REGISTRO reg);

PONT buscaElemLista(LISTA *l, TIPOCHAVE ch);

void excluiElem(LISTA *l, TIPOCHAVE ch);

void fusaoLista(LISTA *l1, LISTA *l2);

void setLista(LISTA *l1, LISTA *l2);

void desaloc(LISTA *l1);

#endif // TESTE_H_INCLUDED
