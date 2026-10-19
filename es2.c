/*
Esprimete con le strutture di controllo fondamentali 
un algoritmo per il calcolo del prodotto di due numeri interi,
utilizzando esclusivamente operazioni di somma.
*/
#include <stdio.h>


int main() {
    int x = 0;
    int y = 0;

     int res = 1;

    // questi cicli controllano che il numero inserito sia effettivamente un numero intero e non un carattere o un altro tipo di dato
    do {
        printf("Inserisci il primo fattore: ");
        res = scanf("%d", &x);

        if (res != 1) {
            printf("Input non valido! Riprova.\n");

            // Con questo while svuotiamo il buffer di input in modo tale che il loop non continui all'infinito (\n viene considerato un carattere e non un numero intero!)
            while (getchar() != '\n');
        }

    } while (res != 1);

    do {
        printf("Inserisci il secondo fattore: ");
        res = scanf("%d", &y);

        if (res != 1) {
            printf("Input non valido! Riprova.\n");

            
            while (getchar() != '\n');
        }

    } while (res != 1);


    // inizializiamo un contatore per contare tutte le volte che viene moltiplicato il numero per se stesso
    int i = 0;

    // azzeriamo la variabile res a zero per poterla riusare e non allocare altro spazio inutilmente
    res = 0;
    // sommiamo a res la variabile x per un numero y di volte. 
    while(i<y) {
        res = res + x;
        i++;
    }

    // stampiamo il risultato e chiudiamo il programma
    printf("%s%d\n", "Il totale della moltiplicazione e': ", res);

    return 0;
}