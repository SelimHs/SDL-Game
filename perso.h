#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <SDL/SDL_mixer.h>

#ifndef PERSO_H
#define PERSO_H
typedef struct Image
{
	SDL_Rect posfromimg;  // to save the x,y,w,h cordinates of an image //position of display in the screen
	SDL_Rect posinscreen; // position of the photo taken
	SDL_Surface *img;	  // contain the img
} Image;

typedef struct Personne
{
	int nombredevie;
	int direction;

	int action;
	int saut;
	int deplacerhaut;
	int acceleration;
	int score;
	Image scoreimg;
	int bonus;
	int malus;
	int newscore;
	SDL_Surface *images[4][15]; 
	Image perso; 
    int i,j;
            
} Personne;
 





void animerPerso(Personne *p);
void MovePerso(Personne *p);
void saut(Personne *p);
void afficher_perso(Personne p, SDL_Surface *screen);

void afficher(Image p, SDL_Surface *screen);

 void initlise_matrice(Personne* p);
void initPerso(Personne *p);
#endif
