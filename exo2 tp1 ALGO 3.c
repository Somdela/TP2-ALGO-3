#include<stdio.h>
#include<stdlib.h>
#define max 50 
 typedef struct{
 	typedef  int file[max] ;
 	int ar, av;
 }File;


/*variables globales*/
File F1,F2,F3;

int file_vide(File p){return(p.ar==p.av);}
	
void initialisation(File k){k.ar=0;k.av=0;}

//int file_pleine(Files t){return((t.ar+1)%max ==t.av);
//}
void enfiler(File p, file x){
	if(((p.ar)+1)%max==p.av){
		printf("Stack overflow");
		exit(1);}
	else{
		if(p.ar==max-1) p.ar=0;
		else p.ar=((p.ar)+1)%max;
		p.file[p.ar]=x;}} // on place x dans l'element de position ar	

  
File  defiler(File z){
	File tab:
	if(file_vide(z)){
		printf("stack underflow");
		exit(1);}
	else{
		if(z.av==max-1) z.av=0;
		else z.av=(z.av+1)%max;
	 	tab.file[av] =p.file[av]; //place l'entier a la position av dans$le tableau tab
	 	return tab}}

defiler_enfiler(File f1, File f2){enfiler(f2, defiler(f1).file);}

int compare(File f1, File f2){
	while(!pile_vide(f1)){
		fil1=defiler(f1);
		printf("");
	}
	
	
	fil2=defiler(f2);
	
	return(fil1.file[av]>=fil2.file[av]);}

void trions(File f1, File f2, File f3){
	int i;
	for (i=0; i<f1.ar;i++){
		
	}
}

int main(){

}
