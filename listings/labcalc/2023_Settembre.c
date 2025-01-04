#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 5

int input() {
    int nchar = 0;
    
    do {
        printf("Inserire il numero totale di caratteri da utilizzare, compreso tra 2 e 26: ");
        scanf("%d", &nchar);
    } while (nchar < 2 || nchar > 26);
    return nchar;
}

void genstring(int nchar, char *parolad) {
    int i;
    for(i = 0; i < LEN; i++) {
        parolad[i] = 'a' + drand48() * nchar;
    }
    parolad[LEN] = '\0'; // fine stringa
}

void reversestring(char *parolad, char *parolar) {
    int i;
    for(i = 0; i < LEN; i++) {
        parolar[i] = parolad[LEN - 1 - i];
    }
    parolar[LEN] = '\0';
}

int ispalindrome(char *parolad, char *parolar) {
    int i;
    int is_p = 1;
    for(i = 0; i < LEN; i++) {
        if(parolad[i] != parolar[i]) { // non e' un palindromo
            is_p = 0;
        }
    }
    
    return is_p;
}

int main() {
    srand48(time(NULL));
    
    int nwords;
    int nchar = input();
    char parolad[LEN + 1], parolar[LEN + 1];
    
    char nomefile[100];
    sprintf(nomefile, "palindromi_%d.dat", nchar);
    FILE *out = fopen(nomefile, "w");
    
    for(nwords = 1000; nwords <= 64000; nwords *= 2) {
        int N_palindromes = 0;
        int i;
        for(i = 0; i < nwords; i++) {
            genstring(nchar, parolad);
            reversestring(parolad, parolar);
            int is_p = ispalindrome(parolad, parolar);
            if(is_p) {
                N_palindromes++;
            }
            
            if(i < 10) {
                printf("parola (%2d) = %s reverse (%2d) = %s palindromo = %d\n", i, parolad, i, parolar, is_p);
            }
        }
        
        double frequency = N_palindromes / (double) nwords;
        fprintf(out, "%d %.4lf\n", nwords, frequency);
        printf("Parole generate: %d, lunghezza: %d, dimensione dell'alfabeto: %d, numero di palindromi: %d, frequenza dei palindromi: %lf\n", nwords, LEN, nchar, N_palindromes, frequency);
    }
    fclose(out);
    
    return 0;
}
