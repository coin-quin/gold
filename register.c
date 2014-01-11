#include "fantasy.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

/* LECTURE FICHIERS */
//Lecture et enregistrement des materias
int read_materia(Materia* l_materia){
	FILE* fp = fopen("dat/materia.dat","r");
		if (fp == NULL)
			return 0;
	
	int i=0;
	while (fscanf(fp, "%[^\n] %d %d\n", l_materia[i].name, &l_materia[i].str, &l_materia[i].mag) >0){
		i++;
	}

	fclose(fp);

	return 1;
}

//Lecture et enregistrement des amures
int read_armor(Armor* l_armor){
	FILE* fp = fopen("dat/armor.dat","r");
		if (fp == NULL)
			return 0;
	
	int i=0;
	while (fscanf(fp, "%[^\n] %d %d %d %d\n", l_armor[i].name, &l_armor[i].vit, &l_armor[i].sp, &l_armor[i].luck, &l_armor[i].slots) >0){
		i++;
	}

	fclose(fp);

	return 1;
}

//Lecture et enregistrement des armes
int read_weapon(Weapon* l_weapon){
	FILE* fp = fopen("dat/weapon.dat","r");
		if (fp == NULL)
			return 0;
	
	int i=0;
	while (fscanf(fp, "%[^\n] %d %d %d %d\n", l_weapon[i].name, &l_weapon[i].str, &l_weapon[i].dex, &l_weapon[i].mag, &l_weapon[i].slots) >0){
		i++;
	}

	fclose(fp);

	return 1;
}

