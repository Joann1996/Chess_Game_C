#ifndef _PILE_H
#define _PILE_H

#include "maillon.h"

typedef struct pile_s{
	maillon_t* premier;
	unsigned taille;
}pile_t;



maillon_t* maillon_extraire(pile_t* p);

pile_t* pile_cree(void);
void pile_detruire(pile_t* p);

short pile_vide(pile_t* p);
unsigned pile_taille(pile_t* p);

void empiler(pile_t* p, char c);
char depiler(pile_t* p);

void afficher_pile(pile_t * p);

#endif
