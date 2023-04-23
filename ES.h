#ifndef ES_H_INCLUDED
#define ES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


typedef struct Ennemi{
SDL_Rect pos;
SDL_Surface * image[1][3];
SDL_Surface *image_act;

int frame;
int dir;
}Ennemi;

void InitEnnemi(Ennemi * e);
void afficherEnnemi(Ennemi e, SDL_Surface *screen);
void animerEnnemi(Ennemi *e);
void move(Ennemi *e); 
//int collisionBB(Personne *p, Ennemi *e);
#endif
