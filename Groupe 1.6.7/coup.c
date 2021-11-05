#include "coup.h"
#include <stdio.h>
#include <stdlib.h>


coordonnee_t* coordonnee_init(int l, int c){
  coordonnee_t* res = malloc(sizeof(coordonnee_t));
  res-> ligne  = l;
  res-> colone = c;
  return res;
}

coordonnee_t* coordonnee_string(char* s){
  int lig = s[1] - '1';
  int col = s[0] - 'a';
  return coordonnee_init(lig, col);
}


short cmp_coordonnee(coordonnee_t* d,coordonnee_t* a){
  if(d-> ligne != a-> ligne)
    return 1;
  return(d-> colone != a-> colone);
}


coup_t* coup_cree(coordonnee_t* d, coordonnee_t* a, short prise){
  coup_t* res = malloc(sizeof(coup_t));
  res-> depart = d;
  res-> arrive = a;
  res-> prise  = prise;
  return res;
}

short coup_prise(coup_t* c){
  return (c-> prise);
}
