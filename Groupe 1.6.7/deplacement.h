#ifndef _DEPLACEMENT_H
#define _DEPLACEMENT_H

#include "plateau.h"


int abs(int n);
short deplacement_valide_pion(partie_t* pa, coordonnee_t* d, coordonnee_t* a);
short deplacement_valide_tour(partie_t* pa, coordonnee_t* d, coordonnee_t* a);
short deplacement_valide_cava(partie_t* pa, coordonnee_t* d, coordonnee_t* a);
short deplacement_valide_fou (partie_t* pa, coordonnee_t* d, coordonnee_t* a);
short deplacement_valide_dame(partie_t* pa, coordonnee_t* d, coordonnee_t* a);
short deplacement_valide_roi (partie_t* pa, coordonnee_t* d, coordonnee_t* a);

short deplacement_valide(partie_t* pa, piece_t* p, coordonnee_t* d, coordonnee_t* a);

short piece_allier(partie_t* pa, coordonnee_t* c);
short free_ligne (partie_t* pa, coordonnee_t* d, coordonnee_t* a);
short free_colone(partie_t* pa, coordonnee_t* d, coordonnee_t* a);
short free_diago (partie_t* pa, coordonnee_t* d, coordonnee_t* a);

void partie_jouer(partie_t* pa);

void rejouer_partie(partie_t * pa, char * c);

#endif
