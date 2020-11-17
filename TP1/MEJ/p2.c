int main()
{ /*   Cas statique   */ 
 int i = 2; 
 int * ptr; 
 ptr= &i; 
 *ptr= 3;  
 printf(â€œ entrez valeur de i :â€);  
 scanf(â€œ%dâ€, i); 
 printf(â€œ entrez valeur de ptr :â€);  
 scanf(â€œ%dâ€, ptr); 
 /*   Cas dynamique    */
 int *tab= (int *)malloc(sizeof(int));
 /* allocation d'un entier */ 
 *ptr= 3; 
 int * p = (int*)malloc(5*sizeof(int));
 :Âµpermet d'allouer une zone mÃ©moire pouvant contenir 5 entiers. Âµ:
 return 0;
 } 