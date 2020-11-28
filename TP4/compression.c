#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CARACTERES_MAX 128

char* openFile(char* file) {
    FILE *fichier;
    char* output = (char*)malloc(sizeof(char) * (CARACTERES_MAX));

    fichier = fopen(file, "r");
    if(fichier == NULL) {
        printf("Erreur ouverture fichier. \n");
        exit(-1);
    }

    fscanf(fichier, "%[^\n]", output);

    fclose(fichier);
    return output;
}

void writeFile(char* name, char* data) {
    FILE *fichier;
    fichier = fopen(name, "w");
    if(fichier == NULL) {
        printf("Erreur creation/ouverture fichier. \n");
        exit(-1);
    }

    fputs(data, fichier);

    fclose(fichier);
}

char* Compression(char* input, char caractere_spetial) {
    int i, j, k = 0, occu, seuil = 3;
    int taille = strlen(input);
    printf(" \n");
    char* output = (char*)malloc(sizeof(char) * (taille * 2 + 1));
    char test[10];

    for(i=0; i < taille; i++) {
        occu = 1;
        while(i+1 < taille && input[i] == input[i+1]) {
            occu++;
            i++;
        }

        if(occu < seuil) {
            for(j=0; j < occu; j++) {
                output[k++] = input[i];
            }
        } else {
            output[k] = caractere_spetial;
            output[k+1] = (char)occu+'0';
            output[k+2] = input[i];
            k = k+3;
        }

    }
    return output;
}

int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("Erreur argument (!=2) \n");
        return -1;
    }

    char* data = openFile(argv[1]);
    char* compress = Compression(data, argv[2][0]);
    
    printf("Original -> %s \n", data);
    printf("Compresse (RLE) -> %s \n", compress);
    
    writeFile("F1.cmp", compress);

    return 0;
}