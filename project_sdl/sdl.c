#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "sdl.h"

void pause(SDL_Surface *screen, SDL_Surface *item)
{
   int continuer = 1, tempsPrecedent = 0, tempsActuel = 0;;
   SDL_Event event;
   SDL_Rect posItem;
   SDL_Surface *img = NULL;
   posItem.x = screen->w / 2 - item->w / 2;
   posItem.y = screen->w / 2 - item->h / 2;
 
//   img = make_background(img, screen);

   while (continuer)
   {
      SDL_PollEvent(&event);
      switch(event.type)
      {
         case SDL_QUIT:
            continuer = 0;
            break;

         case SDL_MOUSEMOTION:
            posItem.x = event.motion.x - item->w / 2;
            posItem.y = event.motion.y - item->h / 2;
            break;

         case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
               case SDLK_ESCAPE:
                  continuer = 0;
                  break;
               case SDLK_F5:
                  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                  break;
               case SDLK_UP:
                  posItem.y--;
                  break;
               case SDLK_DOWN:
                  posItem.y++;
                  break;
               case SDLK_LEFT:
                  posItem.x--;
                  break;
               case SDLK_RIGHT:
                  posItem.x++;
                  break;
              default:
                  break;
            }

         default:
            break;
      }//Fin switch event.type

/*    tempsActuel = SDL_GetTicks();
      if (tempsActuel - tempsPrecedent > 30)
      {
         posItem.x++;
         tempsPrecedent = tempsActuel;
      }
*/

 //  img = make_background(img, screen);
      SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
      SDL_BlitSurface(item, NULL, screen, &posItem);

      SDL_Flip(screen);
   }//Fin while continuer

}//Fin pause()

//FENETRE
SDL_Surface* make_screen(SDL_Surface* screen)
{
   SDL_WM_SetIcon(SDL_LoadBMP("zozor.bmp"), NULL);
   screen = SDL_SetVideoMode(600, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
   if (screen == NULL)
   {
      return NULL;
   }

   SDL_WM_SetCaption("Titre fenêtre", "Titre icône");
   SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
 
   SDL_Flip(screen);

   return screen;
}

//BACKGROUND
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

//ITEM
SDL_Surface* make_item(SDL_Surface* item, SDL_Surface* screen)
{
   SDL_Rect position;
   item = SDL_LoadBMP("zozor.bmp");
   position.x = screen->w / 2 - item->w / 2;
   position.y = screen->w / 2 - item->h / 2;
   SDL_SetColorKey(item, SDL_SRCCOLORKEY, SDL_MapRGB(item->format, 0, 0, 255));
   SDL_SetAlpha(item, SDL_SRCALPHA, 255);
   SDL_BlitSurface(item, NULL, screen, &position);

   SDL_Flip(screen);
   return item;
}

//SURFACE
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

