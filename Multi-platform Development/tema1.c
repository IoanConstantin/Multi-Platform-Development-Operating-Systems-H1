#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINIEMAX 20000
#include "header.h"
#include "compare.h"

/* Functia care insereaza un element (nume, prioritate) in coada */
lista *insert(lista *coada, int priority, char *word)
{
	lista *nod, *p;
	lista *c = coada;
	nod = malloc(sizeof(lista));

	if(nod == NULL)
		exit(12);
	else {
		nod->prioritate = priority;
		strcpy(nod->cuvant, word);
		nod->urm = NULL;
		if(coada == NULL)
			return nod;
		/* Inserare la inceputul cozii */
		if(compare(c->prioritate, priority) <= 0)
		{
			nod->urm = c;
			c = nod;
			return c;
		}
		/* Parcurg lista pana gasesc un element cu prioritate
		 * mai mica decat elementul inserat. Daca nu gasesc
		 * inserez la sfarsitul cozii. */
		while(compare(c->prioritate, priority) > 0)
		{
			if(c->urm != NULL)
			{
				p = c;
				c = c->urm;
			} else {
				c->urm = nod;
				return coada;
			}
		}
		/* Odata ajuns la locul in care trebuie inserat elementul
		   stabilesc legaturile lui folosindu-ma de c (urmatorul
		   element din lista) si de p (precedentul element din
		   lista, retinut la parcurgerea de mai sus). */
		if(compare(c->prioritate, priority) <= 0)
		{
			nod->urm = c;
			p->urm = nod;
			return coada;
		}
		else return coada;
	}
}

/* Returneaza primul element din lista. */
lista *top(lista *coada)
{
	lista *c = coada;
	if(coada == NULL) return NULL;
	return c;
}

/* Elimina primul element din lista. */
lista *pop(lista *coada)
{
	lista *c = coada;
	if(coada == NULL) return NULL;
	coada = coada->urm;
	free(c);
	return coada;
}

lista *coadaPrioritati = NULL;

int main(int argc, char *argv[])
{
	char linie[LINIEMAX];
	int i, j, contorSpace;
	FILE *fp1;
	if(argc > 1)
	{	
		/* Fiecare fisier existent dat ca argument se
		   citeste linie cu linie si se verifica pentru
		   fiecare linie ce comanda valida reprezinta. */
		for(i = 1;i < argc;i++)
		{
			if(fopen(argv[i], "r"))
			{		
				fp1 = fopen(argv[i], "r");
				while(fgets(linie, LINIEMAX, fp1))
				{
					int flagInsert = 0;
					if(strcmp(linie, "top\n") == 0)
					{
						lista *c = top(coadaPrioritati);
						if(c == NULL) printf("\n");
						else printf("%s\n", c->cuvant);
					}
					if(strcmp(linie, "pop\n") == 0)
					{
						coadaPrioritati = pop(coadaPrioritati);
					}
					/* Se verifica daca primele 8 caractere 
					 * ale liniei formeaza "insert " si se 
					 * numara spatiile pentru a ne asigura ca
					 * insert-ul este valid. Se imparte string-ul 
					 * in token-uri folosind delimitatorul " ". */
					contorSpace = 0;
					for(j = 0;j < strlen(linie);j++)
						if(linie[j] == ' ') contorSpace++;
					if(linie[0] == 'i' && linie[1] == 'n' && linie[2] == 's' &&
					   linie[3] == 'e' && linie[4] == 'r' && linie[5] == 't' &&
					   linie[6] == ' ' && linie[7] != ' ')
						flagInsert = 1;
					if(flagInsert == 1 && contorSpace == 2)
					{
						char cuv[LINIEMAX];
						int prior;
						int contorCuvinteAceeasiLinie = 0;
						char *tok;
						tok = strtok(linie, " ");
						while(tok != NULL)
						{
							contorCuvinteAceeasiLinie++;
							if(contorCuvinteAceeasiLinie == 2)
								strcpy(cuv, tok);
							if(contorCuvinteAceeasiLinie == 3)
								prior = atoi(tok);
							tok = strtok(NULL, " ");
						}
						coadaPrioritati = insert(coadaPrioritati, prior, cuv);
					}
				}
				fclose(fp1);
			}
		}
	} else {
		/* Se citeste de la tastatura si se verifica
	   	comenzile precum mai sus. */ 
		while(fgets(linie, LINIEMAX, stdin))
		{
			int flagInsert = 0;
			if(strcmp(linie, "top\n") == 0)
			{
				lista *c = top(coadaPrioritati);
				if(c == NULL)
					printf("\n");
				else printf("%s\n",c->cuvant);
			}
			if(strcmp(linie, "pop\n") == 0)
			{
				coadaPrioritati = pop(coadaPrioritati);
			}
			contorSpace = 0;
			for(i = 0;i < strlen(linie);i++)
				if(linie[i] == ' ') contorSpace++;
			if(linie[0] == 'i' && linie[1] == 'n' && linie[2] == 's' &&
			   linie[3] == 'e' && linie[4] == 'r' && linie[5] == 't' &&
			   linie[6] == ' ' && linie[7] != ' ') flagInsert = 1;
			if(flagInsert == 1 && contorSpace == 2)
			{
				char cuv[LINIEMAX];
				int prior;
				int contorCuvinteAceeasiLinie = 0;
				char *tok;
				tok = strtok(linie, " ");
				while(tok != NULL)
				{
					contorCuvinteAceeasiLinie++;
					if(contorCuvinteAceeasiLinie == 2)
						strcpy(cuv, tok);
					if(contorCuvinteAceeasiLinie == 3)
						prior = atoi(tok);
					tok = strtok(NULL, " ");
				}
				coadaPrioritati = insert(coadaPrioritati, prior, cuv);
			}
		}
	}
	return 0;
}
