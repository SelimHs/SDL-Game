


#ifndef FONCTION_H
#define FONCTION_H
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include "perso.h"
#include "ES.h"


/**
* @struct enigme
* @brief struct enigme
*/
typedef struct enigme
{
char question[100];
char reponse1[100];
char reponse2[100];
char reponse3[100];
int reponse;
SDL_Surface *surfacequestion;
SDL_Surface *surfacereponse1;
SDL_Surface *surfacereponse2;
SDL_Surface *surfacereponse3;
SDL_Surface *surfacereponse;

SDL_Rect positionquestion;
SDL_Rect positionreponse1;
SDL_Rect positionreponse2;
SDL_Rect positionreponse3;
SDL_Rect positionreponse;
}enigme;
void init_enigmes(enigme *e );
void animer(enigme *e,SDL_Rect *pos_sprite,int j);
void afficherenigme(enigme e,SDL_Surface *screen);
/*void sauvegarder(Personne p, background b, char *nomfichier);
void charger(Personne *p, background *b, char *nomfichier); */

#endif
