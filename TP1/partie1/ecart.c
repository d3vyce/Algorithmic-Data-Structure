#include "mesTypes.h"

int cmpDates(t_Date d1, t_Date d2) {
    int nUmJourD1, nUmJourD2;

    //On calcule le numéro du jour (d1)
    int m1 = (d1.mois + 9) % 12;
    int a1 = d1.an - (m1 >=10);
    nUmJourD1 = 1461*a1/4 - a1/100 + a1/400 + (m1*306 + 5)/10 + d1.jour;

    //On calcule le numéro du jour (d2)
    int m2 = (d2.mois + 9) % 12;
    int a2 = d2.an - (m1 >=10);
    nUmJourD2 = 1461*a2/4 - a2/100 + a2/400 + (m2*306 + 5)/10 + d2.jour;

    return nUmJourD2-nUmJourD1;
}

void nom_jour(t_Date d1) {
    int M[12] = {0,3,3,6,1,4,6,2,5,0,3,5};
    int nb_jour;

    nb_jour = (d1.jour+(d1.an-1900)+((d1.an-1900)/4)+M[d1.mois-1])%7;

    switch (nb_jour)
    {
    case 1:
        printf("Lundi\n");
        break;
    case 2:
        printf("Mardi\n");
        break;
    case 3:
        printf("Mercredi\n");
        break;
    case 4:
        printf("Jeudi\n");
        break;
    case 5:
        printf("Vendredi\n");
        break;
    case 6:
        printf("Samedi\n");
        break;
    case 7:
        printf("Dimanche\n");
        break;
    case 0:
        printf("Dimanche\n");
        break;
    default:
        printf("[Erreur]\n");
        break;
    }
}