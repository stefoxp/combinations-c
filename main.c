#include "combina.h"

int main(void)
{
    char input;
    int c,
        inserito,
        accodato;
    lista_t *mia_lista_p;
    lista_t *tmp_lista_p;
    
    c = 0;
    inserito = 0;
    accodato = 0;
    /*mia_lista_p = (lista_t *)malloc(sizeof(lista_t));*/
    mia_lista_p = NULL;
    /*tmp_lista_p = (lista_t *)malloc(sizeof(lista_t));*/
    
    /* presenta le funzionalit� del programma */
    printf("\t**************************************************\n");
    printf("\t**********  Inserire %d numeri interi.   **********\n",
            MAXDATI);
    printf("\t** Il programma li elaborera' e ne visualizzera'**\n");
    printf("\t**            l'insieme delle parti.            **\n");
    printf("\t**************************************************\n\n");
    
    for(c = 0;
        c < MAXDATI;
        c++)
    {
        printf("\t**************************************************\n");
        printf("\t**   Inserire 1 numero intero e premere Invio   **\n");
        /* acquisisce il numero */
        scanf("%s",
                &input);
        
        /* svuota la lista temporanea per impedire la comparsa di valori duplicati */
        tmp_lista_p = NULL;
        
        concatena_in_lista(&tmp_lista_p,
                            &mia_lista_p,
                            &input);
 
        /* inserisce il singolo elemento in lista */
        inserito = inserisci_in_lista(&mia_lista_p,
                                        &input);
        if(inserito == 1)
            printf("\t**       Elemento acquisito con successo!       **\n");
        else
            printf("\t**  Problemi nell'acquisizione dell'elemento!   **\n");
        
        /* unisce gli elementi della lista temporanea a quelli della lista principale */
        accodato = accoda_lista(&tmp_lista_p,
                                &mia_lista_p);
        if(inserito == 1)
            printf("\t**  Tutte le combinazioni sono state calcolate! **\n");
        else
            printf("\t**  Problemi con il calcolo delle combinazioni! **\n");
        
    }
    
    printf("\t**************************************************\n");
    printf("\n\t**     L'insieme delle parti e' il seguente     **\n");
    printf("\t**************************************************\n\n");
    /* visualizza la lista finale delle combinazioni: insieme delle parti */
    attraversa_lista(mia_lista_p);
    return 0;
}


int inserisci_in_lista(lista_t **testa_p, char *c)
{
    lista_t *corr_p,
            *prec_p,
            *nuovo_p;
    int ris;
    
    for(corr_p = prec_p = *testa_p;
        (corr_p != NULL);
        prec_p = corr_p, corr_p = corr_p->succ_p)
        ;
    
    if (corr_p != NULL)
        ris = 0;
    else
    {
        /* nuova combinazione */
        ris = 1;
        nuovo_p = (lista_t *)malloc(sizeof(lista_t));
        nuovo_p->combinazione = strdup(c);
        nuovo_p->succ_p = corr_p;
        
        if(corr_p == *testa_p)
            *testa_p = nuovo_p;
        else
            prec_p->succ_p = nuovo_p;
    }
    return(ris);
}


void attraversa_lista(lista_t *testa_p)
{
    lista_t *punt;
    int conta;
    
    conta = 0;
    
    for(punt = testa_p;
        punt != NULL;
        punt = punt->succ_p)
    {
        conta++;
            printf("\t**           %da combinazione:\t%s           \n",
                    conta,
                    punt->combinazione);
    }
    printf("\n\t**************************************************\n");
}


void concatena_in_lista(lista_t **coda_p, lista_t **testa_p, char *c)
{
    lista_t *corr_p,
            *prec_p,
            *punt;
    char *s;
    
    for(corr_p = prec_p = *coda_p;
        (corr_p != NULL);
        prec_p = corr_p, corr_p = corr_p->succ_p)
        ;
    
    punt = *testa_p;
    /*for(punt = *testa_p; punt != NULL; punt = punt->succ_p)
    {*/
    if(punt != NULL)
    {
        s = strdup(punt->combinazione);
        /*printf("Prima s vale: %s\n", s);*/
        /* aggiunge uno spazio in fondo */
        s = strcat(s,
                    " ");
        /* unisce il nuovo elemento */
        s = strcat(s,
                    c);
        /*printf("Dopo s vale: %s\n", s);*/
        
        if (corr_p != NULL)
        {
            /*printf("Controllo corr_p non e' NULL\n", s);*/
        }
        else
        {
            lista_t *corr_p,
                    *prec_p,
                    *nuovo_p;
    
            for(corr_p = prec_p = *coda_p;
                (corr_p != NULL);
                prec_p = corr_p, corr_p = corr_p->succ_p)
                ;
            
            if (corr_p != NULL)
                ;
            else
            {
                /* nuova combinazione */
               
                nuovo_p = (lista_t *)malloc(sizeof(lista_t));
                nuovo_p->combinazione = strdup(s);
                nuovo_p->succ_p = corr_p;
                
                if(corr_p == *coda_p)
                    *coda_p = nuovo_p;
                else
                    prec_p->succ_p = nuovo_p;
            }
        }
        punt = punt->succ_p;
        concatena_in_lista(coda_p,
                            &punt,
                            c);
    }
}

int accoda_lista(lista_t **coda_p, lista_t **testa_p)
{
    lista_t *corr_p,
            *prec_p,
            *punt;
    int ris;
   
    ris = 0;
    
    for(corr_p = prec_p = *testa_p;
        (corr_p != NULL);
        prec_p = corr_p, corr_p = corr_p->succ_p)
        ;
   
    for(punt = *coda_p;
        punt != NULL;
        punt = punt->succ_p)
    {
        
        if (corr_p != NULL)
            ris = 0;
        else
        {
            ris = inserisci_in_lista(testa_p,
                                    punt->combinazione);
        }
    }
    return(ris);
}

char *strdup(char *s)
{
    char *p;
    
    p = (char *)malloc(strlen(s) + 1);
    if(p != NULL)
        strcpy(p,
                s);
    
    return p;
}
