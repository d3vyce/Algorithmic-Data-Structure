#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE 20

typedef struct occurence {
    char caractere;
    int nb_occurence;
}occurence;

char* Compression(char* input) {
    int i, j, k = 0, occu;
    int taille = strlen(input);
    char* output = (char*)malloc(sizeof(char) * (taille * 2 + 1));
    char test[10];

    for(i=0; i < taille; i++) {
        j = i;
        occu = 1;
        while(i+1 < taille && input[i] == input[i+1]) {
            occu++;
            i++;
        }

        if(occu == 1) {
            output[k++] = input[i];
        } else if(occu < 10) {
            sprintf(test, "%d", occu);
            output[k++] = test[0];
            output[k++] = input[i];
        } else {
            sprintf(test, "%d", occu);
            output[k++] = test[0];
            output[k++] = test[1];
            output[k++] = input[i];
        }
    }
    return output;
}

char* deCompression(char* input) {
    //TODO
}

void tauxCompression(char* data, char* data_compresse) {
    float f_data = (float)strlen(data);
    float f_result = (float)strlen(data_compresse)-1;

    float taux_compression = (f_data-f_result)/f_data*100;
    printf("Taux de compression : %f \n", taux_compression);
}

int main(int argc, char* argv[]) {
    char data[] = "AAAAAAAAAARRRRRRRROLLLLBBBBBUUTTTTTT";
    char* result = Compression(data);

    printf("Original -> %s \n", data);
    printf("Compresse (RLE) -> %s \n", result);
    tauxCompression(data, result);

    return 0;
}