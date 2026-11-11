#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_NAVI 10
#define LUNGHEZZA_NOME 100

static void leggi_nome(const char *messaggio, char nome[LUNGHEZZA_NOME])
{
	printf("%s", messaggio);
	if (fgets(nome, LUNGHEZZA_NOME, stdin) == NULL) {
		nome[0] = '\0';
		return;
	}
	nome[strcspn(nome, "\n")] = '\0';
}

static void inserisci_navi(const char *giocatore, int navi[NUM_NAVI][4])
{
	printf("Tocca al %s\n", giocatore);
	int i = 0;
    while (i < NUM_NAVI) {
		printf("Nave %d\n", i + 1);
		printf("Inserire la riga della posizione iniziale: ");
		scanf("%d", &navi[i][0]);
		printf("Inserire la colonna della posizione iniziale: ");
		scanf("%d", &navi[i][1]);
		printf("Inserire la riga della posizione finale: ");
		scanf("%d", &navi[i][2]);
		printf("Inserire la colonna della posizione finale: ");
		scanf("%d", &navi[i][3]);
        i++;
    }
}

int main(void)
{
	char nome1[LUNGHEZZA_NOME];
	char nome2[LUNGHEZZA_NOME];
	int navi1[NUM_NAVI][4];
	int navi2[NUM_NAVI][4];

	leggi_nome("Inserire il nome del primo giocatore: ", nome1);
	do {
		leggi_nome("Inserire il nome del secondo giocatore: ", nome2);
		if (strcmp(nome2, nome1) == 0) {
			printf("ERRORE\n");
		}
	} while (strcmp(nome2, nome1) == 0);

	srand((unsigned int)time(NULL));
	int numero = rand() % 2;
	const char *giocatore1 = (numero == 0) ? nome1 : nome2;
	const char *giocatore2 = (numero == 0) ? nome2 : nome1;

	inserisci_navi(giocatore1, navi1);
	inserisci_navi(giocatore2, navi2);

	return 0;
}
