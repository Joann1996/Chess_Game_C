#include "deplacement.h"
#include <stdio.h>
#include <string.h>




int abs(int n){

  int res[2];
  res[0] = n; res[1] = -n;
  return res[n<0];
}

short piece_allier(partie_t* pa, coordonnee_t* c){
  short au_piece = couleur(pa-> echiquier[c-> ligne][c-> colone]);
  return (pa-> tour == au_piece);
}

short free_colone(partie_t* pa, coordonnee_t* d, coordonnee_t* a){
  int i;
  /*gauche ou droite ?*/
  if(d-> colone < a-> colone){
    /*droite*/
    i = 1;
    while (d-> colone+i != a-> colone) {
      if(pa-> echiquier[d-> ligne][d-> colone + i] != '.')
        return 0;
      i++;
    }
  }
  /*gauche*/
  else{
    i = -1;
    while (d-> colone+i != a-> colone){
      if(pa-> echiquier[d-> ligne][d-> colone + i] != '.')
        return 0;
      i--;
    }
  }

  return 1;
}

short free_ligne (partie_t* pa, coordonnee_t* d, coordonnee_t* a){
  int i;
  /*haut ou bas ?*/
  if(d-> ligne < a-> ligne){
    /*bas*/
    i = 1;
    while (d-> ligne+i != a-> ligne) {
      if(pa-> echiquier[d-> ligne + i][d-> colone] != '.')
        return 0;
      i++;
    }
  }
  /*haut*/
  else{
    i = -1;
    while(d-> ligne+i != a-> ligne){
      if(pa-> echiquier[d-> ligne + i][d-> colone] != '.')
        return 0;
      i--;
    }
  }

  return 1;

}

short free_diago (partie_t* pa, coordonnee_t* d, coordonnee_t* a){
  int i;
  /*NW -> SE ou SE -> NW ou NE -> SW ou SW -> NE ?*/
  if(d-> colone < a-> colone){
    /*direction est*/
    if(d-> ligne < a-> ligne){
      /*c'est donc NW-> SE*/
      for(i = 1; d-> colone + i == a-> colone; i++)
        if(pa->echiquier[d-> ligne + i][d-> colone + i] != '.')
          return 0;
    }
    else{
      for(i = 1; d-> colone + i == a-> colone; i++)
        if(pa->echiquier[d-> ligne - i][d-> colone + i] != '.')
          return 0;
    }
  }
  else{
    /*direction ouest*/
    if(d-> ligne < a-> ligne){
      /*c'est donc NE -> SW*/
      for(i = -1; d-> colone + i == a-> colone; i--)
          if(pa->echiquier[d-> ligne - i][d-> colone + i] != '.')
            return 0;
    }
    else{
      for(i = -1; d-> colone + i == a-> ligne; i--)
        if(pa->echiquier[d-> ligne -i][d-> colone - i] != '.')
          return 0;
    }
  }
  return 1;
}

/**********************************************************/
short deplacement_valide_pion(partie_t* pa, coordonnee_t* d, coordonnee_t* a){
  if(!piece_allier(pa, d))
    return 0;
  if(piece_allier(pa, a))
    return 0;

  if(pa-> tour == 0){
    if((d-> ligne - a-> ligne) < 0 )
      return 0;
    if(d-> ligne != 6 && (d-> ligne - a-> ligne) != 1)
      return 0;
  }
  else{
    if((d-> ligne - a-> ligne > 0))
      return 0;
    if(d-> ligne != 1 && (a-> ligne - d-> ligne) != 1)
      return 0;
  }
  if(abs(a-> ligne - d-> ligne) > 2)
    return 0;
  if((d-> colone != a-> colone) && case_vide(pa, a))
    return 0;
  if((d-> colone == a-> colone) && !case_vide(pa,a))
    return 0;

  return 1;
}

short deplacement_valide_tour(partie_t* pa, coordonnee_t* d, coordonnee_t* a){
  if(!piece_allier(pa, d))
    return 0;
  if(!cmp_coordonnee(d,a))
    return 0;
  if(piece_allier(pa, a))
    return 0;
  if(d-> ligne == a-> ligne)
    return free_colone(pa,d, a);
  if(d-> colone == a-> colone)
    return free_ligne(pa,d,a);
  return 0;
}

short deplacement_valide_cava(partie_t* pa, coordonnee_t* d, coordonnee_t* a){
  if(!piece_allier(pa, d))
    return 0;
  if(piece_allier(pa, a))
    return 0;
  if((d-> ligne == a-> ligne) || (d-> colone == a-> colone))
    return 0;
  if(abs(a-> ligne - d-> ligne) + abs(a-> colone - d-> colone) != 3)
    return 0;
  return 1;
}

short deplacement_valide_fou (partie_t* pa, coordonnee_t* d, coordonnee_t* a){
  if(!piece_allier(pa, d))
    return 0;
  if(!cmp_coordonnee(d,a))
    return 0;
  if(piece_allier(pa, a))
    return 0;
  if((d-> ligne == a-> ligne) || (d-> colone == a-> colone))
    return 0;
  return free_diago(pa,d,a);
}

short deplacement_valide_dame(partie_t* pa, coordonnee_t* d, coordonnee_t* a){
  if(!piece_allier(pa, d))
    return 0;
  if(!cmp_coordonnee(d,a))
    return 0;
  if(piece_allier(pa, a))
    return 0;
  if(d-> ligne == a-> ligne)
    return free_colone(pa,d, a);
  if(d-> colone == a-> colone)
    return free_ligne(pa,d,a);
  return free_diago(pa,d,a);
}
short deplacement_valide_roi (partie_t* pa, coordonnee_t* d, coordonnee_t* a){
  if(!piece_allier(pa, d))
    return 0;
  if(!cmp_coordonnee(d,a))
    return 0;
  if(piece_allier(pa, a))
    return 0;
  if((abs(a-> ligne - d-> ligne) > 1) || (abs(a-> colone - d-> colone) > 1))
    return 0;
  /*a ajouter (la case n'est pas attaqué)*/
  return 1;
}

short deplacement_valide(partie_t* pa, piece_t* p, coordonnee_t* d, coordonnee_t* a){
  if(!case_vide(pa, d)){
    switch (p-> type) {
      case 'p':return deplacement_valide_pion(pa,d,a); break;
      case 't':return deplacement_valide_tour(pa,d,a); break;
      case 'c':return deplacement_valide_cava(pa,d,a); break;
      case 'f':return deplacement_valide_fou (pa,d,a); break;
      case 'd':return deplacement_valide_dame(pa,d,a); break;
      case 'r':return deplacement_valide_roi (pa,d,a); break;
      default : printf("erreur type ! \n"); break;
    }
  }
  return 0;
}

/*----------------------------------------------------------*/

void partie_jouer(partie_t* pa){
	coordonnee_t* depart;
	coordonnee_t* arrive;
  piece_t* ma_piece;
	char s[256];
	char sav;
  char slot[32];

	while(1){
		start:
		afficher_echiquier(pa);
		if(pa-> tour == 0)
		printf("Trait au blanc: \n");
		else
		printf("Trait au noir: \n");
		/* imput */
		scanf(" %s", s);
		if(!strcmp(s, "fin"))
			break;
		if(!strcmp(s, "redo"))
			annuler_deplacement(pa);
		if(!strcmp(s, "aide")){
      printf("aide: afficher le manuel des commandes\n");
      printf("coup: affiche la liste des coups précedent\n"); /* voir une foi la fonction affiche coup ameliorer*/
      printf("prise: affiche la liste des pieces capuré\n"); /* voir une foi la fontion affiche piece ameliorer*/
			printf("fin: metre fin a la partie\n");
			printf("redo: annuler le deplacement precedent\n");
			printf("Pour jouer, indiquer les cordonnees de deplacement \t depart -> arriver\n");
			printf("la notation est traditionnel; indiquer par une lettre(a--h) la colonne, puis par un chiffre(1--8) la ligne\n");
			printf("exemple: h8e7, d4f7\n");
      pa-> tour++;
		}
		else{
      printf("%c %c %c %c\n",s[0],s[1],s[2],s[3]);
		/* verifion que c'est bien un coup*/
		if(s[0] < 'a'|| s[0] > 'h' || s[1] < '1' ||
		 	 s[1] > '8'|| s[2] < 'a' || s[2] > 'h' ||
			 s[3] < '1'|| s[3] > '8'){
				 printf("Mauvaise entrer; tapez 'aide'\n");
				 goto start;
			 }
			 depart = coordonnee_string(s);
			 arrive = coordonnee_string(&s[2]);
       printf("%d%d %d%d\n",depart-> ligne, depart-> colone, arrive-> ligne, arrive-> colone);
       		 ma_piece = piece_identifier(pa-> echiquier[depart-> ligne][depart-> colone]);
			 if(deplacement_valide(pa, ma_piece, depart, arrive)){
				 deplacement(pa, depart, arrive);
			 }
			 else{
				 printf("le deplacement proposez est invalide, entrez en un autre\n");
				 goto start;
			 }
		}
		changer_joueur(pa);
    /* manque un test pour voir si "echec et mat !"*/
	}
	fin:
	printf("Desirez vous sauvegarder la partie (y/n) ?");
	scanf(" %c", &sav);
	switch (sav) {
		case 'y':
    printf("Veuillez choisir parmi les 3 espaces de sauvegarde suivant :\n");
    printf("1.slot1.txt \t 2.slot2.txt \t 3.slot3.txt\n");
    scanf(" %s", slot);
    partie_sauvegarder(pa, slot);
    printf("La partie à été sauvegarder\n");break; /*Il faut penser a creer les slot 1 2 et 3, je vais essayer de faire une fonction qui regarde si slot est déja utilisé*/
		case 'n': break; /*ferme le programme sans sauvegarder*/
		default : goto fin; /* mauvaise entrer du jouer*/
	}
}
void rejouer_partie(partie_t * pa, char * c)
{
  FILE *fichier=NULL;
  char * chaine=NULL;
  char s[256];
  piece_t * ma_piece;
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
          printf("%c %c %c %c\n",s[0],s[1],s[2],s[3]);
               /* verifion que c'est bien un coup*/
          if(s[0] < 'a'|| s[0] > 'h' || s[1] < '1' ||
            s[1] > '8'|| s[2] < 'a' || s[2] > 'h' ||
            s[3] < '1'|| s[3] > '8')
          {
            printf("Mauvaise entrer\n");
          }
          depart = coordonnee_string(s);
          arrive = coordonnee_string(&s[2]);
          printf("%d%d %d%d\n",depart-> ligne, depart-> colone, arrive-> ligne, arrive-> colone);
          ma_piece = piece_identifier(pa-> echiquier[depart-> ligne][depart-> colone]);
          if(deplacement_valide(pa, ma_piece, depart, arrive))
          {
            deplacement(pa, depart, arrive);
          }
          else
          {
            printf("le deplacement proposez est invalide\n");
          }
          changer_joueur(pa);
        }
      }
    }
    else
      printf("Ce n'est pas le bon format\n");
  }
  else
    printf("Le fichier n'existe pas\n");
}