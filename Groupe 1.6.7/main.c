#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "deplacement.h"

int main(int argc, char *argv[]) {
  partie_t* game;
  printf("blalblablalba ?\n");
  printf("meow !\n");


  if(strlen(argv[0]) < 1){

/* le joueur choisi de jouer contre un autre joueur une nouvelle partie */
    game = partie_charger(argv[0]);
  }
  if(argv[1]!=NULL)
  {
    game = partie_nouvelle();
    rejouer_partie(game, argv[1]);
  }
  else{
/* je ne suis pqs certain que ce soit ainsi que cela fonctionne::*/
    game = partie_nouvelle();
  }
  partie_jouer(game);


  printf("\nSAYONARA\n");

  return EXIT_SUCCESS;
}