#include <stdio.h>
#include <stdlib.h>

#define LINIT 10
#define NT 50000
#define LMAX 500

void init_snake(int pos[LMAX][2], int *length);
void add_segment(int pos[LMAX][2], int *length);
int check_overlap(int pos[LMAX][2], int length);

int main() {
    int i, length;
    int pos[LMAX][2];
    int histo[LMAX + 1] = {0};
    
    srand48(42);
    for(i = 0; i < NT; i++) {
        init_snake(pos, &length);
        
        while(length < LMAX && !check_overlap(pos, length)) {
            add_segment(pos, &length);
        }
        
        histo[length]++;
    }
    
    FILE *out = fopen("isto_lunghezza.dat", "w");
    for(i = 0; i <= LMAX; i++) {
        fprintf(out, "%d %.6lf\n", i, histo[i] / (double) NT);
    }
    fclose(out);
    
    return 0;
}

void init_snake(int pos[LMAX][2], int *length) {
    int i;
    for(i = 0; i < LINIT; i++) {
        pos[i][0] = 0;
        pos[i][1] = i;
    }
    *length = LINIT;
}

void add_segment(int pos[LMAX][2], int *length) {
    do {
        pos[*length][0] = pos[*length - 1][0];
        pos[*length][1] = pos[*length - 1][1];
        
        double R = drand48();
        if(R < 0.25) {
            pos[*length][0] += 1;
        }
        else if(R < 0.5) {
            pos[*length][0] -= 1;
        }
        else if(R < 0.75) {
            pos[*length][1] += 1;
        }
        else {
            pos[*length][1] -= 1;
        }
    } while(pos[*length][0] == pos[*length - 2][0] && pos[*length][1] == pos[*length - 2][1]);
    
    *length += 1;
}

int check_overlap(int pos[LMAX][2], int length) {
    int i;
    for(i = 0; i < length - 1; i++) {
        if(pos[i][0] == pos[length - 1][0] && pos[i][1] == pos[length - 1][1]) {
            return 1;
        }
    }
    
    return 0;
}
