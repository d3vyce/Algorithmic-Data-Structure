#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE 20
#define CARACTERES_MAX 128

char* openFile(char* file) {
    //TODO
}

char* writeFile(char* name, char* data) {
    //TODO
}

char* Compression(char* input, char caractere_spetial) {
    int i, j, k = 0, occu, seuil = 3;
    int taille = strlen(input);
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
    
    //char data[] = "AAAAAAAAAARRRRRRRROLLLLBBBBBUUTTTTTT";
    char data[] = openFile(argv[1]);
    char* compress = Compression(data, argv[2][0]);
    char* decompress = deCompression(compress, argv[2][0]);

    
    
    printf("Original -> %s \n", data);
    printf("Compresse (RLE) -> %s \n", compress);
    tauxCompression(data, compress);
    printf("deCompresse -> %s \n", decompress);

    return 0;
}