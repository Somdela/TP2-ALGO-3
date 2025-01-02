#include<stdio.h>
#include<string.h>
#include<ctype.h>
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
 
 /*Fonction d'ajout d'une photos*/
 int ajouterphotos(char *ch, char *ind, Date date ){
 	Photos  *elt, *e;
 	e=preparerPhotos(ch, ind,date);
 	if(nb_element==0){ // cas ou le liste est vide
 		debut=e;
 		e->precedent=NULL;
 		nb_element++;
 		return 1;
	 }
	 else{
	 	if(strcmp(e->index,"Famille")){ //cas ou on ajoute un element d'index famille
 		e->precedent=debut;
 		debut =e;
 		nb_element++;}
 		else{ elt=debut; //cas ou on ajoute un element d'index loisir
	 		while(elt!=NULL){elt=elt->precedent;}
		 elt->precedent=e;
		 e->precedent=NULL;
		 nb_element++;}
		 return 1;}
		return 0;
	}

/* Fonction pour compter les categorie de photos : FAmille et loisir*/
void compterphotoscategorie(int *compteur_famille, int *compteur_loisir){
	Photos *element;
	element=debut;
	*compteur_famille=0;
	*commpteur_famille=0;
	while(element!=NULL){
		if(strcmp(element->index,"famille")==0) *(compteur_famille)=(*compteur_famille)+1;
		else  if(strcmp(element->index,"loisir")==0)(*compteur_loisir)=(*compteur_loisir)+1;
		element=element->precedent;
	}
}

/* Fonction de trie par date*/
void trierphotos(){
	/* e represente l'element;
	   courant represente un compteur pour boucler sur toute la liste
	   max represnte l'element ayant la date la plus element;
	   echange permet de permutter; 
	   avant_max permet d'avoir l'element avant le max pour pour faire les liaisions
	   es represnte l'element qui suit e
	   avant_fin point sur l'element avant la fin pour pouvoir le lier avec le max */
	Photos *e,*courant, *Max, *echange,*avant_max *es, *avant_fin;
	int i, k;

	while(i<=compteur famille){
		e=debut;
		courant=debut;
		es=e->precedent;
		max=e;
		while(courant!=NULL){
			if(e->prise_vue.annee > es->prise_vue.annee) {
				avant_max=e;
				es=es->precedent;}
				
			else{
				if(e->prise_vue.annee < es->prise_vue.annee){
					max=es;
					e=es;
					es=es->precedent;
				}
				else{
					if(e->prise_vue.mois > es->prise_vue.mois) {
						avant_max=e;
						es=es->precedent;}
					else{
						if(e->prise_vue.mois < es->prise_vue.mois){
							max=es;
							e=es;
							es=es->precedent;
						}
						else{
							if(e->prise_vue.jour > es->prise_vue.jour){
								avant_max=e;
								es =es->precedent;} 
							else{
								if(e->prise_vue.jour < es->prise_vue.jour){
									max=es;
									e=es;
									es=es->precedent;
								}
								else printf("Les deux photos phtos ont ete prise le meme jour");
							}
						}
					}
				}
			}
			if(courant->precedent->precedent==NULL) avant_fin=courant; // Pour cette condition, 
																	  //il faut que la liste soit coposer d'au moins trois element
			courant=courant->precedent;
		}
		if(Max!=debut){
			//echange=Max;
			avant_max->precedent= avant_fin->precedent;
			courant->precedent= Max->precedent;
			avant_fin->precedent= Max;
			Max->precedent=NULL;
		}
		else if(MAx==debut){
			avant_fin->precedent->precedent=debut->precedent;
			avant_fin=MAx;
			debut=avant_fin;
		}	
	}	
}

changer_ordre_photos(){
	
}
