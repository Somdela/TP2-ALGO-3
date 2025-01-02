#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define max 50

typedef struct {
	int jour;
	int mois;
	int annee;
}Date;

typedef struct photos{
	char* chemin_acces;
	Date prise_vue;
	char* index;
	struct photos *precedent;
} Photos;

/* Variables globales*/
 Photos *debut; 
 int nb_element;
 
 /*INitialisation*/
 void initialiser(){
 	debut=NULL;
 	nb_element=0;
 }
 
 /*Fonction d'allocation de la memoire*/
 Photos* preparerPhotos(char *ch, char *ind, Date date){
 	Photos *p;
 	p=(Photos*)malloc(sizeof(Photos));
 	p->chemin_acces=(char*)malloc(sizeof(char));
 	p->index=(char*)malloc(sizeof(char));
 	if(p==NULL || p->chemin_acces==NULL || p->index==NULL) return (NULL);
 	else{
 		p->chemin_acces=ch;
 		p->index=ind;
 		p->prise_vue=date;
 		return(p);	
	 } 
 }
