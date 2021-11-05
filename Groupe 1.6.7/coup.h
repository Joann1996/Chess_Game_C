#ifndef _COUP_H
#define _COUP_H


typedef struct coordonnee_s{
  int ligne;
  int colone;
}coordonnee_t;

typedef struct coup_s{
  coordonnee_t* depart;
  coordonnee_t* arrive;
  short prise; /* 0|1 */
}coup_t;

coordonnee_t* coordonnee_init(int l, int c);
coordonnee_t* coordonnee_string(char* s);
short cmp_coordonnee(coordonnee_t* d,coordonnee_t* a); /* renvoie 1 si les coordonnees sont differente*/
coup_t* coup_cree(coordonnee_t* d, coordonnee_t* a, short prise);
short coup_prise(coup_t* c);

#endif
