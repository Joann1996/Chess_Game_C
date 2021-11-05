#ifndef _LISTE_COUP_H
#define _LISTE_COUP_H
#include "coup.h"



typedef struct maillon_coup_s{
  coup_t* coup;
  struct maillon_coup_s* suivant;
  struct maillon_coup_s* precedent;

}maillon_coup_t;

typedef struct liste_s{
  maillon_coup_t* premier;
  maillon_coup_t* dernier;
  int taille;

}liste_t;

maillon_coup_t* maillon_c_cree(coup_t* c);
void maillon_c_detruire(maillon_coup_t* m);
liste_t* liste_initialiser(void);
short liste_vide(liste_t* l);
void liste_ajouter_debut(liste_t* l, maillon_coup_t* m);
void liste_ajouter_fin(liste_t* l, maillon_coup_t* m);
maillon_coup_t* liste_extraire_debut(liste_t* l);
maillon_coup_t* liste_extraire_fin(liste_t* l);
void liste_tourner(liste_t* l);
void liste_detruire(liste_t * l);
/*void liste_afficher(liste_t* l);*/
short last_prise(liste_t* l);

#endif
