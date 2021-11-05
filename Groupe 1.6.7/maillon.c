#include "maillon.h"
#include <stdlib.h>
#include <stdio.h>

maillon_t* maillon_cree(char c){
  maillon_t* res = malloc(sizeof(maillon_t));
  res-> piece = c;
  res-> precedent = NULL;
  return res;
}

void maillon_detruire(maillon_t* m){
  free(m);
}
