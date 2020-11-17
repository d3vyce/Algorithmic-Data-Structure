#include "tp2.h"

/*
https://perso.esiee.fr/~djebalia/e4/
https://perso.esiee.fr/~djebalia/e4/TP2-INR411-listes.pdf
*/

//Partie 1/////////////////////////////////////
int longueur(liste L) {
    int i = 0;
    while(L) {
        i++;
        L = suite(L);
    }
    return i;
}

void affiche(liste L) {
    int i, taille = longueur(L);

    for(i=0;i<taille;i++) {
        printf("L[%d] = %d / %d\n", i+1, tete(L), isLast(L));
        L = suite(L);
    }
}

booleen isLast(liste L) {
    if(L->suiv == NULL) {
        return 1;
    } else {
        return 0;
    }
}

typeElem Last(liste L) {
    int i, taille = longueur(L);

    for(i=0;i<taille;i++) {
        if(isLast(L) == 1) {
            return tete(L);
        } else {
            L = suite(L);
        }
    }
}

typeElem maxL(liste L) {
    int i, max = 0, taille = longueur(L);

    if(est_vide(L)) {
        return -1;
    }

    for(i=0;i<taille;i++) {
        if(tete(L) > max) {
            max = tete(L);
        }
        L = suite(L);
    }
    
    return max;
}

typeElem rec_maxL(liste L) {
    if (est_vide(L)){
        return 0;
    }
    if(L->e<rec_maxL(L->suiv)){
        return rec_maxL(L->suiv);
    }
    else {
        return(L->e);
    }
}

booleen recherche(typeElem X, liste L) {
    int i, taille = longueur(L);

    if(est_vide(L)) {
        return -1;
    }
    
    for(i=0;i<taille;i++) {
        if(tete(L) == X) {
            return 1;
        }
        L = suite(L);
    }
    
    return 0;
}

//Partie 2/////////////////////////////////////
int nb_Occu(typeElem X, liste L) {
    int i, compteur = 0, taille = longueur(L);

    if(est_vide(L)) {
        return -1;
    }

    for(i=0;i<taille;i++) {
        if(tete(L) == X) {
            compteur++;
        }
        L = suite(L);
    }
    
    return compteur;
}

typeElem kieme(liste L, int k) {
    int i, taille = longueur(L);

    if(est_vide(L) || k > taille) {
        return -1;
    }

    for(i=1;i<k;i++) {
        L = suite(L);
    }

    return tete(L);
}

int ieme(liste L, typeElem E) {
    int i, taille = longueur(L);

    if(est_vide(L)) {
        return -1;
    }

    for(i=1;i<taille;i++) {
        if(i > taille) {
            return -1;
        } else if(tete(L) == E) {
            return i;
        }
        L = suite(L);
    }

}

//Partie 3/////////////////////////////////////
void iter_inverse(liste *pl) {
    liste previous, current, next;

    previous = NULL;
    current = *pl;

    while(current != NULL)
    {
        next = current->suiv;
        current->suiv = previous;
        previous = current;
        current = next;
    }

    *pl = previous;
}

liste rec_inverse(liste* pl) {
    liste tmp_pl, tmp;
    tmp_pl = *pl;

    if(tmp_pl && suite(tmp_pl)) {
        tmp_pl = suite(tmp_pl);
        rec_inverse(suite(tmp_pl));
    }
}

void ajoutAukieme(liste *L, int k, typeElem e) {
    int i, taille = longueur(*L);
    liste tmp, tmpbis, newliste=(liste)malloc(sizeof(typeListe));
    
    tmp = *L;
    newliste->e = e;

    if(k == 1 || est_vide(*L)) {
        *L = cons(e, *L);
    } else if(k <= taille) {
        for(i=1; i<k-1; i++) tmp = suite(tmp);
        tmpbis = tmp->suiv;
        tmp->suiv = newliste;
        tmp = suite(tmp);
        tmp->suiv = tmpbis;
    } else {
        ajout_fin(L, e);
    }  
}

void supprime_debut(liste *L) {
    liste tmp;

    tmp = *L;
    *L = suite(*L);
    free(tmp);
}

void ajout_fin(liste *L, typeElem X) {
    liste tmp, newliste=(liste)malloc(sizeof(typeListe));
    
    tmp = *L;
    newliste->e = X;
    newliste->suiv = NULL;

    if(est_vide(tmp)) {
        *L = newliste;
    } else {
        while(tmp->suiv!=NULL) tmp = tmp->suiv;
        
        tmp->suiv = newliste;
    }
}

void supprimekieme(liste *L, int k) {
    int i, taille = longueur(*L);
    liste tmp, tmpbis;
    
    tmp = *L;

    if(k == 1) {
        supprime_debut(L);
    } else if(k < taille) {
        for(i=1; i<k-1; i++) tmp = suite(tmp);
        tmpbis = suite(tmp);
        tmpbis = suite(tmpbis);
        tmp->suiv = tmpbis;
    } else {
        for(i=1; i<k-1; i++) tmp = suite(tmp);
        tmp->suiv = NULL;
    }
}

//Partie 4/////////////////////////////////////
void catenate(liste *L1, liste *L2) {
    int i, taille = longueur(*L1);
    liste tmp_l1, tmp_l2;

    tmp_l1 = *L1;
    tmp_l2 = *L2;

    if(est_vide(tmp_l1) != 0 && est_vide(tmp_l2) != 0) {
        for(i=1; i<taille; i++) tmp_l1 = suite(tmp_l1);
        tmp_l1->suiv = tmp_l2;
    } else if(est_vide(tmp_l1)) {
        taille = longueur(*L2);
        for(i=0; i<taille; i++) {
            ajout_fin(L1, tete(tmp_l2));
            tmp_l2 = suite(tmp_l2);
        }
    }
}

void couper(liste *L1, liste *L2, liste *L3) {
    int i, taille = longueur(*L3);
    liste tmp_l3;

    tmp_l3 = *L3;

    for(i=0; i<taille; i++) {
        if(tete(tmp_l3) > 0) {
            ajout_fin(L1, tete(tmp_l3));
        } else if (tete(tmp_l3) < 0) {
            ajout_fin(L2, tete(tmp_l3));
        }
        tmp_l3 = tmp_l3->suiv;
    }
}

void fusion(liste *L1, liste *L2, liste *L3) {
    int i, sort, taille_l1 = longueur(*L1), taille_l2 = longueur(*L2);
    liste tmp_l1, tmp_l2, tmp_l3, tmp = NULL;

    tmp_l1 = *L1;
    tmp_l2 = *L2;

    //Copie de L1 & L2 dans L3
    for(i=0; i<taille_l1; i++) {
        ajout_fin(L3, tete(tmp_l1));
        tmp_l1 = suite(tmp_l1);
    }
    for(i=0; i<taille_l2; i++) {
        ajout_fin(L3, tete(tmp_l2));
        tmp_l2 = suite(tmp_l2);
    }

    //Trie de L3 par ordre croissant
    do {
        sort = 0;
        tmp_l3 = *L3;
        while(suite(tmp_l3) != NULL) {
            if(tete(tmp_l3) > tete(suite(tmp_l3))) {
                swap(tmp_l3, tmp_l3->suiv);
                sort = 1;
            }
            tmp_l3 = suite(tmp_l3);
        }
        tmp = tmp_l3;
    }
    while(sort);
}

void swap(liste a, liste b) {
    typeElem temp = a->e; 
    a->e = b->e; 
    b->e = temp;
}

int main(int argc, char **argv) {
    liste Liste1 = NULL;
    liste Liste2 = NULL;
    liste Liste3 = NULL;
    
    /*
    ajout_fin(&Liste1, 51);
    ajout_fin(&Liste1, 22);
    ajout_fin(&Liste1, 33);
    */

    ajout_fin(&Liste2, 111);
    ajout_fin(&Liste2, 222);
    ajout_fin(&Liste2, 333);
    
    /*
    ajout_fin(&Liste3, 1);
    ajout_fin(&Liste3, -3);
    ajout_fin(&Liste3, -15);
    ajout_fin(&Liste3, 0);
    ajout_fin(&Liste3, 21);
    */
    
    //ajoutAukieme(&Liste, 10, 55);
    /*
    printf("Longeur de liste 1 : %d\n",longueur(Liste1));
    affiche(Liste1);
    printf("\nLongeur de liste 2 : %d\n",longueur(Liste2));
    affiche(Liste2);
    printf("Dernier élement : %d\n",Last(Liste1));
    printf("Max élement : %d\n",rec_maxL(Liste1));
    printf("Recherche de 11 dans la liste : %d\n",recherche(11, Liste1));
    printf("Recherche du nb de 11 dans la liste : %d\n",nb_Occu(11, Liste1));
    printf("Le nombre en 3ème position dans la liste est : %d\n",kieme(Liste1, 3));
    printf("La positon de 22 dans la liste est : %d\n",ieme(Liste1, 22));
    */
    //iter_inverse(&Liste1);
    //supprimekieme(&Liste, 1);
    //supprime_debut(&Liste1);
    //catenate(&Liste1, &Liste2);
    //fusion(&Liste1, &Liste2, &Liste3);

    
    //couper(&Liste1, &Liste2, &Liste3);
    printf("Longeur de liste 1 : %d\n",longueur(Liste1));
    affiche(Liste1);
    printf("Longeur de liste 2 : %d\n",longueur(Liste2));
    affiche(Liste2);
    printf("Longeur de liste 3 : %d\n",longueur(Liste3));
    affiche(Liste3);
    return 0;
}