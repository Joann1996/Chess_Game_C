#include "double_liste.h"
#include <stdlib.h>
#include <stdio.h>

maillon_coup_t* maillon_c_cree(coup_t* c){

  maillon_coup_t* res = malloc(sizeof(maillon_coup_t));
  res-> coup = c;
  res-> suivant = NULL;
  res-> precedent = NULL;
  return res;
}

void maillon_c_detruire(maillon_coup_t* c){
  free(c);
}

liste_t* liste_initialiser(void){
  liste_t* res = malloc(sizeof(liste_t));
  res-> premier = NULL;
  res-> dernier = NULL;
  res-> taille  = 0;
  return res;
}

short liste_vide(liste_t* l){
  return (l-> taille)? 0:1;
}

void liste_ajouter_debut(liste_t* l, maillon_coup_t* c){
  if(liste_vide(l))
    l-> dernier = c;
  else{
    c-> precedent = l-> premier;
    l-> premier-> suivant = c;
  }
  l-> premier = c;
  l-> taille++;
}

void liste_ajouter_fin(liste_t* l, maillon_coup_t* c){
  if(liste_vide(l))
    l-> premier = c;
  else{
    c-> suivant = l-> dernier;
    l-> dernier-> precedent = c;
  }
  l-> dernier = c;
  l-> taille++;
}

maillon_coup_t* liste_extraire_debut(liste_t* l){
  maillon_coup_t* res = l-> premier;
  if(!liste_vide(l)){
    l-> premier = res-> precedent;
    res-> precedent = NULL;
    l-> taille--;
  }
  if(liste_vide(l))
    l-> dernier = NULL;
  else{
    l-> premier-> suivant = NULL;
    res-> suivant = NULL;
   }
  return res;
}

maillon_coup_t* liste_extraire_fin(liste_t* l){
  maillon_coup_t* res = l-> dernier;
  if(!liste_vide(l)){
    l-> dernier = l-> dernier-> suivant;
    res-> suivant = NULL;
    l-> taille--;
  }
  if(liste_vide(l))
    l-> premier = NULL;
  else{
    l-> premier-> precedent = NULL;
    res-> precedent = NULL;
  }
  return res;
}

void liste_tourner(liste_t* l){
  liste_ajouter_debut(l, liste_extraire_fin(l));
}
/**
void liste_afficher(liste_t* l){
  maillon_coup_t* tmp;
  for(tmp = l-> dernier; tmp != NULL; tmp = tmp-> suivant)
    printf("%s\n", tmp-> coup);
}
**/
void liste_detruire(liste_t * l)
{
  while(!liste_vide(l))
    maillon_c_detruire(liste_extraire_debut(l));
  free(l);
}

short last_prise(liste_t* l){
  return coup_prise(l-> premier-> coup);
}
