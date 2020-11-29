#include <stdio.h>
#include <stdlib.h>

#define TAILLE 5

typedef struct annuaire {
    char *nom;
    char *numero;
    struct annuaire *next;
} *annuaire;

struct annuaire *tab[TAILLE];


int Hash(unsigned char *str) {
    int i = 1;
    unsigned long hash = 5381;
    char c = str[0];

    while(c != '\0') {
        hash = hash * 33 + c;
        c = str[i++];
    }
    return hash%TAILLE;
}

void print(annuaire *an) {
    int i;

    for(i=0; i < TAILLE; i++) {
        annuaire temp = an[i];
        printf("chaine[%d] ->", i);
        while(temp) {
            printf("%s ->", temp->nom);
            temp = temp->next;
        }
        printf("NULL \n");
    }
}