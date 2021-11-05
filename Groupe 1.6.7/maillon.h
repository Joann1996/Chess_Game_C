#ifndef _MALLION_H
#define _MALLION_H

typedef struct maillon_s{
	char piece;
	struct maillon_s* precedent;
}maillon_t;


maillon_t* maillon_cree(char c);

void maillon_detruire(maillon_t* m);


#endif
