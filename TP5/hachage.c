#include "hachage.h"

annuaire * creer() {
    int i;
    
    annuaire *tab = malloc(sizeof(annuaire) * TAILLE);

    for(i=0; i < TAILLE; i++) {
        tab[i] = NULL;
    }
    return tab;
}

char * inserer(annuaire *an, char *nom, char *numero) {
    int hash_key;
    annuaire new = malloc(sizeof(annuaire));
    new->nom = nom;
    new->numero = numero;

    hash_key = Hash(nom);

    if(an[hash_key] == NULL) {
        an[hash_key] = new;
        printf("Pas de colision (%s, hash : %d)\n", nom, hash_key);

        return NULL;
    } else {
        annuaire temp = an[hash_key];
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = new;
        printf("Colision (%s, hash : %d)\n", nom, hash_key);
    }
}

char * rech(annuaire *an, char *nom) {
    int hash_key = Hash(nom);

    if(an[hash_key] != NULL) {
        annuaire temp = an[hash_key];
        while(temp->next) {
            if(an[hash_key]->nom == nom) {
                return an[hash_key]->numero;
            }
            temp = temp->next;
        }
    }
    return NULL;
}

void supprime(annuaire *an, char *nom) {
    //TODO
}

void libere(annuaire *an) {
    //TODO
}

int main() {
    annuaire *annu = creer();
    char *test = "nicolas sudres";

    inserer(annu, "nicolas sudres", "0677777");
    inserer(annu, "pierre janaudy", "0666666");
    inserer(annu, "leo corazza", "06555555");

    print(annu);
    printf("recherche de %s : %s \n", test, rech(annu, test));

    return 0;
}