#include "fantasy.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

//Personnage
int make_hero(Character* Hero, Materia* l_materia, Weapon* l_weapon, Armor* l_armor){

	int i, str=0, dex=0, mag=0, vit=0, sp=0, luck=0, retour=1;

	//numero arme
		Hero->weapon = select_weapon(l_weapon, l_materia, Hero->mat_w);
	//numero armure
		Hero->armor = select_armor(l_armor, l_materia, Hero->mat_a);
	//somme materia
		str = l_weapon[Hero->weapon].str;
			for(i=0; i<=7; i++)
				if (Hero->mat_w[i] != 24)
					str += l_materia[ Hero->mat_w[i] ].str;
			

		mag = l_weapon[Hero->weapon].mag;
			for(i=0; i<=7; i++)
				if (Hero->mat_w[i] != 24)
					mag += l_materia[ Hero->mat_w[i] ].mag;
		
		dex = l_weapon[Hero->weapon].dex;

		vit = l_armor[Hero->armor].vit;	

		sp = l_armor[Hero->armor].sp;	

		luck = l_armor[Hero->armor].luck;	

	//Affectation materia
	Hero->str = str; Hero->mag = mag; Hero->dex = dex; Hero->vit = vit; Hero->sp = sp; Hero->luck = luck;

	//Affichage du héros une fois terminé
	show_hero(Hero, l_weapon, l_armor, l_materia);

	//Ecriture du hero
	write_hero(Hero);
		
	printf("Vous pouvez retourner au menu(1) ou quitter(0) : ");
	scanf("%d", &retour);

	return retour;
} //Fin make_hero


//Ecire le hero dans un fichier
int write_hero(Character* Hero){
		
	char* nom_f = concat(Hero->name, ".hero");

	FILE* fp = fopen( nom_f, "w");
	
	fprintf(fp,

		"%s\n"//nom 
		"%d %d %d %d %d %d %d %d %d\n"//noméro arme + numéro materias
		"%d %d %d %d %d %d %d %d %d\n"//noméro armure + numéro materias
		"%d %d %d %d %d %d",//force, vit, magie, dext, vit, chance
		Hero->name,
		Hero->weapon, Hero->mat_w[0], Hero->mat_w[1], Hero->mat_w[2], Hero->mat_w[3], Hero->mat_w[4], Hero->mat_w[5], Hero->mat_w[6], Hero->mat_w[7], 
		Hero->armor, Hero->mat_a[0], Hero->mat_a[1], Hero->mat_a[2], Hero->mat_a[3], Hero->mat_a[4], Hero->mat_a[5], Hero->mat_a[6], Hero->mat_a[7], 
		Hero->str, Hero->vit, Hero->mag, Hero->dex, Hero->sp, Hero->luck );	

	fclose(fp);
	free(nom_f);	

	return 1;
} //Fin write_hero


//Afficher le hero
void show_hero(Character* Hero, Weapon* l_weapon, Armor* l_armor, Materia* l_materia){
	printf( "------------------------------\n"
		"Voici votre héros : \n"
		"------------------------------\n"
		"Nom : %s\n"
		"Arme : %s\n"
		"Materia de l'arme : %s  %s  %s  %s  %s  %s  %s  %s\n"
		"Armure : %s\n"
		"Materia de l'armure : %s  %s  %s  %s  %s  %s  %s  %s\n"
		"Force : %d\nVitalité : %d\nMagie : %d\nDexterité : %d\nVitesse : %d\nChance : %d\n\n",
		/* Nom */	Hero->name,
		/* Armre */	l_weapon[Hero->weapon].name,
		/* Materia */	l_materia[ Hero->mat_w[0] ].name, l_materia[ Hero->mat_w[1] ].name, l_materia[ Hero->mat_w[2] ].name, l_materia[ Hero->mat_w[3] ].name, l_materia[ Hero->mat_w[4] ].name, l_materia[ Hero->mat_w[5] ].name, l_materia[ Hero->mat_w[6] ].name, l_materia[ Hero->mat_w[7] ].name,
		/* Armure */	l_armor[Hero->armor].name,
		/* Materia */	l_materia[ Hero->mat_a[0] ].name, l_materia[ Hero->mat_a[1] ].name, l_materia[ Hero->mat_a[2] ].name, l_materia[ Hero->mat_a[3] ].name, l_materia[ Hero->mat_a[4] ].name, l_materia[ Hero->mat_a[5] ].name, l_materia[ Hero->mat_a[6] ].name, l_materia[ Hero->mat_a[7] ].name,
		/* Force, vitalité, magie, dexterité, vitesse, chance */
		Hero->str, Hero->vit, Hero->mag, Hero->dex, Hero->sp, Hero->luck
	); //Fin printf();
} //Fin show_hero

