#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct date{
    int jour;
    int mois;
    int annee;
} Date;

typedef struct elt{
    char * chem;
    Date date;
    char *index;
    struct elt * suiv;
    struct elt * prec;
} lsc;

/* variables globales*/
lsc * debut;
int nbelt;

/* Preparation de la photos*/
lsc *preparerphotos(Date date, char *ch, char *ind){
    lsc *e;
    if((e=(lsc*)malloc(sizeof(lsc)))==NULL) return NULL;
    else{
        /* reserver la memeoire pour le chemin d'acces et pour l'index*/
        if((e->chem=(char*)malloc(50*sizeof(char)))==NULL) return NULL;
        if((e->index=(char*)malloc(50*sizeof(char)))==NULL) return NULL;
        /* copier les valeurs*/
        strcpy(e->chem,ch);
        strcpy(e->index,ind);
        e->date=date;
        e->suiv=NULL;
        e->prec=NULL;
        return e;
    }
}

/* Ajouter une photos d'index famille au debut et d'index a la fin*/
int ajouterphotos(Date date, char *ch, char *ind){
    lsc *e, *p;
    if((e=preparerphotos(date,ch,ind))==NULL) return 0;
    else{
        if(debut==NULL){
            debut=e;
            e->suiv=NULL;
            e->prec=NULL;
        }
        else{
            if((strcmp(e->index,"famille"))==0){
                e->suiv=debut;
                debut->prec=e;
                debut=e;
            }
            else{
                p=debut;
                while(p->suiv!=NULL){
                    p=p->suiv;
                }
                p->suiv=e;
                e->prec=p;
                e->suiv=NULL;
            }
        }
        nbelt++;
        return 1;
    }
}

/* Pour compter le nombre de photos par categorie*/
void comptercategorie(int *comp_fam, int *comp_loisir){
    lsc *p;
    p=debut;
    *comp_fam=0;
    *comp_loisir=0;
    while(p!=NULL){
        if(strcmp(p->index, "famille")==0){
            (*comp_fam)+=1;
        }
        else{
            (*comp_loisir)+=1;
        }
        p=p->suiv;
    }
}

/* Trier les photos de chaque categorie par date ( Du plus recent -> moins recent)*/
void triephotos(char x){
    lsc *courant;
    Date temp;
    courant =debut;
    while(courant!=NULL){
        if((strcmp(courant->index, "x"))==0){
            while(courant->suiv!=NULL){
                if(courant->date.annee < courant->suiv->date.annee){
                    temp=courant->date;
                    courant->date=courant->suiv->date;
                    courant->suiv->date=temp;
                }
                else if(courant->date.annee == courant->suiv->date.annee){
                    if(courant->date.mois < courant->suiv->date.mois){
                        temp=courant->date;
                        courant->date=courant->suiv->date;
                        courant->suiv->date=temp;
                    }
                    else if(courant->date.mois == courant->suiv->date.mois){
                        if(courant->date.jour < courant->suiv->date.jour){
                            temp=courant->date;
                            courant->date=courant->suiv->date;
                            courant->suiv->date=temp;
                        }
                    }
                }
                courant=courant->suiv;
            }
        }
        courant=courant->suiv;
    }
}

void trie(){
	const char famille, loisir;
    triephotos(famille);
    triephotos(loisir);
}

/* fonction pour changer l'ordre des photos c'est-à-dire 
mettre les photos de type loisir en premier et celle de type famille a la fin*/

/* Premiere methode -> changement du sens du chainage de la lsc*/
void changement(){
    lsc *courant, *suivant, *precedent;
    courant=debut;
    precedent =courant->prec;
    suivant=courant->suiv;
    while(courant!=NULL){
        if(courant==debut){
            courant->suiv=NULL;
            courant->prec=suivant;
            suivant->prec=courant;
        }   
        else{
            courant->suiv=precedent;
            courant->prec=suivant;
            if(suivant!=NULL){
                suivant->prec=courant;
            }
            if(precedent!=NULL){
                precedent->suiv=courant;
            }
        }
        precedent=courant;
        courant=suivant;
        suivant=suivant->suiv;
    }
}

/* Deuxieme methode -> on va deplacer photos par 
photos la categorie famille a la fin de la liste */

void deplacement(int comp_fam ){
    lsc *courant, *e;
    int i;
    i=0;
    e=debut;
    courant=debut->suiv;
    while (i<=comp_fam && strcmp(e->index, "famille")==0){
        while(courant->suiv!=NULL){
            courant=courant->suiv;
        }
        courant->suiv=e;
        e->prec=courant;
        e->suiv=NULL;
        debut=debut->suiv;
        e=debut;
        courant=e->suiv;
        i++;
    }
}

/* fonction pour afficher les photos*/
void afficher(){
    lsc *courant;
    courant=debut;
    while(courant!=NULL){
        printf("%s %s %d %d %d\n", courant->chem, courant->index, courant->date.jour, courant->date.mois, courant->date.annee);
        courant=courant->suiv;
    }
}

/* ecrivons la fonction main pour tester les differentes fonctions precedentes*/
int main(){
    int comp_fam, comp_loisir;
    ajouterphotos((Date){1, 1, 2022}, "photo1", "famille");
    ajouterphotos((Date){2, 2, 2022}, "photo2", "loisir");
    ajouterphotos((Date){3, 3, 2022}, "photo3", "famille");
    ajouterphotos((Date){5, 5, 2022}, "photo5", "famille");
    ajouterphotos((Date){6, 6, 2022}, "photo6", "loisir");
    ajouterphotos((Date){7, 7, 2022}, "photo7", "famille");
    ajouterphotos((Date){8, 8, 2022}, "photo8", "loisir");
    ajouterphotos((Date){9, 9, 2022}, "photo9", "famille");
    ajouterphotos((Date){10, 10, 2022}, "photo10", "loisir");
    comptercategorie(&comp_fam, &comp_loisir);
    printf("Nombre de photos de famille: %d\n", comp_fam);
    printf("Nombre de photos de loisir: %d\n", comp_loisir);
    trie();
    afficher();
    changement();
    afficher();
    deplacement(comp_fam);
    afficher();
    return 0;
}

