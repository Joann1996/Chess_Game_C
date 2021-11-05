#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "plateau.h"

partie_t* partie_creer(void){
	int i;
	partie_t* res = malloc(sizeof(partie_t));
	res-> echiquier = malloc(8*sizeof(char*));
	for(i = 0; i < 8; i++)
		res-> echiquier[i] = malloc(8*sizeof(char));
	res-> capture = pile_cree();
	res-> joue = liste_initialiser();
	res-> tour = B;
	return res;
}

void partie_detruire(partie_t* pa){
	int i;
	for (i = 0; i < 8; ++i)
		free(pa-> echiquier[i]);
	free(pa-> echiquier);

	pile_detruire(pa-> capture);
	liste_detruire(pa-> joue);
}

short case_vide(partie_t* pa, coordonnee_t* c){
	if (pa-> echiquier[c-> ligne][c-> colone] == '.')
		return 1;
	return 0;
}

/*peut etre a modifier selon les besoins*/
void modifier_case(partie_t* pa, piece_t* p, coordonnee_t* c){
	pa-> echiquier[c-> ligne][c-> colone] = piece_caractere(p);
}

void changer_joueur(partie_t* pa){
	pa-> tour = (pa-> tour + 1)%2;
}

void afficher_echiquier(partie_t* pa){
	int i,j;
	for(i = 0; i < 8; i++)
	{
		printf("\t *--------------------------------*\n");
		printf("\t%d |",i+1);
		for(j = 0;j < 8; j++)
			printf(" %c |", pa-> echiquier[i][j]);
		printf("\n");
	}
	printf("\t *---------------------------------* \n");
	printf("\t    a   b   c   d   e   f   g   h \n");

}

void annuler_deplacement(partie_t* pa){
	if(last_prise(pa-> joue)) /* si une piece a ete prise le coup precedent*/
		depiler(pa-> capture);
	liste_extraire_debut(pa-> joue);
}


void deplacement(partie_t* pa, coordonnee_t* d, coordonnee_t* a){
  /*cette fonction suppose que le deplacement est valide; (cf enoncer)*/
  short prise = 0;
  coup_t* c = NULL; maillon_coup_t* m = NULL;
  /*si la case n'est pas vide et le deplacement valide, alors capture :*/
  if(!case_vide(pa,a)){
    empiler(pa-> capture, pa-> echiquier[a-> ligne][a-> colone]);
    prise++;
    }
    pa-> echiquier[a-> ligne][a-> colone] = pa-> echiquier[d-> ligne][d-> colone] ;
    pa-> echiquier[d-> ligne][d-> colone] = '.';

    c = coup_cree(d, a, prise);
    m = maillon_c_cree(c); liste_ajouter_debut(pa-> joue, m);
  }

/*pour john*/
coordonnee_t* saisie_case(void){
	char tmp[3];
	coordonnee_t* res;
	scanf("%s\n",tmp);
	printf("Entrez coordonnees (colone|ligne)\n");
	res = coordonnee_init(tmp[1]-'1',tmp[0]-'0');
	return res;
}

void partie_sauvegarder(partie_t* pa, char * F)
{
	int i,j;
	char chaine[3];
	FILE *fichier=fopen(F,"r+");
	if(fichier!=NULL)
	{
		fgets(chaine, 3, fichier);
		if(strcmp(chaine,"PL")==0)
		{
			fputs("\n", fichier);
			for(i=0;i<8;i++)
			{
					for(j=0;j<8;j++)
					{
						fprintf(fichier, "%c", pa->echiquier[i][j]);
					}
					fputs("\n",fichier);
			}
		}
	else
		printf("Ce n'est pas le bon format\n");
	fclose(fichier);
	}
	else
		printf("Le fichier n'existe pas\n");
}
partie_t * partie_charger(char * c)
{
	partie_t * p=partie_creer();
	int j,i;
	FILE * fichier=fopen(c, "r+");
	char truc[4];
	if(fichier!=NULL)
	{
		fgets(truc, 4, fichier);
		fputs("\n", fichier);
		if(strcmp(truc, "PLT")==0)
		{
			for(i=0;i<8;i++)
			{
				for(j=0;j<8;j++)
				{
					p->echiquier[i][j]=fgetc(fichier);
				}
				fputs("\n",fichier);
			}
			return(p);
		}
		else
		{
			printf("Ce n'est pas le bon format\n");
			return NULL;
		}
	}
	printf("Le fichier n'existe pas\n");
	fclose(fichier);
	return(0);
}
partie_t* partie_nouvelle(void){
	int i, j;
	int maj = ('a'-'A');
	char liste_piece[9] = "tcfrdfct";
	partie_t* res = partie_creer();
	for(i = 0; i < 8; i++){
		res-> echiquier[7][i] = liste_piece[i];
		res-> echiquier[6][i] = 'p';
		res-> echiquier[1][i] = ('p' - maj);
		res-> echiquier[0][i] = (liste_piece[i] - maj);
	}
	for(i = 0; i < 8; i++)
		for(j = 2; j < 6; j++)
			res-> echiquier[j][i] = '.';
	return res;
}
