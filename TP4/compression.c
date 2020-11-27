#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE 20

//https://codes-sources.commentcamarche.net/source/view/10982/756930#browser

typedef struct occurence {
    char caractere;
    int nb_occurence;
}occurence;

occurence recherche(char * data) {
    occurence caractere[TAILLE+1];
    
    //TODO
}

char* RLE(char* data) {
    int i, j, k = 0, occu;
    int taille = strlen(data);
    char* output = (char*)malloc(sizeof(char) * (taille * 2 + 1));
    char test[10];

    for(i=0; i < taille; i++) {
        j = i;
        occu = 1;
        while(i+1 < taille && data[i] == data[i+1]) {
            occu++;
            i++;
        }

        if(occu == 1) {
            output[k++] = data[i];
        } else if(occu < 10) {
            sprintf(test, "%d", occu);
            output[k++] = test[0];
            output[k++] = data[i];
        } else {
            sprintf(test, "%d", occu);
            output[k++] = test[0];
            output[k++] = test[1];
            output[k++] = data[i];
        }
    }
    return output;
}

int main() {
    char data[] = "AAAAAAAAAARRRRRRRROLLLLBBBBBUUTTTTTT";
    char* result = RLE(data);

    printf("%s \n", result);
    return 0;
}