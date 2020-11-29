#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define arbre_vide NULL
#define booleen   int
#define false 0  
#define true 1
#define MAX_DATA 256
unsigned int TabOcurrence[MAX_DATA];
unsigned int NbOctFichierSource = 0;
unsigned int MaxOccu = 0;
unsigned int MaxNbBits=0;

typedef struct noeud {
    unsigned char c;
    int occurence;
    int code;
    int bits;
    struct noeud *gauche, *droit;
}noeud;

typedef struct dictionnaire {
  unsigned int code;
  unsigned int bits;
}dictionnaire;

noeud *ArbreHuffman[MAX_DATA], *Racine = NULL;
dictionnaire Dico[MAX_DATA];

void initArbre(noeud *A[]) {
    int i, j = 0;
    noeud *arbre;

    for(i=0; i < MAX_DATA; i++) {
        A[i] = NULL;
    }
    for(i=0; i < MAX_DATA; i++) {
        if(TabOcurrence[i] != 0) {
            arbre = (noeud*) malloc(sizeof(noeud));
            arbre->gauche = NULL;
            arbre->droit = NULL;
            arbre->c = i;
            arbre->code = 0;
            arbre->bits = 0;
            arbre->occurence = TabOcurrence[i];
            A[j++] = arbre;
        }
    }
}

void Tri(noeud * A[]) {
    int i = 0, j, val;
    noeud *arbre;

    while((i < MAX_DATA) && (A[i] != NULL)) {
        arbre = A[i];
        val = arbre->occurence;
        j = i;

        while((j > 0) && (val < (A[j-1]->occurence))) {
            A[j] = A[j-1];
            j--;
        }

        A[j] = arbre;
        i++;
    }
}

void decTobinary(int n, int bits) {
    int binaryNum[32]; 
 
    int i = 0; 
    for(i=0; i < bits; i++) { 
        binaryNum[i] = n % 2; 
        n = n / 2; 
    }

    for (int j = i - 1; j >= 0; j--) 
        printf("%d", binaryNum[j]); 
}

void affiche(noeud *A[]) {
    int i = 0;

    while((i < MAX_DATA) && (A[i] != NULL)) {
        printf("%c (x%d) -> %d bits -> ", A[i]->c, A[i]->occurence, A[i]->bits);
        decTobinary(A[i]->code, A[i]->bits);
        printf("\n");
        i++;
    }
}

void parcours2(noeud *a) {
    if(a == NULL) {
        return;
    } else {
        printf("{");
        if(a->gauche != NULL) {
            parcours2(a->gauche);
        } else {
            printf("?");
        }
        printf(", %c (*%d), ", a->c, a->occurence);
        if(a->droit != NULL) {
            parcours2(a->droit);
        } else {
            printf("?");
        }
        printf("}");
    } 
}