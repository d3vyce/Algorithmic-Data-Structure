#include "mesTypes.h"

int est_bissextile(t_Date d1) {
    if ( (d1.an%4 == 0 && d1.an%100 != 0) || (d1.an%400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}