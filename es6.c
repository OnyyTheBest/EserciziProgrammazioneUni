/*
Esprimete con le strutture di controllo 
fondamentali un algoritmo per il calcolo 
della somma di una sequenza di interi fornita 
in ingresso dall’utente. 
Si supponga che l’inserimento di 0 indichi il termine 
della sequenza.
*/
#include <stdio.h>

int main() {
    int x = 0;
    int res = 0;
    int risultato = 0;
    // questi cicli controllano che il numero inserito sia effettivamente un numero intero e non un carattere o un altro tipo di dato
    do {
        printf("Inserisci un numero: ");
        res = scanf("%d", &x);

        if (res != 1) {
            printf("Input non valido! Riprova.\n");

            // Con questo while svuotiamo il buffer di input in modo tale che il loop non continui all'infinito (\n viene considerato un carattere e non un numero intero!)
            while (getchar() != '\n');
        }

        risultato = risultato + x;
    } while (res != 1 || x != 0);

    printf("%d", risultato);
}