# include "p3.h"

int cmpDates(t_Date d1, t_Date d2){

	if (d1.jour!=d2.jour || d1.mois!=d2.mois || d1.annee!=d2.annee){
		return -1;
	}

return 0;
}

int cmpIdentites(t_Identite id1, t_Identite id2){

int compNom;
int compPrenom;

compNom=strcmp(id1.nom, id2.nom);
compPrenom=strcmp(id1.prenom, id1.prenom);

	if (compNom==0 && compPrenom==0){
	return 0;
	}

return -1;
}

int cmpAdresses(t_Adresse ad1, t_Adresse ad2){

int compAdresse;

compAdresse=strcmp(ad1.ville, ad2.ville);
	if (ad1.codePostal==ad2.codePostal && compAdresse==0){
		return 0;
	}
return -1;	
}

int main(){
//Date
t_Date d1;
t_Date d2;
d1.jour=1;
d1.mois=6;
d1.annee=2010;
d2.jour=1;
d2.mois=6;
d2.annee=2010;
	if (cmpDates(d1,d2)==-1){
		printf("Les deux dates ne sont pas identiques\n");
		//printf("cmpDate a retourné : %d\n", cmpDates(d1,d2));
	}
	else{
		printf("Les deux dates sont identiques\n");
	}
//Identité
t_Identite id1;
t_Identite id2;

strcpy(id1.nom, "Janaudy");
strcpy(id1.prenom, "Pierre");
strcpy(id2.nom, "Janaudy");
strcpy(id2.prenom, "Pierre");
	if (cmpIdentites(id1,id2)==0){
		printf("Les deux identités sont identiques\n");
		//printf("cmpDate a retourné : %d\n", cmpDates(d1,d2));
	}
	else{
		printf("Les deux identités ne sont pas identiques\n");
	}
//Adresse
t_Adresse ad1;
t_Adresse ad2;
ad1.codePostal=75020;
strcpy(ad1.ville, "Paris");
ad2.codePostal=75020;
strcpy(ad2.ville, "Paris");
	if(cmpAdresses(ad1,ad2)==0){
		printf("Les deux adresses sont identiques\n");
	}
	else{
		printf("Les deux adresses ne sont pas identiques\n");
	}
}

