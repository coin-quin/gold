
/* STRUCTURES */

//Materia (21 différents)
typedef struct materia_t {
	char name[64];
	int str, mag;
}Materia;

//Arme (16 différentes)
typedef struct weapon_t {
	char name[64];
	int str, dex, mag;
	int slots;
}Weapon;

//Armure (31 différentes)
typedef struct armor_t {
	char name[64];
	int vit, sp, luck;
	int slots;
}Armor;

//Personnage
typedef struct character_t {
	char name[64];
	int weapon;
	int armor;
	int mat_w[8];
	int mat_a[8];
	int str, dex, mag, vit, sp, luck;
}Character;

/* FONCTIONS */
//Lecture et enregistrement des materias, armures et armes
int read_materia(Materia* l_materia);

int read_armor(Armor* l_armor);

int read_weapon(Weapon* l_weapon);

//Choix des armes, amrures, et materia
void select_name(char* name);

int select_weapon(Weapon* l_weapon, Materia* l_materia, int* choix_w);
int select_armor(Armor* l_armor, Materia* l_materia, int* choix_a);

int select_materia_w(Weapon* l_weapon, Materia* l_materia, int n_w, int* choix_w);
int select_materia_a(Armor* l_armor, Materia* l_materia, int n_a, int* choix_a);

int show_materia(Materia* l_materia);

//Début et fin de programme
void hello();
void menu();
void bye();
void purger(void);
char* concat(char *s1, char *s2);

//Création du héro
int make_hero(Character* Hero, Materia* l_materia, Weapon* l_weapon, Armor* l_armor);
void show_hero(Character* Hero, Weapon* l_weapon, Armor* l_armor, Materia* l_materia);
int write_hero(Character* Hero);

