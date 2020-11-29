#include <stdio.h>
#include <stdlib.h>

#define TAILLE 5

typedef struct annuaire {
    char *nom;
    char *numero;
    struct Annuaire *next;
} *annuaire;

annuaire * creer();
char * inserer(annuaire *an, char *nom, char *numero);
char * rech(annuaire *an, char *nom);
void supprime(annuaire *an, char *nom);
void libre(annuaire *an);

int Hash(unsigned char *str) {
    int i = 1;
    unsigned long hash = 5381;
    char c = str[0];

    while(c != '\0') {
        printf("%c", c);
        hash = hash * 33 + c;
        c = str[i++];
    }
    printf("\n");
    return hash;
}