#include <stdio.h>
#include <stdlib.h>

int nb_rec(int dS, int dT[], int dN) {

    if(dS == 0) {
        return 1;
    }

    int i = dN;
    while(dT[i] > dS) {
        i--;
        if(i < 0) {
            return 0;
        }
    }

    return nb_rec(dS-dT[i],dT,dN)+nb_rec(dS,dT,i-1);
}

int main() {
    int iT[7] = {5,10,20,50,100,200,500};
    int iS = 100;

    printf("Il y a %d possibilitée(s)\n",nb_rec(iS, iT, 7));

    return 0;
}