#ifndef _PIECE_H
#define _PIECE_H

#define B 0
#define N 1

typedef struct piece_s{
	short couleur; /* N/B*/
	char type;    /* en minuscule p,c,f,t,d,r (a discuter)*/
}piece_t;


piece_t* piece_cree(short c, char t);

short piece_couleur(piece_t* p);
short couleur(char c);

piece_t* piece_identifier(char c);

char piece_caractere(piece_t* p);

void piece_afficher(piece_t* p);


#endif
