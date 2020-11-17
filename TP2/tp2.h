#include <stdio.h>
#include <stdlib.h>

#define liste_vide NULL
#define typeElem int
#define booleen int

typedef struct ll {
    typeElem e;
    struct ll *suiv;
}typeListe;

typedef typeListe *liste;

int est_vide(liste L){
    return L==liste_vide; 
}

liste cons(typeElem E , liste L) {
    liste tmp=(liste)malloc(sizeof(typeListe));
    tmp -> e=E;
    tmp -> suiv=L;
    return tmp;
}

liste suite(liste L){ 
    return L->suiv; 
}

typeElem tete(liste L){ 
    return L->e; 
}


//Fonction

//Partie 1
int longueur(liste L);  //Done
void affiche(liste L);  //Done
booleen isLast(liste L);    //Done
typeElem Last(liste L); //Done
typeElem maxL(liste L); //Done
typeElem rec_maxL(liste L); //Done
booleen recherche(typeElem X, liste L); //Done

//Partie 2
int nb_Occu(typeElem X, liste L);   //Done
typeElem kieme(liste L, int k); //Done
int ieme(liste L, typeElem E);  //Done

//Partie 3
void iter_inverse(liste* pl);   //Done
liste rec_inverse(liste* pl);   
void ajoutAukieme(liste *L, int k, typeElem e); //Done
void supprime_debut(liste *L);  //Done
void ajout_fin(liste *L, typeElem X);   //Done
void supprimekieme(liste *L, int k);    //Done

//Partie 4
void catenate(liste *L1, liste *L2);    //Done
void couper(liste *L1, liste *L2, liste *L3);   //Done
void fusion(liste *L1, liste *L2, liste *L3);   //Done

void swap(liste a, liste b);