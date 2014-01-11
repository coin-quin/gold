#include "fantasy.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

/* MENU */
void menu(){
	system("clear");
	printf(	"\033[40;01mMENU\033[00m\n"
		"-----\n"
		"1. Créer un nouveau personnage\n"
		"2. Afficher le personnage\n"
		"0. Quitter\n"
		"Choix : ");
}

/* CREATION PERSONNAGE */
//Choix du nom
void select_name(char* name){
	system("clear");
	printf("Choisissez le nom de votre héros : ");
	scanf("%[^\n]", name);
	
	system("clear");
}

//Affichage materia
int show_materia(Materia* l_materia){
	assert(l_materia != NULL);

	int i;
	printf("\n");
	for (i=0; i<=20; i++){
		printf("%2d || %20s || Force : %d | Magie : %d\n",
          i, l_materia[i].name, l_materia[i].str, l_materia[i].mag);
	}
	return 1;
}

//Choix de l'arme
int select_weapon(Weapon* l_weapon, Materia* l_materia, int* choix_w){
	assert(l_weapon != NULL && l_materia != NULL);

	printf( "Choisissez une arme dans la liste ci dessous : \n\n");
	
	int i, n_w;
	for(i=0;i<=15;i++){
		printf("\033[31;01m%3d\033[00m || \033[4;01m%20s\033[00m ||
            Force : \033[33;01m%3d\033[00m  | Dextérité : \033[36;01m%3d\033[00m
            | Magie : \033[38;01m%3d\033[00m  | Slots materia : \033[39;01m%3d\033[00m \n"            , i, l_weapon[i].name, l_weapon[i].str, l_weapon[i].dex,
            l_weapon[i].mag, l_weapon[i].slots);
	}

	do{
		printf("Arme n° : ");
		scanf("%d", &n_w);
	
		if (n_w > 15 || n_w < 0)
			printf("Cette arme n'existe pas.\n");

	}while(n_w > 15 || n_w < 0);		
		
	if(l_weapon[n_w].slots != 0){
		system("clear");
		select_materia_w(l_weapon, l_materia, n_w, choix_w);
	}

	system("clear");
	return n_w;
}

//Choix des materia de l'arme
int select_materia_w(Weapon* l_weapon, Materia* l_materia, int n_w, int* choix_w){

	int n_mat=0, i;
	printf( "Choisissez vos materia, votre arme peut en porter %d\n",l_weapon[n_w].slots);

	do{
		printf("Combien voulez-vous en acheter ? ");
		scanf("%d", &n_mat);
		if (n_mat > l_weapon[n_w].slots)
			printf("Vous ne pouvez pas porter autant de materia.\n");
		
	}while(n_mat > l_weapon[n_w].slots);

	show_materia(l_materia);

	for(i=0; i < n_mat; i++){
		do{ 
			printf("Materia %d : ",i+1);
			scanf("%d", &choix_w[i]);
			if(choix_w[i] < 0 || choix_w[i] > 20)
				printf("Ce materia n'existe pas.\n");
					
		}while(choix_w[i] < 0 || choix_w[i] > 20);
	}
	
	return 1;
}

//Choix de l'armure
int select_armor(Armor* l_armor, Materia* l_materia, int* choix_a){
	assert(l_armor != NULL && l_materia != NULL);	

	printf( "Choisissez une armure dans la liste ci dessous : \n\n");
	
	int i, n_a;
	for(i=0;i<=30;i++){
		printf("%3d || %20s || Vitalité : %3d | Vitesse : %3d | Chance : %3d | Slots materia : %d\n", i, l_armor[i].name, l_armor[i].vit, l_armor[i].sp, l_armor[i].luck, l_armor[i].slots);
	}

	do{
		printf("Armure n° : ");
		scanf("%d", &n_a);
		if (n_a > 30 || n_a < 0)
			printf("Cette armure n'existe pas.\n");

	}while(n_a > 30 || n_a < 0);

	if(l_armor[n_a].slots != 0){
		system("clear");
		select_materia_a(l_armor, l_materia, n_a, choix_a);
	}

	system("clear");
	return n_a;
}

//Choix des materia de l'armure
int select_materia_a(Armor* l_armor, Materia* l_materia, int n_a, int* choix_a){

	int n_mat=0, i;
	printf( "Choisissez vos materia, votre armure peut en porter %d\n",l_armor[n_a].slots);

	do{
		printf("Combien voulez-vous en acheter ? ");
		scanf("%d", &n_mat);
		if (n_mat > l_armor[n_a].slots)
			printf("Vous ne pouvez pas porter autant de materia.\n");
		
	}while(n_mat > l_armor[n_a].slots);

	show_materia(l_materia);

	for(i=0; i < n_mat; i++){
		do{ 
			printf("Materia %d : ",i+1);
			scanf("%d", &choix_a[i]);
			if(choix_a[i] < 0 || choix_a[i] > 20)
				printf("Ce materia n'existe pas.\n");
					
		}while(choix_a[i] < 0 || choix_a[i] > 20);
	}
	
	return 1;
}

