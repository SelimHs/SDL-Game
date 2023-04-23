#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "ES.h"
int main(int argc,char *argv)
{
SDL_Init(SDL_INIT_EVERYTHING );
SDL_Init (SDL_INIT_VIDEO | SDL_INIT_AUDIO| SDL_INIT_TIMER);
SDL_Surface* bg=IMG_Load("testbg4.jpg");
SDL_Rect pos_bg;
pos_bg.x=0;
pos_bg.y=0;
Ennemi e;

int done=1;
SDL_Surface *screen;
SDL_Event event;

InitEnnemi(&e);

screen=SDL_SetVideoMode(826,495,32,SDL_HWSURFACE |SDL_DOUBLEBUF);
while(done)
{

	SDL_BlitSurface(bg , NULL , screen , &pos_bg);
	afficherEnnemi(e, screen);
	SDL_Flip(screen);
	move (&e);
	animerEnnemi(&e);

	SDL_PollEvent(&event);
	switch(event.type)
	{
		case SDL_QUIT:
		done=0;
		break;	
	}

	
}
SDL_FreeSurface(bg);																																																																	
SDL_Quit();
return 0;
}
