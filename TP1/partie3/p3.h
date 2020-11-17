# include <stdio.h>
# include <string.h>

typedef struct s_Date{
    int jour;
    int mois;
    int annee;
}t_Date;

typedef struct s_Identite{
    char nom[10];
    char prenom[10];
}t_Identite;

typedef struct s_Adresse{
    int codePostal;
    char ville[10];
}t_Adresse;