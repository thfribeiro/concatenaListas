#include "teste.h"

int main()
{
LISTA lista1;
LISTA lista2;
LISTA lista3;
LISTA lista4;
REGISTRO reg;


    inicializar(&lista1);
    inicializar(&lista2);
    inicializar(&lista3);
    inicializar(&lista4);
//-------------------------------------------------------------------
//LISTA 1;
    reg.chave = 8;
    insereElemOrd(&lista1,reg);

    reg.chave = 3;
    insereElemOrd(&lista1,reg);

    reg.chave = 10;
    insereElemOrd(&lista1,reg);
//-------------------------------------------------------------------
//LISTA 2;
    reg.chave = 2;
    insereElemOrdDecres(&lista2,reg);

    reg.chave =4;
    insereElemOrdDecres(&lista2,reg);

    reg.chave = 152;
    insereElemOrdDecres(&lista2,reg);

    reg.chave = 15;
    insereElemOrdDecres(&lista2,reg);

//-------------------------------------------------------------------
//LISTA 3;

    reg.chave = 86;
    insereElemOrdDecres(&lista3,reg);

    reg.chave =42;
    insereElemOrdDecres(&lista3,reg);

    reg.chave = 61;
    insereElemOrdDecres(&lista3,reg);

    reg.chave = 7;
    insereElemOrdDecres(&lista3,reg);

    setFim(&lista1);
    setFim(&lista2);
    setFim(&lista3);

    puts("Lista 1:");
    exibir(&lista1);
    puts("\nLista 2:");
    exibir(&lista2);
    puts("\nLista 3:");
    exibir(&lista3);
    puts("\nLista 4:");
    exibir(&lista4);


    puts("--------------------------------------------");

    fusaoLista(&lista1,&lista2);
    puts("Lista 1 + 2:");
    exibir(&lista2);

    puts("\n--------------------------------------------");

    fusaoLista(&lista2,&lista3);
    puts("Lista 1 + 2 + 3:");
    exibir(&lista3);

    puts("\n--------------------------------------------");
    setLista(&lista3,&lista4);

    puts("Lista 1 + 2 + 3 ordenada:");
    exibir(&lista3);

    desaloc(&lista4);
    limpa(&lista3);

    puts("\n--------------------------------------------");

    puts("Lista 1:");
    exibir(&lista1);
    puts("Lista 2:");
    exibir(&lista2);
    puts("Lista 3:");
    exibir(&lista3);
    puts("Lista 4:");
    exibir(&lista4);

}
