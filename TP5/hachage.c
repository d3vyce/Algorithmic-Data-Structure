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
        return NULL;
    } else {
        annuaire temp = an[hash_key];
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = new;
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
    int hash_key = Hash(nom);

    if(an[hash_key] != NULL) {
        annuaire temp = an[hash_key], n, nPlus1;

        if(temp->nom == nom) {
            n = temp;
            an[hash_key] = temp->next;
            free(n);
        } else {
            n = temp;
            nPlus1 = temp->next;

            while(n != NULL) {
                if(nPlus1->nom == nom) {
                    n->next = nPlus1->next;
                    free(nPlus1);
                    return;
                }
                n = nPlus1;
                nPlus1 = nPlus1->next;
            }
        }
    }
    return;
}

void libere(annuaire *an) {
    int i;
    annuaire temp, n;
    
    for(i=0; i < TAILLE; i++) {
        temp = an[i];
        while(an[i]) {
            n = temp;
            an[i] = temp->next;
            free(n);
        }
    }

    free(an);
}

int main() {
    annuaire *annu = creer();
    char *test = "nicolas sudres";

    inserer(annu, "nicolas sudres", "0677777");
    inserer(annu, "pierre janaudy", "0666666");
    inserer(annu, "leo corazza", "06555555");

    printf("Annuaire :\n");
    print(annu);

    printf("\nRecherche de %s : %s \n", test, rech(annu, test));

    printf("\nAnnuaire après suppression de %s:\n", test);
    supprime(annu, test);
    print(annu);

    libere(annu);
    return 0;
}