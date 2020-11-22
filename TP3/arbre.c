#include "arbre.h"

// 2. Opération de base
arbre consa(typeElem E, arbre g, arbre d) {
    arbre tmp = (arbre)malloc(sizeof(typeArbre));

    tmp->valeur = E;
    tmp->g = g;
    tmp->d = d;

    return tmp;
}

int max_comp(int a, int b) {
    if(a>=b) {
        return a;
    } else {
        return b;
    }
}

booleen est_vide(arbre a) {
    return a == arbre_vide;
}

arbre gauche(arbre a) {
    if(!est_vide(a)) {
        return a->g;
    }
}

typeElem racine(arbre a) {
    if(!est_vide(a)) {
        return a->valeur;
    }
}

arbre droit(arbre a) {
    if(!est_vide(a)) {
        return a->d;
    }
}

void prefixe(arbre a) {
    if(!est_vide(a)) {
        printf("%d ", racine(a));
        prefixe(gauche(a));
        prefixe(droit(a));
    }
}

void infixe(arbre a) {
    if(!est_vide(a)) {
        infixe(gauche(a));
        printf("%d ", racine(a));
        infixe(droit(a));
    }
}

void postfixe(arbre a) {
    if(!est_vide(a)) {
        postfixe(gauche(a));
        postfixe(droit(a));
        printf("%d ", racine(a));
    }
}


// 3. Opération annexes
int nbreTotalNoeuds(arbre a) {
    if(est_vide(a)) {
        return 0;
    } else {
        return 1 + nbreTotalNoeuds(gauche(a)) + nbreTotalNoeuds(droit(a));
    }
}

int nbreNoeuds2(arbre a){
    if(est_vide(a)) {
        return 0;
    } else if(!est_vide(gauche(a)) && !est_vide(droit(a))) {
        return 1 + nbreNoeuds2(gauche(a)) + nbreNoeuds2(droit(a));
    } else {
        return 0 + nbreNoeuds2(gauche(a)) + nbreNoeuds2(droit(a));
    }
}

int nbreNoeuds1(arbre a){
    if(est_vide(a)) {
        return 0;
    } else if(!est_vide(gauche(a)) && est_vide(droit(a))) {
        return 1 + nbreNoeuds1(gauche(a)) + nbreNoeuds1(droit(a));
    } else if(est_vide(gauche(a)) && !est_vide(droit(a))) {
        return 1 + nbreNoeuds1(gauche(a)) + nbreNoeuds1(droit(a));
    } else {
        return 0 + nbreNoeuds1(gauche(a)) + nbreNoeuds1(droit(a));
    }
}

int nombre_de_feuilles(arbre a){
    if(est_vide(a)) {
        return 0;
    } else if(est_vide(gauche(a)) && est_vide(droit(a))) {
        return 1 + nombre_de_feuilles(gauche(a)) + nombre_de_feuilles(droit(a));
    } else {
        return 0 + nombre_de_feuilles(gauche(a)) + nombre_de_feuilles(droit(a));
    }
}

int hauteur(arbre a){
    if(est_vide(a)) {
        return 0;
    } else {
        return 1 + max_comp(hauteur(gauche(a)), hauteur(droit(a)));
    }
}


// 4. Autres parcours
void parcours2(arbre a) {
    if(est_vide(a)) {
        return;
    } else {
        printf("{");
        if(!est_vide(gauche(a))) {
            parcours2(gauche(a));
        } else {
            printf("?");
        }
        printf(", %c, ", racine(a));
        if(!est_vide(droit(a))) {
            parcours2(droit(a));
        } else {
            printf("?");
        }
        printf("}");
    } 
}

void parcoursOrder(arbre a) {
    if(!est_vide(a)) {
        parcoursOrder(gauche(a));
        printf("%c ", racine(a));
        parcoursOrder(droit(a));
    }
}


// 5. Autres fonctions
booleen recherche_noeud(typeElem x, arbre a) {
    if(est_vide(a)) {
        return 0;
    }
    int Vreturn = 0;
    int greturn = recherche_noeud(x, gauche(a));
    int dreturn = recherche_noeud(x, droit(a));

    if(racine(a) == x) {
        Vreturn = 1;
    }

    return Vreturn+greturn+dreturn;
}

arbre recherche_noeudbis(typeElem x, arbre a) {
    if(est_vide(a)) {
        return arbre_vide;
    }
    if (x == racine(a)) {
        return a;
    }
    if (x < racine(a)) {
        return recherche_noeudbis(x, gauche(a));
    } else {
        return recherche_noeudbis(x, droit(a));
    }
}

int max(arbre a) {
    if(est_vide(a)) {
        return 0;
    }
    int Vmax = racine(a); 
    int gmax = max(gauche(a));
    int dmax = max(droit(a));

    if(gmax > Vmax) {
        Vmax = gmax;
    }
    if(dmax > Vmax) {
        Vmax = dmax;
    }

    return Vmax;
}

int min(arbre a) {
    if(est_vide(a)) {
        return 0;
    }
    int Vmin = racine(a);
    int gmin = min(gauche(a));
    int dmin = min(droit(a));

    if(gmin < Vmin && gmin != 0) {
        Vmin = gmin;
    }
    if(dmin < Vmin && dmin != 0) {
        Vmin = dmin;
    }

    return Vmin;
}

booleen egaux(arbre a1, arbre a2) {
    if(est_vide(a1) && est_vide(a2)) {
        return vrai;
    }

    if(!est_vide(a1) && !est_vide(a2)) {
        return
        (
            racine(a1) == racine(a2) &&
            egaux(gauche(a1), gauche(a2)) &&
            egaux(droit(a1), droit(a2))
        );
    }

    return faux;
}

void largeur(arbre a) {
    int h = hauteur(a);
    int i;
    for(i = 1; i <= h; i++) {
        affiche_etage(a, i);
    }
}

void affiche_etage(arbre a, int etage) {
    if(est_vide(a)) {
        return;
    }
    if(etage == 1) {
        printf("%d, ", racine(a));
    } else if(etage > 1) {
        affiche_etage(gauche(a), etage-1);
        affiche_etage(droit(a), etage-1);
    }
}


// Arbre binaire de recherche
arbre Add(typeElem x, arbre a) {
    if(est_vide(a)) {
        return consa(x, arbre_vide, arbre_vide);
    } else {
        if(x < racine(a)) {
            if(est_vide(gauche(a))) {
                a->g = consa(x, arbre_vide, arbre_vide);
            } else {
                Add(x, gauche(a));
            }
        } else {
            if(est_vide(droit(a))) {
                a->d = consa(x, arbre_vide, arbre_vide);
            } else {
                Add(x, droit(a));
            }
        }
    }
}

booleen recherche_Elem(typeElem x, arbre a) {
    if(est_vide(a)) {
        return faux;
    }
    if(x == racine(a)) {
        return vrai;
    } else if(x < racine(a)) {
        recherche_Elem(x, gauche(a));
    } else {
        recherche_Elem(x, droit(a));
    }
}

arbre recherche_Noeud(typeElem x, arbre a) {
    if(est_vide(a)) {
        return arbre_vide;
    }
    if (x == racine(a)) {
        return a;
    }
    if (x < racine(a)) {
        recherche_Noeud(x, gauche(a));
    } else {
        recherche_Noeud(x, droit(a));
    }
}

int max_bis(arbre a1) {
    if(est_vide(a1)) {
        return 0;
    }
    if(est_vide(droit(a1))) {
        return a1->valeur;
    } else {
        max_bis(droit(a1));
    }
}

int min_bis(arbre a1) {
    if(est_vide(a1)) {
        return 0;
    }
    if(est_vide(gauche(a1))) {
        return a1->valeur;
    } else {
        min_bis(gauche(a1));
    }
}

void minMax(int *min, int *max, arbre a) {
    *min = min_bis(a);
    *max = max_bis(a);
}

booleen est_arb(arbre a) {

}

int main(){
    
    int valeur_recherche;
    
    arbre a1 = consa(11 ,arbre_vide, arbre_vide);
    arbre a2 = consa(22 ,arbre_vide, arbre_vide);
    arbre a3 = consa(33,arbre_vide, arbre_vide);
    arbre a4 = consa(44 ,arbre_vide, arbre_vide);

    arbre a5 = consa(55, a1,a2);
    arbre a6 = consa(66, a3,a4);
    arbre a7 = consa(77, a5,a6);

    postfixe(a7);
    printf("\n");
    prefixe(a7);
    printf("\n");
    infixe(a7);
    printf("\n");
    printf("Nombre de noeud : %d \n", nbreTotalNoeuds(a7));
    printf("Nombre de noeud (fils == 2) : %d \n", nbreNoeuds2(a7));
    printf("Nombre de noeud (fils == 1) : %d \n", nbreNoeuds1(a7));
    printf("Nombre de feuille : %d \n", nombre_de_feuilles(a7));
    printf("Hauteur : %d \n", hauteur(a7));
    printf("Valeur max de l'arbre : %d \n", max(a7));
    printf("Valeur min de l'arbre : %d \n", min(a7));

    valeur_recherche = 11;
    arbre test = recherche_noeudbis(valeur_recherche, a7);
    printf("Est ce que la valeur %d est dans l'arbre ? %d \n", valeur_recherche, recherche_noeud(valeur_recherche, a7));
    printf("Est ce que la valeur %d est dans l'arbre ? %d \n", valeur_recherche, racine(test));
    printf("Est ce que les deux arbres sont identiques ? %d \n", egaux(a7, a7));
    largeur(a7);
    printf("\n");
    
    printf("\n");
    // Arbre question 14   
    arbre b1 = consa('V', arbre_vide, arbre_vide);
    arbre b2 = consa('E', arbre_vide, arbre_vide);
    arbre b3 = consa('R', arbre_vide, arbre_vide);

    arbre b4 = consa('W', b1, arbre_vide);
    arbre b5 = consa('T', arbre_vide, b3);
    arbre b6 = consa('B', b2, b4);
    arbre b7 = consa('G', b5, b6);

    parcours2(b7);
    printf("\n");
    parcoursOrder(b7);
    printf("\n");

    printf("\n");
    //Arbre question 15
    arbre c1 = consa('A', arbre_vide, arbre_vide);
    arbre c2 = consa('C', arbre_vide, arbre_vide);
    arbre c3 = consa('H', arbre_vide, arbre_vide);
    arbre c4 = consa('L', arbre_vide, arbre_vide);
    arbre c5 = consa('N', arbre_vide, arbre_vide);
    arbre c6 = consa('R', arbre_vide, arbre_vide);
    arbre c7 = consa('Y', arbre_vide, arbre_vide);

    arbre c8 = consa('B', c1, c2);
    arbre c9 = consa('K', c3, c4);
    arbre c10 = consa('P', c5, c6);
    arbre c11 = consa('W', c10, c7);
    arbre c13 = consa('M', c9, c11);
    arbre c14 = consa('G', c8, c13);

    parcoursOrder(c14);
    printf("\n");

    //Arbre binaire de recherche
    arbre d1 = arbre_vide;
    char E1[7] = {'B', 'J', 'C', 'G', 'D', 'T', 'P'};
    
    d1 = Add(E1[0], d1);
    arbre d2 = Add(E1[1], d1);
    arbre d3 = Add(E1[2], d1);
    arbre d4 = Add(E1[3], d1);
    arbre d5 = Add(E1[4], d1);
    arbre d6 = Add(E1[5], d1);
    arbre d7 = Add(E1[6], d1);
    
    parcours2(d1);
    printf("\n");

    printf("C est-il présent dans l'arbre ? %d \n", recherche_Elem('Z', d1));
    arbre testbis = recherche_Noeud('C', d1);
    printf("C est-il présent dans l'arbre ? @ : %d \n", racine(testbis));

    int *min, *max;
    minMax(&min, &max, d1);
    printf("Minimum : %d / Maximum : %d \n", min, max);

    return 0;
}