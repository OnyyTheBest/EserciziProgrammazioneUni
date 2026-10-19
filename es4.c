/*
Esprimete con le strutture di controllo fondamentali
un algoritmo per il calcolo della potenza x^y 
di due numeri interi x e y, 
utilizzando esclusivamente le 4 operazioni di somma, 
sottrazione, prodotto e divisione. Si supponga y ≥ 0.
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

    // impostiamo i a y in modo tale da avere un contatore decrescente
    i = y;
    while(i > 0) {
        // moltiplichiamo res (ovvero il risultato delle operazioni precedenti) per x per un totale di y volte
        res = res * x;

        i--;
    }

    // stampiamo il risultato e chiudiamo con return 0.
    printf("%d", res);
    return 0;
}