#include "mesTypes.h"

int nb_jours_par_an(t_Date d1) {
    if (est_bissextile(d1.an) == 1) {
        return 366;
    } else {
        return 365;
    }
}

int nb_jours_par_mois(t_Date d1) {
    int tab[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(1 < d1.mois < 12) {
        if (est_bissextile(d1.an) == 1) {
            return tab[d1.mois-1]+1;
        } else {
            return tab[d1.mois-1];
        }
    } else {
        return -1;
    }
}