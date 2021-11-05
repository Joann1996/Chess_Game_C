#ifndef _PLATEAU_H
#define _PLATEAU_H

#include "piece.h"
#include "pile.h"
#include "double_liste.h"

struct partie_s{
	char** echiquier;
	pile_t * capture;
	liste_t * joue;
	short tour;
};
typedef struct partie_s partie_t;

partie_t * partie_creer(void);

void partie_detruire(partie_t* pa);

short case_vide(partie_t* pa, coordonnee_t* c);

void modifier_case(partie_t* pa, piece_t* p, coordonnee_t* c);

void changer_joueur(partie_t* pa);

void afficher_echiquier(partie_t * pa);

void deplacement(partie_t* pa, coordonnee_t* d, coordonnee_t* a);

void annuler_deplacement(partie_t* pa);

coordonnee_t* saisie_case(void);	

void partie_sauvegarder(partie_t* pa, char * F);

partie_t* partie_charger(char* c);

partie_t* partie_nouvelle(void);







#endif
