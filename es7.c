/*
Esprimete con le strutture di controllo fondamentali 
un algoritmo per il calcolo della media di tutti i numeri 
pari e della media di tutti i numeri dispari in una sequenza
di interi, fornita in ingresso dall’utente. 
Si supponga che l’inserimento di 0 indichi il termine
della sequenza (0 non fa parte della sequenza). 
Si indichi infine quale delle due medie è più grande.
*/
#include <stdio.h>

int main() {
    int x = 0;
    int res = 0;
    int somma_p = 0;
    int somma_d = 0;
    int i = 0;
    int j = 0;
    // questi cicli controllano che il numero inserito sia effettivamente un numero intero e non un carattere o un altro tipo di dato
    do {
        printf("Inserisci un numero: ");
        res = scanf("%d", &x);

        if (res != 1) {
            printf("Input non valido! Riprova.\n");

            // Con questo while svuotiamo il buffer di input in modo tale che il loop non continui all'infinito (\n viene considerato un carattere e non un numero intero!)
            while (getchar() != '\n');
        }

        if((x % 2) == 0) {
            somma_p += x;
            i++;
        } else {
            somma_d += x;
            j++;
        }
    } while (res != 1 || x != 0);

    float media_p = somma_p / i;
    float media_d = somma_d / j;

    if(media_d > media_p) {
        printf("%s", "la media dei numeri dispari e' piu' grande.");
        return 0;
    }

    printf("%s", "La media dei numeri pari e' piu' grande.");
    return 0;
}