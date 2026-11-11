#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <errno.h>

#define NUM_NAVI 10
#define LUNGHEZZA_NOME 100
#define DIMENSIONE_CAMPO 10

static void leggi_nome(const char *messaggio, char nome[LUNGHEZZA_NOME])
{
	printf("%s", messaggio);
	if (fgets(nome, LUNGHEZZA_NOME, stdin) == NULL) {
		nome[0] = '\0';
		return;
	}
	nome[strcspn(nome, "\n")] = '\0';
}

int leggi_intero(const char *messaggio, int *valore)
{
	char riga[128];
	char *fine;
	long numero;

	for (;;) {
		printf("%s", messaggio);
		if (fgets(riga, sizeof riga, stdin) == NULL)
			return 0;
		errno = 0;
		numero = strtol(riga, &fine, 10);
		while (isspace((unsigned char)*fine))
			fine++;
		if (fine != riga && *fine == '\0' && errno != ERANGE &&
		    numero >= -2147483647L - 1 && numero <= 2147483647L) {
			*valore = (int)numero;
			return 1;
		}
		printf("Valore non valido: inserire un numero intero.\n");
	}
}

/* Le navi devono stare nel campo, essere dritte e non sovrapporsi né toccarsi,
   nemmeno in diagonale. */
int tocca_navi_precedenti(const int navi[NUM_NAVI][4], int quantita,
				 const int nave[4])
{
	int r, c, i, pr, pc;
	int r_min = nave[0] < nave[2] ? nave[0] : nave[2];
	int r_max = nave[0] > nave[2] ? nave[0] : nave[2];
	int c_min = nave[1] < nave[3] ? nave[1] : nave[3];
	int c_max = nave[1] > nave[3] ? nave[1] : nave[3];

	for (r = r_min; r <= r_max; r++) {
		for (c = c_min; c <= c_max; c++) {
			for (i = 0; i < quantita; i++) {
				int pr_min = navi[i][0] < navi[i][2] ? navi[i][0] : navi[i][2];
				int pr_max = navi[i][0] > navi[i][2] ? navi[i][0] : navi[i][2];
				int pc_min = navi[i][1] < navi[i][3] ? navi[i][1] : navi[i][3];
				int pc_max = navi[i][1] > navi[i][3] ? navi[i][1] : navi[i][3];

				for (pr = pr_min; pr <= pr_max; pr++) {
					for (pc = pc_min; pc <= pc_max; pc++) {
						if (abs(r - pr) <= 1 && abs(c - pc) <= 1)
							return 1;
					}
				}
			}
		}
	}
	return 0;
}

static int inserisci_navi(const char *giocatore, int navi[NUM_NAVI][4])
{
	int i;
	printf("Tocca al %s\n", giocatore);
	for (i = 0; i < NUM_NAVI;) {
		int nave[4];
		int valida;

		printf("Nave %d\n", i + 1);
		if (!leggi_intero("Inserire la riga della posizione iniziale: ", &nave[0]) ||
		    !leggi_intero("Inserire la colonna della posizione iniziale: ", &nave[1]) ||
		    !leggi_intero("Inserire la riga della posizione finale: ", &nave[2]) ||
		    !leggi_intero("Inserire la colonna della posizione finale: ", &nave[3]))
			return 0;

		valida = nave[0] >= 1 && nave[0] <= DIMENSIONE_CAMPO &&
		         nave[2] >= 1 && nave[2] <= DIMENSIONE_CAMPO &&
		         nave[1] >= 1 && nave[1] <= DIMENSIONE_CAMPO &&
		         nave[3] >= 1 && nave[3] <= DIMENSIONE_CAMPO &&
		         (nave[0] == nave[2] || nave[1] == nave[3]);
		if (!valida) {
			printf("Posizione non valida: coordinate da 1 a %d e nave orizzontale o verticale. Riprova.\n",
			       DIMENSIONE_CAMPO);
			continue;
		}
		if (tocca_navi_precedenti(navi, i, nave)) {
			printf("La nave si sovrappone o tocca un'altra nave. Riprova.\n");
			continue;
		}
		memcpy(navi[i], nave, sizeof nave);
		i++;
	}
	return 1;
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

	if (!inserisci_navi(giocatore1, navi1) ||
	    !inserisci_navi(giocatore2, navi2))
		return 1;

	return 0;
}
