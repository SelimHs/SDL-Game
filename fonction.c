/**
* @file fonction.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 01, 2015
*
* Testing program for enigme
*
*/
#include "fonction.h"
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdbool.h>
#include "minimap.h"
/**
* @brief To initialize enigme
* @param e enigme
* @return Nothing
*/
void init_enigmes(enigme *e ){


int nbligne=0;

char question[100];
char reponse1[100];
char reponse2[100];
char reponse3[100];
int reponse;



FILE *f=NULL;
f=fopen("questionsans","r");
if(f!=NULL){

while(fscanf(f,"%s %s %s %s %d\n",question,reponse1,reponse2,reponse3,&reponse)!=EOF)
{
nbligne++;
}
fclose(f);
} 





srand(time(0));
int alea=rand()%(6) +1;

int check=0;


f=fopen("questionsans","r");
if(f!=NULL){

while(fscanf(f,"%s %s %s %s %d\n",e->question,e->reponse1,e->reponse2,e->reponse3,&e->reponse)!=EOF)
{
check++;
if(check==alea){
break;}

}
fclose(f);
}


e->positionquestion.x=50;
e->positionquestion.y=20;

e->positionreponse1.x=50;
e->positionreponse1.y=50;

e->positionreponse2.x=50;
e->positionreponse2.y=100;

e->positionreponse3.x=50;
e->positionreponse3.y=150;




TTF_Font*police=NULL;
police=TTF_OpenFont("Trajan Pro.ttf",20);

SDL_Color black={255,255,255}; 
SDL_Color red={255,255,255};



e->surfacequestion=TTF_RenderText_Blended(police,e->question,red);
e->surfacereponse1=TTF_RenderText_Blended(police,e->reponse1,black);
e->surfacereponse2=TTF_RenderText_Blended(police,e->reponse2,black);
e->surfacereponse3=TTF_RenderText_Blended(police,e->reponse3,black);}


/**
* @brief To initialize the background b .
* @param e enigme
* @param upos_sprite SDL_Rect
* @param j int
* @return Nothing
*/
void animer(enigme *e,SDL_Rect *pos_sprite,int j){
pos_sprite->x=j*pos_sprite->w;
 pos_sprite->x=pos_sprite->x+pos_sprite->w ;
}

/**
* @brief To initialize the background b .
* @param e enigme
* @param screen SDL_Rect
* @return Nothing
*/
void afficherenigme(enigme e,SDL_Surface *screen){
SDL_BlitSurface(e.surfacequestion,NULL,screen,&e.positionquestion);
SDL_BlitSurface(e.surfacereponse1,NULL,screen,&e.positionreponse1);
SDL_BlitSurface(e.surfacereponse2,NULL,screen,&e.positionreponse2);
SDL_BlitSurface(e.surfacereponse3,NULL,screen,&e.positionreponse3);
SDL_Flip(screen);
}

/**
* @brief To initialize the background b .
* @param p person
* @param nomfichier char
* @param b background
* @return Nothing
*/

