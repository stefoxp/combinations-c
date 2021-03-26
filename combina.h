#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


/* numero massimo di input accettati */
#define MAXDATI 8


/* dichiarazione del tipo struttura per la lista */
typedef struct lista
{
    char        *combinazione;
    struct      lista *succ_p;
} lista_t;


/* prototipi di funzione */
void attraversa_lista(lista_t *testa_p);
int inserisci_in_lista(lista_t **testa_p, char *c);
void concatena_in_lista(lista_t **coda_p, lista_t **testa_p, char *c);
int accoda_lista(lista_t **coda_p, lista_t **testa_p);
char *strdup(char *s);
