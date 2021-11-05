#include "pile.h"
#include <stdlib.h>
#include <stdio.h>



maillon_t* maillon_extraire(pile_t* p){
	maillon_t* res = NULL;
	if(!pile_vide(p)){
		res = p-> premier;
		p-> premier = res-> precedent;
		p-> taille--;
	}
	return res;
}

pile_t* pile_cree(void){
	pile_t* res = malloc(sizeof(pile_t));
	res-> premier = NULL;
	res-> taille  = 0;
	return res;
}

void pile_detruire(pile_t* p){
	while(!pile_vide(p))
		maillon_detruire(maillon_extraire(p));
	free(p);
}

short pile_vide(pile_t* p)	{return (p-> taille)? 0:1;}

unsigned pile_taille(pile_t* p)	{return p-> taille;}

void empiler(pile_t * p, char c){
	maillon_t* m = maillon_cree(c);
	if(pile_vide(p)){
		p-> premier = m;
	}
	else{
		m-> precedent = p-> premier;
		p-> premier = m;
	}
	p-> taille++;
}

char depiler(pile_t * p){
	maillon_t* m = maillon_extraire(p);
	char res = m-> piece;
	maillon_detruire(m);
	return res;
}

void afficher_pile(pile_t * p){
	maillon_t* tmp;
	for(tmp = p-> premier; tmp != NULL; tmp = tmp-> precedent)
		printf("%c\n",tmp-> piece);
}
