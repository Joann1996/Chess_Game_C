#include <stdlib.h>
#include <stdio.h>
#include "deplacement.h"
void rejouer_partie(partie_t * pa, char * c)
{
	FILE *fichier=NULL;
	char * chaine=NULL;
	char * bidule;
	char s[256];
	coordonnee_t * depart;
	coordonnee_t * arrive;
	fichier=fopen(c, "r+");
	if(fichier!=NULL)
	{
		fgets(chaine, 3, fichier);
		fputs("\n", fichier);
		if(strcmp(chaine,"PR")==0)
		{
			fgets(s, 5, fichier);
			while(s!=NULL)
			{
				while(1)
				{
					afficher_echiquier(pa);
					if(pa-> tour == 0)
						printf("Trait au blanc: \n");
					else
						printf("Trait au noir: \n");
					fgets(s, 5, fichier);
					fputs("\n",fichier);
					else{
      					printf("%c %c %c %c\n",s[0],s[1],s[2],s[3]);
						/* verifion que c'est bien un coup*/
					if(s[0] < 'a'|| s[0] > 'h' || s[1] < '1' ||
		 	 			s[1] > '8'|| s[2] < 'a' || s[2] > 'h' ||
			 			s[3] < '1'|| s[3] > '8'){
				 		printf("Mauvaise entrer\n");
			 			}
			 		depart = coordonnee_string(s);
			 		arrive = coordonnee_string(&s[2]);
       				printf("%d%d %d%d\n",depart-> ligne, depart-> colone, arrive-> ligne, arrive-> colone);
       				ma_piece = piece_identifier(pa-> echiquier[depart-> ligne][depart-> colone]);
			 		if(deplacement_valide(pa, ma_piece, depart, arrive)){
				 	deplacement(pa, depart, arrive);
			 		}
			 		else{
				 	printf("le deplacement proposez est invalide\n");
			 		}
				}
				changer_joueur(pa);
			}
		}
		else
			printf("Ce n'est pas le bon format\n");
	}
	else
		printf("Le fichier n'existe pas\n");
}