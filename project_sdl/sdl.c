#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "sdl.h"

void pause()
{
   int continuer = 1;
   SDL_Event event;
   
   while (continuer)
   {
      SDL_WaitEvent(&event);
      switch(event.type)
      {
         case SDL_QUIT:
            continuer = 0;
            break;
         case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
               continuer = 0;
            break;
      }
   }

}

SDL_Surface* make_screen(SDL_Surface* screen)
{
   SDL_WM_SetIcon(SDL_LoadBMP("sdl_icone.bmp"), NULL);
   screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
   if (screen == NULL)
   {
      return NULL;
   }

   SDL_WM_SetCaption("Titre fenêtre", "Titre icône");
   SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
 
   SDL_Flip(screen);

   return screen;
}

SDL_Surface* make_background(SDL_Surface* bg, SDL_Surface* screen)
{   
   SDL_Rect position;
   position.x = 0;
   position.y = 0;

   bg = SDL_LoadBMP("lac_en_montagne.bmp");
   SDL_SetAlpha(bg, SDL_SRCALPHA, 128);
   SDL_BlitSurface(bg, NULL, screen, &position);

   SDL_Flip(screen);
   return bg;
}

SDL_Surface* make_item(SDL_Surface* item, SDL_Surface* screen)
{
   SDL_Rect position;
   position.x = 550;
   position.y = 100;
   item = SDL_LoadBMP("zozor.bmp");
   SDL_SetColorKey(item, SDL_SRCCOLORKEY, SDL_MapRGB(item->format, 0, 0, 255));
   SDL_SetAlpha(item, SDL_SRCALPHA, 255);
   SDL_BlitSurface(item, NULL, screen, &position);

   SDL_Flip(screen);
   return item;
}

SDL_Surface* make_rect(SDL_Surface* rect, SDL_Surface* screen)
{
   SDL_Rect position;
   position.x = 0;
   int x=255, y=54;
   rect = SDL_CreateRGBSurface(SDL_HWSURFACE, 900, 1, 32, 0, 0, 0, 0);
   for(int i=0; i<256; i++)
   {
      position.y = i;
      SDL_FillRect(rect, NULL, SDL_MapRGB(screen->format, i, x--, y));
      SDL_BlitSurface(rect, NULL, screen, &position);
   }

   SDL_Flip(screen);
   return rect;
}

