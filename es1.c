/*
Esprimete con le strutture di controllo fondamentali un algoritmo per il calcolo della somma di tutti i numeri interi compresi tra x e y, 
estremi inclusi, dove x e y sono due interi forniti dall’utente. 
Se ad esempio l'utente fornisce 3 e 8 il risultato dovr`a essere 33. 
Nella prima versione supponete che l’utente fornisca i numeri in ordine non decrescente. 
Nella seconda versione l’algoritmo deve calcolare la somma indipendentemente dall’ordine: se l’utente fornisce prima 8 e poi 3 il risultato deve essere di nuovo 33.
*/

#include <stdio.h>

int main() {
    int x = 0;
    int y = 0;

    int somma_totale = 0;
    
    int res = 1;

    // questi cicli controllano che il numero inserito sia effettivamente un numero intero e non un carattere o un altro tipo di dato
    do {
        printf("Inserisci il primo numero dell'intervallo: ");
        res = scanf("%d", &x);

        if (res != 1) {
            printf("Input non valido! Riprova.\n");

            // Con questo while svuotiamo il buffer di input in modo tale che il loop non continui all'infinito (\n viene considerato un carattere e non un numero intero!)
            while (getchar() != '\n');
        }

    } while (res != 1);

    do {
        printf("Inserisci il secondo numero dell'intervallo: ");
        res = scanf("%d", &y);

        if (res != 1) {
            printf("Input non valido! Riprova.\n");

            
            while (getchar() != '\n');
        }

    } while (res != 1);

    // controlliamo che il primo numero dell'intervallo non sia piu' grande del secondo
    if((x > y)) {
        int temp = 0;
        temp = x;
        x = y;
        y = temp;
    }
    
    // sommiamo tutti i numeri partendo da quello piu' piccolo dell'intervallo
    int i = x;
    while(i<=y) {
        somma_totale = somma_totale + i;
        i++;
    }

    // stampiamo a schermo il risultato e chiudiamo con un return 0 per far capire al sistema che abbiamo chiuso senza errori.
    printf("%s%d", "La somma totale di tutti i numeri tra l'insieme chiuso e' > ", somma_totale);
    return 0;
}