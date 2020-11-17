#include <stdio.h>
#include <stdlib.h>

int nb_partition(int dn, int dt){
    int i, y, nb = 0, test = 0;
    int N = dn;
    int T = dt;

    if(dn < 0) {
        return 0;
    } else if(N == 0) {
        return 1;
    } else if(N > 0 && T == 1) {
        return 1;
    } else if(N > 0 && T > 1) {
        for(i=1; i <= T; i++) {
            nb =+ nb_partition(N-T, i);
        }
        for(y=1; y <= T-1; y++) {
            test =+ nb_partition(N, y);
        }
        return nb+test;
    }
}

int main() {
    int iN, iT;

    iN = 20;
    iT = 19;

    printf("Il y a %d façons de faire %d avec les nombres de 1 à %d \n",nb_partition(iN, iT), iN, iT);

    return 0;
}