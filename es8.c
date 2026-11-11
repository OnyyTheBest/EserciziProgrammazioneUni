/*

Un numero naturale si dice perfetto se è uguale alla somma
dei suoi divisori propri. 
Ad esempio i primi due numeri perfetti sono 6 (= 1+2+3) 
e 28 (= 1+2+4+7+14). 
Un numero si dice difettivo se è maggiore della somma
dei suoi divisori propri, 
ad esempio il numero 10 (> 1 + 2 + 5). 
Un numero si dice abbondante se è minore della somma
dei suoi divisori propri, 
ad esempio il numero 12 (< 1 + 2 + 3 + 4 + 6). 
Utilizzando le strutture di controllo fondamentali esprimete
due algoritmi per svolgere i seguenti compiti:

Leggere un numero e stabilire se è perfetto, 
difettivo o abbondante.
Leggere un numero n e produrre:
        un elenco di tutti i numeri perfetti ≤ n;
        un elenco di tutti i numeri difettivi ≤ n;
        un elenco di tutti i numeri abbondanti ≤ n.


*/
#include <stdio.h>

int reset_lista(int list[],int lenght) {
    int i = 0;
    
    while(i<lenght){
        list[i] = 0;
        i++;
    }
}

int get_divisori(int n, int list[]) {
    int i = 1;

    while(i<n) {
        if((n % i) == 0) {
            list[i] = i; 
        }
        i++;
    }

}

int get_numero_valore(int list[],int lenght, int numero) {
    int i = 0;
    int somma = 0;

    while(i<lenght) {
        if(list[i] != 0) {
            somma += list[i];
        }
        i++;
    }

    if(numero > somma) {
        return -1;
    } else if(numero < somma) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n = 0;   
    
    int res = 1;

    // questi cicli controllano che il numero inserito sia effettivamente un numero intero e non un carattere o un altro tipo di dato
    do {
        printf("Inserisci un numero: ");
        res = scanf("%d", &n);

        if (res != 1) {
            printf("Input non valido! Riprova.\n");

            // Con questo while svuotiamo il buffer di input in modo tale che il loop non continui all'infinito (\n viene considerato un carattere e non un numero intero!)
            while (getchar() != '\n');
        }

    } while (res != 1);

    int list[n];
    reset_lista(list, n);
    get_divisori(n, list);
    printf("%d", get_numero_valore(list,n, n));



    return 0;
}