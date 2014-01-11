#include "fantasy.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

//Personnage
int make_hero(Character* Hero, Materia* l_materia, Weapon* l_weapon, Armor* l_armor)
{
	int i, str=0, dex=0, mag=0, vit=0, sp=0, luck=0, retour=1;

	//numero arme
		Hero->weapon = select_weapon(l_weapon, l_materia, Hero->mat_w);
	//numero armure
		Hero->armor = select_armor(l_armor, l_materia, Hero->mat_a);
	//somme materia
		str = l_weapon[Hero->weapon].str;
			for(i=0; i<=7; i++)
				if (Hero->mat_w[i] != 22)
					str += l_materia[ Hero->mat_w[i] ].str;
			

		mag = l_weapon[Hero->weapon].mag;
			for(i=0; i<=7; i++)
				if (Hero->mat_w[i] != 22)
					mag += l_materia[ Hero->mat_w[i] ].mag;
		
		dex = l_weapon[Hero->weapon].dex;

		vit = l_armor[Hero->armor].vit;

		sp = l_armor[Hero->armor].sp;

		luck = l_armor[Hero->armor].luck;

	//Affectation materia
	Hero->str = str;
   Hero->mag = mag;
   Hero->dex = dex;
   Hero->vit = vit;
   Hero->sp = sp;
   Hero->luck = luck;

	//Affichage du héros une fois terminé
	show_hero(Hero, l_weapon, l_armor, l_materia);

	//Ecriture du hero
	if (!write_hero(Hero))
      printf("L'enregistrement du Héros a échoué\n");
   
	printf("Vous pouvez retourner au menu(1) ou quitter(0) : ");
	scanf("%d", &retour);

	return retour;
} //Fin make_hero


//Ecire le hero dans un fichier
int write_hero(Character* Hero)
{
	char* nom_f = concat(Hero->name, ".hero");

	FILE* fp = fopen( nom_f, "w");
      if (fp == NULL)
         return 0;

	fprintf(fp,

		"%s\n"//nom 
		"%d %d %d %d %d %d %d %d %d\n"//noméro arme + numéro materias
		"%d %d %d %d %d %d %d %d %d\n"//noméro armure + numéro materias
		"%d %d %d %d %d %d",//force, vit, magie, dext, vit, chance
		Hero->name,

		Hero->weapon,
      Hero->mat_w[0], Hero->mat_w[1], Hero->mat_w[2], Hero->mat_w[3], Hero->mat_w[4],
      Hero->mat_w[5], Hero->mat_w[6], Hero->mat_w[7],

		Hero->armor,
      Hero->mat_a[0], Hero->mat_a[1], Hero->mat_a[2], Hero->mat_a[3], Hero->mat_a[4],
      Hero->mat_a[5], Hero->mat_a[6], Hero->mat_a[7],

		Hero->str, Hero->vit, Hero->mag, Hero->dex, Hero->sp, Hero->luck );

	fclose(fp);
	free(nom_f);	

	return 1;
} //Fin write_hero

//Afficher le hero
void show_hero(Character* Hero, Weapon* l_weapon, Armor* l_armor, Materia* l_materia)
{
	printf(  "------------------------------\n"
		      "Voici votre héros : \n"
		      "------------------------------\n"
		      "Nom : %s\n", Hero->name);

	printf(  "Arme : %s\n"
            "Materia de l'arme : ", l_weapon[Hero->weapon].name);

   for (int i=0; i<=8; i++)
      if (Hero->mat_w[i] != 22)
         printf("%s ", l_materia[Hero->mat_w[i]].name);

   printf(	"\nArmure : %s\n"
      		"Materia de l'armure : ", l_armor[Hero->armor].name);

   for (int i=0; i<=8; i++)
      if (Hero->mat_a[i] != 22)
         printf("%s ", l_materia[Hero->mat_a[i]].name);

   printf(	"\nForce : %d\nVitalité : %d\nMagie : %d\nDexterité : %d\nVitesse : %d\nChance : %d\n\n",
	         Hero->str, Hero->vit, Hero->mag, Hero->dex, Hero->sp, Hero->luck);

} //Fin show_hero


