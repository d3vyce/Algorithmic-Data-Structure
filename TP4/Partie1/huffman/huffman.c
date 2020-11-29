#include "huffman.h"

//https://github.com/sbksba/Huffman

//Remplis le tab TabOcurrence avec le fichier Name
int OccurenceData(char Name[]) {
    int i, result;
    unsigned char data;
    FILE *Fichier;

    for(i=0; i < MAX_DATA; i++) {
        TabOcurrence[i] = 0;
    }

    Fichier = fopen(Name, "r");
    if(Fichier == NULL) {
        printf("Erreur ouverture fichier\n");
        return -1;
    } else {
        while (!feof(Fichier)) {
            result = fscanf(Fichier, "%c", &data);
            if(result != EOF) {
                TabOcurrence[data]++;
                NbOctFichierSource++;
            }
        }
        fclose(Fichier);

        for(i=0; i < MAX_DATA; i++) {
            if(TabOcurrence[i] > MaxOccu) {
                MaxOccu = TabOcurrence[i];
            }
        }
    }
    return 1;
}

void CreateArbreBinaire() {
    int i, j;
    noeud *arb_gauche, *arb_droit, *new_arb;
    noeud *A[MAX_DATA];

    for(i=0; i < MAX_DATA; i++) {
        A[i] = ArbreHuffman[i];
    }

    while(A[1] != NULL) {
        arb_gauche = A[0];
        arb_droit = A[1];

        new_arb = (noeud*) malloc(sizeof(noeud));
        new_arb->occurence = arb_gauche->occurence+arb_droit->occurence;
        new_arb->gauche = arb_gauche;
        new_arb->droit = arb_droit;
        new_arb->c = 0;
        A[0] = new_arb;

        j = 1;
        while((j < MAX_DATA-1) && (A[j] != NULL)) {
            A[j] = A[j+1];
            j++;
        }
        A[j] = NULL;

        Tri(A);
    }
    Racine = A[0];
}

void CreateCode(noeud *A, int code, int niveau) {
    if((A->gauche == NULL) && (A->droit == NULL)) {
        A->bits = niveau;
        A->code = code;

        Dico[A->c].code = code;
        Dico[A->c].bits = niveau;

        if(niveau > MaxNbBits) {
            MaxNbBits = niveau;
        }
    } else {
        CreateCode(A->gauche, (code<<1), niveau+1);
        CreateCode(A->droit, (code<<1)+1, niveau+1);
    }
}

int main(int argc, char* argv[]) {
    int code = 0;
    char Nom[] = "data.txt";

    code = OccurenceData(Nom);
    if(code != -1) {
        initArbre(ArbreHuffman);
        Tri(ArbreHuffman);
        CreateArbreBinaire();
        printf("Arbre Binaire :\n");
        parcours2(Racine);

        printf("\n\nOccurence + Code :\n");
        CreateCode(Racine, 0 ,0);
        affiche(ArbreHuffman);
        
    }

    return 0;
}