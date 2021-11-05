#include "piece.h"
#include <stdio.h>
#include <stdlib.h>

piece_t* creer_piece(short c, short t){

	piece_t* piece = malloc(sizeof(piece_t));
	piece-> couleur = c;
	piece-> type    = t;
	return piece;
}

short piece_couleur(piece_t* p)	{return p-> couleur;}

short couleur(char c){
	if(c == '.')
		return -1;
	if (c < 'a')
		return 1;
	return 0;
}
/** Pour les fonctions suivantes; voir Table ASCII **/

piece_t* piece_identifier(char c){
	piece_t* res = NULL;
	short couleur; char type;
	if(c == '.')
		return res;

	couleur = B;	type = c;
	if(c < (int)'a'){
		couleur = N;
		type += ('a'-'A');
	}
	res = creer_piece(couleur, type);
	return res;
}

char piece_caractere(piece_t* p){

	char res;
	if(p == NULL)
		return '.';
	res = p->type;
	if(p-> couleur == 1){res -= 32;}
	return res;
}

void piece_afficher(piece_t* p){
	printf("%c ", piece_caractere(p));
}
