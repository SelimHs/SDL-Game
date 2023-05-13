#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "ES.h"
#include "perso.h"
#include "fonction.h"
#include "minimap.h"
SDL_Surface *screen;

void InitEnnemi(struct Ennemi *e){
e->image_act=NULL;
e->image[0][0]=IMG_Load("runr1.png");
e->image[0][1]=IMG_Load("runr2.png");
e->image[0][2]=IMG_Load("runr3.png");
e->image[0][3]=IMG_Load("runr4.png");
e->image[1][0]=IMG_Load("runl1.png");
e->image[1][1]=IMG_Load("runl2.png");
e->image[1][2]=IMG_Load("runl3.png");
e->image[1][3]=IMG_Load("runl4.png");
//chargement des images de l'animation
e->image_act=e->image[0][0]; //initialiser l'image a afficher a la premiere image
e->pos.x=100; //à def
e->pos.y=505;
//e->frame=0;
e->frame=0;
e->dir=0;
//position et initialisation de l'image actuelle à 0
}

void afficherEnnemi(Ennemi e, SDL_Surface *screen){
	SDL_BlitSurface(e.image_act,NULL,screen,&e.pos);
//afficher l'image_act 
}


/*void animerEnnemi(Ennemi*e){ //first animer/ SEG FAULT CORE DUMPED
if (e->frame==4){
e->frame=0;}//boucle d'animation
else{
e->frame++;}
//[dir] de la direction qui est eq à la direction, meme int
//[ennemi.frame] pour parcourir les colonnes en fonction de frame

e->image_act=e->image[e->dir][e->frame];
}*/

/*void animerEnnemi(Ennemi *e){ //animer w switch w i MAKES MOVEMENT W DIR SWAP
int i;
if (e->frame==4){
e->frame=0;}//boucle d'animation
else{
e->frame++;}
switch(e->dir){
case 0:
e->image_act=e->image[1][e->frame];
break;
case 1:
e->image_act=e->image[0][e->frame];
break;
}}*/

void animerEnnemi(Ennemi*e)
{
int i;
if (i==3)
i=0;
else
(i)++;

switch (e->dir)
{
case 1:
e->image_act=e->image[0][i];
break;
case 0:
e->image_act=e->image[1][i];
break;
}

}





void move(Ennemi*e)
{

int posMAX=500;
int posMIN=100;
int speed=1;
if(e->dir==0){
    if(e->pos.x>posMIN){ 
      e->pos.x-=speed;}
 else{
     e->dir=1;
}
}else{
   if(e->pos.x<posMAX){
     e->pos.x+=speed;
}else{
    e->dir=0;
}}}

int collisionBB(Personne *p, Ennemi *e){

if ((p->perso.posinscreen.x+p->perso.posinscreen.w<e->pos.x)||(p->perso.posinscreen.x>e->pos.x+e->pos.w)||(p->perso.posinscreen.y+p->perso.posinscreen.h<e->pos.y)||(p->perso.posinscreen.y>e->pos.y+e->pos.h))
	return 0;
else
	return 1;
}










































