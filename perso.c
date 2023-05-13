#include "perso.h"
#include "ES.h"
#include "fonction.h"
void initPerso(Personne *p)

{
     p->nombredevie = 3;
    p->perso.posinscreen.x = 100;
    p->perso.posinscreen.y = 505;
    p->perso.posinscreen.w = 100;
    p->perso.posinscreen.h = 100;

 p->deplacerhaut=0;  
p->i=0;
p->j=0;
p->saut=0;
p->score=100;
    p->direction = 0; 
}
void afficher(Image p, SDL_Surface *screen)
{
    SDL_BlitSurface(p.img, &p.posfromimg, screen, &p.posinscreen);
}
void afficher_perso(Personne p, SDL_Surface *screen)
{
    SDL_BlitSurface(p.images[p.i][p.j], NULL, screen, &p.perso.posinscreen);
}
void animerPerso(Personne *p){
     
if(p->action==1){ 
 p->i=p->direction;
    if ( p->j  > 13)  p->j = -1;
    p->j+=1; }

else if (p->action==0) {
 p->acceleration=0;
  p->i=p->direction+2;
 
     if ( p->j > 13)  p->j = -1;
     p->j += 1; 
}
}
void MovePerso(Personne *p){

if(p->action){

if(p->perso.posinscreen.x<1100&&p->direction==0){ 
p->perso.posinscreen.x+=(10+p->acceleration);
if(p->acceleration<10) p->acceleration+=1;
}
else   
if(p->perso.posinscreen.x>0&&p->direction==1){ 
p->perso.posinscreen.x-=15;
 
}
 

}}
void saut(Personne* p) {
 if(p->saut&&p->perso.posinscreen.y==505){
    p->deplacerhaut=1;}
if(p->deplacerhaut==1){p->perso.posinscreen.y-=10;}
if(p->perso.posinscreen.y<390-(p->acceleration*6)){p->deplacerhaut=0;}
if(p->deplacerhaut==0&&p->perso.posinscreen.y<505){
   p->perso.posinscreen.y+=10; 
} 


}
 
 

void initlise_matrice(Personne* p){
    
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i <= 14; i++) {
            char filename[50];
            sprintf(filename, "images/personnage/sprite%d_%d.png", j, i);
       
            p->images[j][i] = IMG_Load(filename);
            if (p->images[j][i] == NULL) {
                printf("Error loading image: %s\n", SDL_GetError());
            }
        }
    }
}
