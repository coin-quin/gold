#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "sdl.h"

//Compiler : `sdl-config --cflags --libs` --std=c99 

int main(int argc, char *argv[])
{
   //Variables
   SDL_Surface *screen = NULL, *rect = NULL, *imgBackGround = NULL, *item = NULL;

   //Chargement SDL
   if (SDL_Init(SDL_INIT_VIDEO) == -1)
   {
      printf("Erreur d'initianlisation SDL : %s\n", SDL_GetError());
      return EXIT_FAILURE;
    }

   //Création de la fenêtre
   if ((screen = make_screen(screen)) == NULL)
   {
      printf("Erreur d'initianlisation fenêtre : %s\n", SDL_GetError());
      return EXIT_FAILURE;
   }

   item = make_item(item, screen);
//   rect = make_rect(rect, screen);
//   imgBackGround = make_background(imgBackGround, screen);

   SDL_EnableKeyRepeat(10, 10);
   pause(screen, item);

//   SDL_FreeSurface(imgBackGround);
   SDL_FreeSurface(item);
   SDL_Quit();    
   return EXIT_SUCCESS;
}

