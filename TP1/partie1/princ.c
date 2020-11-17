#include "mesTypes.h"

int main(int argc, char **argv) {

    t_Date d1, d2;

    if (argc == 1) {
        printf("Erreur 1: no argument\n");
        return 1;
    } else if (argc > 4) {
        printf("Erreur 2: trop arguments\n");
        return 2;
    }
    

    d1.jour = atoi(argv[1]);
    d1.mois = atoi(argv[2]);
    d1.an = atoi(argv[3]);

    d2.jour = 1;
    d2.mois = 6;
    d2.an = 1999;

    printf("%d est %d \n", d1.an, est_bissextile(d1));
    printf("Il y a %d jour(s) entre %d/%d/%d et %d/%d/%d \n", cmpDates(d1, d2), d1.jour, d1.mois, d1.an, d2.jour, d2.mois, d2.an);
    printf("Le %d/%d/%d c'était un ",d2.jour, d2.mois, d2.an);
    nom_jour(d2);

    return 0;
}