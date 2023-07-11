#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll(int dices[3][6], int coppia, int *res_dado_1, int *res_dado_2);
void print_esito(int n_lancio, int res, int coppia, int res_dado_1, int res_dado_2);

int main() {
    srand48(time(NULL));
    
    int dices[3][6] = {
        {3, 3, 3, 3, 3, 6},
        {2, 2, 2, 5, 5, 5},
        {1, 4, 4, 4, 4, 4}
    };
    
    int N_rolls, i, coppia, res_1, res_2, histo_index;    
    double histo[3];
    
    FILE *out = fopen("histo.dat", "w");
    for(N_rolls = 10, histo_index = 0; N_rolls <= 100000; N_rolls *= 10, histo_index++) {
        for(i = 0; i < N_rolls; i++) {
            for(coppia = 0; coppia < 3; coppia++) {
                int res = roll(dices, coppia, &res_1, &res_2);
                if(coppia == 0 && res == 0) {
                    histo[0]++;
                }
                else if(coppia == 1 && res == 1) {
                    histo[1]++;
                }
                else if(coppia == 2 && res == 2) {
                    histo[2]++;
                }
                
                if(i < 5) {
                    print_esito(i + 1, res, coppia, res_1, res_2);
                }
            }
        }
        
        // normalizzazione e stampa dell'istogramma
        fprintf(out, "%d", N_rolls);
        for(coppia = 0; coppia < 3; coppia++) {
            histo[coppia] /= N_rolls;
            fprintf(out, " %lf", histo[coppia]);
        }
        fprintf(out, "\n");
    }
    fclose(out);
    
    return 0;
}

int roll(int dices[3][6], int coppia, int *res_dado_1, int *res_dado_2) {
    int dado_1, dado_2;
    if(coppia == 0) {
        dado_1 = 0;
        dado_2 = 1;
    }
    else if(coppia == 1) {
        dado_1 = 1;
        dado_2 = 2;
    }
    else {
        dado_1 = 2;
        dado_2 = 0;
    }
    
    *res_dado_1 = dices[dado_1][lrand48() % 6];
    *res_dado_2 = dices[dado_2][lrand48() % 6];
    
    if(*res_dado_1 > *res_dado_2) {
        return dado_1;
    }
    else {
        return dado_2;
    }
}

void print_esito(int n_lancio, int res, int coppia, int res_dado_1, int res_dado_2) {
    char nome_dado_1, nome_dado_2, nome_vincitore;
    if(coppia == 0) {
        nome_dado_1 = 'A';
        nome_dado_2 = 'B';
    }
    else if(coppia == 1) {
        nome_dado_1 = 'B';
        nome_dado_2 = 'C';
    }
    else {
        nome_dado_1 = 'C';
        nome_dado_2 = 'A';
    }
    
    if(res == 0) {
        nome_vincitore = 'A';
    }
    else if(res == 1) {
        nome_vincitore = 'B';
    }
    else {
        nome_vincitore = 'C';
    }
    
    fprintf(stdout, "Lancio n. %d, dado %c = %d, dado %c = %d, vince il dado %c\n", n_lancio, nome_dado_1, res_dado_1, nome_dado_2, res_dado_2, nome_vincitore);
}
