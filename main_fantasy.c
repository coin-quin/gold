#include "fantasy.h"
#include <stdio.h>
#include <assert.h>

int main(){
	int i;
	Character Hero = {"", -1, -1};
	for(i=0; i<9; i++){
		Hero.mat_w[i]=24;
		Hero.mat_a[i]=24;
	}

	Materia l_materia[25];
	Armor l_armor[40];
	Weapon l_weapon[20];	

	assert(read_materia(l_materia));
	assert(read_weapon(l_weapon));
	assert(read_armor(l_armor));

	int choix =1;
	while(choix){
		menu();
		scanf("%d", &choix);
		purger();
		switch(choix){

			case 1:
			select_name(Hero.name);	
			if(!make_hero(&Hero, l_materia, l_weapon, l_armor))
				choix = 0;	
				break;
			default :
				break;
		}
	}
	bye();
	return 0;
}
