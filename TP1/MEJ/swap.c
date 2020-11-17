#include <stdio.h>

void  swap ( int *pA,   int *pB) 
{
    int tmp =  pB;
    printf("Avant swap - x : %d et y : %d \n", pA, pB);
    pB =   pA;
    pA =   tmp;
    printf("Après swap - x : %d et y : %d \n", pA, pB);
}

int main() {
    int *x = 20, *y = 44;
    
    swap(x,y);

    return 0;
}