#include "hachage.h"

annuaire * creer() {
    int i;
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
    } else {
        annuaire temp = an[hash_key];
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = new;
        printf("Colision (%s, hash : %d)\n", nom, hash_key);
    }
}

int main() {
    annuaire *test = creer();

    inserer(test, "nicolas sudres", "0673978130");
    inserer(test, "pierre janaudy", "0643978130");
    inserer(test, "leo corazza", "0643978130");

    print(test);

    return 0;
}