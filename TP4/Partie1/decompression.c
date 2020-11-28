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

char* deCompression(char* input, char caractere_spetial) {
    int taille = strlen(input);
    char* output = (char*)malloc(sizeof(char) * (CARACTERES_MAX));
    char caractere;
    int i, j, k = 0, occu;

    for(i=0; i < taille; i++) {
        if(input[i] == caractere_spetial) {
            occu = input[i+1]-'0';
            caractere = input[i+2];
        
            for(j=0; j < occu; j++) {
                output[k++] = caractere;     
            }
        } else {
            if(input[i-1] != caractere_spetial && input[i-2] != caractere_spetial) {
                output[k++] = input[i];
            }
        }
    }

    return output;
}

void tauxCompression(char* data, char* data_compresse) {
    float f_data = (float)strlen(data);
    float f_result = (float)strlen(data_compresse)-1;

    float taux_compression = (f_data-f_result)/f_data*100;
    printf("Taux de compression : %f \n", taux_compression);
}

int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("Erreur argument (!=2) \n");
        return -1;
    }

    char* compress = openFile(argv[1]);
    char* decompress = deCompression(compress, argv[2][0]);

    printf("Compresse -> %s \n", compress);
    printf("deCompresse -> %s \n", decompress);
    tauxCompression(decompress, compress);

    writeFile("F1.dec", decompress);

    return 0;
}