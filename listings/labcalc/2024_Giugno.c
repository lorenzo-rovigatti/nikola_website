#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void fillmatrix(char grid[SIZE][SIZE], int nstar);
void move(int position[2]);
void print_grid(char grid[SIZE][SIZE]);

int main() {
    srand48(time(NULL));
    char grid[SIZE][SIZE];
    int nstar_min, nstar;
    
    FILE *out = fopen("passi.dat", "w");
    
    do {
        fprintf(stderr, "Inserire il numero di asteroidi minimo (compreso tra 10 e 20): ");
        scanf("%d", &nstar_min);
    } while(nstar_min < 10 || nstar_min > 20);
    
    for(nstar = nstar_min; nstar <= 99; nstar++) {
        int position[2] = {0, 0};
        int steps = 0;
        int shields = 5;
        fillmatrix(grid, nstar);
        
        if(nstar == nstar_min) {
            print_grid(grid);
        }
        
        while(shields >= 0) {
            move(position);
            steps++;
            
            if(grid[position[0]][position[1]] == '*') {
                shields--;
                if(nstar == nstar_min) {
                    printf("Dopo %d passi l'astronave ha colpito un asteroide in (%d, %d) scudi=%d\n", steps, position[0], position[1], shields);
                }
            }
            grid[position[0]][position[1]] = 'A';
        }
        
        fprintf(out, "%d %d\n", nstar, steps);
        
        if(nstar == nstar_min) {
            printf("Dopo %d passi l'astronave e' esplosa\n", steps);
            print_grid(grid);
        }
    }
    
    fclose(out);
    
    return 0;
}

void fillmatrix(char grid[SIZE][SIZE], int nstar) {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            grid[i][j] = '-';
        }
    }
    
    int inserted = 0;
    while(inserted < nstar) {
        int x = drand48() * SIZE;
        int y = drand48() * SIZE;
        if((x != 0 || y != 0) && grid[x][y] == '-') {
            grid[x][y] = '*';
            inserted++;
        }
    }
}

void move(int position[2]) {
    int done = 0;
    
    while(!done) {
        // questa parte puo' essere fatta in diversi modi. Qui uso una soluzione che puo'
        // sembrare un po' criptica ma e' breve ed esplicita
        int coord_change = drand48() * 2;
        int shift = ((int) (drand48() * 2)) * 2 - 1;
        position[coord_change] += shift;
        if(position[coord_change] < 0 || position[coord_change] == SIZE) {
            position[coord_change] -= shift;
        }
        else {
            done = 1;
        }
    }
}

void print_grid(char grid[SIZE][SIZE]) {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        printf("|");
        for(j = 0; j < SIZE; j++) {
            printf(" %c", grid[i][j]);
        }
        printf(" |\n");
    }
}
