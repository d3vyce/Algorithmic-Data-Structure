#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define arbre_vide   NULL    /* pour déclarer arbre vide */
#define typeElem   char    /* à déclarer avant la structure */
#define booleen   int    /* on définit le type booléen  */
#define faux 0  
#define vrai 1

typedef struct aa {
typeElem valeur;
struct aa *g;
struct aa *d;
}typeArbre;

typedef typeArbre *arbre;


//  Fonction arbre.c

// 2. Opération de base
arbre consa(typeElem E ,arbre g,arbre d);
booleen est_vide(arbre a);
arbre gauche(arbre a);
typeElem racine(arbre a);
arbre droite(arbre a);
void prefixe(arbre a);
void infixe(arbre a);
void postfixe(arbre a);

// 3. Opération annexes
int nbreTotalNoeuds(arbre a);       //Done
int nbreNoeuds2(arbre a);           //Done
int nbreNoeuds1(arbre a);           //Done
int nombre_de_feuilles(arbre a);    //Done
int hauteur(arbre a);               //Done
int max_comp(int a, int b);

// 4. Autres parcours
void parcours2(arbre a);            //Done
void parcoursOrder(arbre a);        //Done

// 5. Autres fonctions
booleen recherche_noeud(typeElem x, arbre a);       //Done
arbre recherche_noeudbis(typeElem x, arbre a);      //Done
int max(arbre a);                                   //Done
int min(arbre a);                                   //Done
booleen egaux(arbre a1, arbre a2);                  //Done
void largeur(arbre a);                              //Done
void affiche_etage(arbre a, int etage);

// Arbre binaire de recherche
arbre Add(typeElem x, arbre a);                     //Done
booleen recherche_Elem(typeElem x, arbre a);        //Done
arbre recherche_Noeud(typeElem x, arbre a);         //
int max_bis(arbre a1);                              //
int min_bis(arbre a1);                              //
void minMax(int min, int max, arbre a);             //
booleen est_arb(arbre a);                           //