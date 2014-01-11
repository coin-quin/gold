#include "fantasy.h"
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define NB_MAT 25
#define NB_W 20
#define NB_A 40

int main()
{
	const int MAT_MAX = 22;
	int i;

   Character Hero = {"", -1, -1};

   for(i=0; i<9; i++)
   {
      Hero.mat_w[i]=MAT_MAX;
      Hero.mat_a[i]=MAT_MAX;
   }

   //Création des structures
   Materia l_materia[NB_MAT];
   Armor l_armor[NB_A];
   Weapon l_weapon[NB_W];        

   //Remplissage des structures + assert
   assert(read_materia(l_materia));
   assert(read_weapon(l_weapon));
   assert(read_armor(l_armor));

   int choix = true;
   while(choix)
   {
      menu();
      scanf("%d", &choix);
      purger();

      switch(choix)
      {
         case 1:
            select_name(Hero.name);        
            if(!make_hero(&Hero, l_materia, l_weapon, l_armor))
               choix = false;        
            break;

         case 2:
            break;

         case 3:
            break;

         default :
            break;
      }//Fin switch

   }//Fin while
   
   bye();
   return 0;
}//Fin main

