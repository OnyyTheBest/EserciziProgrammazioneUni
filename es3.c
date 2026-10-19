/*
Esprimete con le strutture di controllo fondamentali un algoritmo per il calcolo del quoziente e del resto della divisione
tra due numeri interi, utilizzando esclusivamente 
operazioni di somma e sottrazione. Ad esempio, 
se in ingresso vengono forniti i valori 13 e 4, 
in uscita dovranno essere restituiti i valori 3 e 1. 
Si supponga che i numeri inseriti siano positivi.
*/

#include <stdio.h>

int main(){
    int x = 0;
    int y = 0;
    int res = 0;

    int i = 0;

    // questi cicli controllano che il numero inserito sia effettivamente un numero intero e non un carattere o un altro tipo di dato
    do {
        printf("Inserisci il dividendo: ");
        res = scanf("%d", &x);

        if (res != 1) {
            printf("Input non valido! Riprova.\n");

            // Con questo while svuotiamo il buffer di input in modo tale che il loop non continui all'infinito (\n viene considerato un carattere e non un numero intero!)
            while (getchar() != '\n');
        }

    } while (res != 1 || x < 0);

    do {
        printf("Inserisci il divisore: ");
        res = scanf("%d", &y);

        if (res != 1) {
            printf("Input non valido! Riprova.\n");

            
            while (getchar() != '\n');
        }

    } while (res != 1 || y <= 0);



    
    // portiamo res a zero in modo tale da poterlo riutilizzare.
    res = 0;

    // cicliamo per x maggiore di 0.
    while(x > 0){
        
        // controlliamo che la sottrazione tra dividendo e divisore sia maggiore o uguale a 0 per evitare loop infiniti o resti negativi
        if ((x - y) >= 0) {
            printf("%d-%d = %d\n", x, y, x-y);
            x = x - y; 
            res++;
        // se la condizione risulta falsa usciamo dal ciclo con un break.
        } else {
            break;
        }
    }

    // stampiamo a video risultato e resto e returniamo 0 per terminale il programma.
    printf("%s%d %s%d\n", "Risultato: ", res, "resto: ", x);
    return 0;
}