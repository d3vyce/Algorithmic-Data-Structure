#include "hachage.h"

annuaire * creer() {
    int i;
    annuaire * new_annuaire;
    new_annuaire = (annuaire*) malloc(sizeof(annuaire) * TAILLE);

    for(i=0; i < TAILLE; i++) {
        new_annuaire[i] = NULL;
    }

    return new_annuaire;
}

char * inserer(annuaire *an, char *nom, char *numero) {
    //TODO
}

char * rech(annuaire *an, char *nom) {
    //TODO
}

void supprime(annuaire *an, char *nom) {
    //TODO
}

void libre(annuaire *an) {
    //TODO
}

int main() {
    annuaire *test = creer();
    

    return 0;
}