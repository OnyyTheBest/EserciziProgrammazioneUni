/*
Ripetete l’esercizio 1.4, 
senza utilizzare prodotto e divisione.

Suggerimento: combinate in maniera opportuna gli algoritmi
ottenuti per risolvere gli esercizi 1.2 e 1.4.
*/

#include <stdio.h>

int main() {
    int x = 0;
    int y = 0;
    int res = 0;
    int i = 0;


    // questi cicli controllano che il numero inserito sia effettivamente un numero intero e non un carattere o un altro tipo di dato
    do {
        printf("Inserisci il primo numero: ");
        res = scanf("%d", &x);

        if (res != 1) {
            printf("Input non valido! Riprova.\n");

            // Con questo while svuotiamo il buffer di input in modo tale che il loop non continui all'infinito (\n viene considerato un carattere e non un numero intero!)
            while (getchar() != '\n');
        }

    } while (res != 1 || x < 0);

    do {
        printf("Inserisci il secondo numero: ");
        res = scanf("%d", &y);

        if (res != 1) {
            printf("Input non valido! Riprova.\n");

            
            while (getchar() != '\n');
        }

    } while (res != 1 || y < 0);


    

    //cicliamo sulla variabile i finche' non raggiunge il valore dell'esponente
    while (i < y) {
        // ci affidiamo ad una variabile temporanea e ad un altra variabile contatore per replicare la moltiplicazione
        int temp = 0;
        int j = 0;
        // moltiplichiamo sommando il numero della base a se stesso x volte
        while (j < x) {
            temp = temp + res;
            j++;
        }
        // facciamo diventare la variabile temporanea il nostro risultato
        res = temp;
        i++;
    }

    // stampiamo il risultato e chiudiamo con return 0.
    printf("%d", res);
    return 0;
}