#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>


typedef struct
{
	SDL_Surface *minimap;
	SDL_Rect posMm;
	SDL_Rect camera;
	
	SDL_Surface *bonhomme;
	SDL_Rect posBh;
	
	SDL_Surface *masque;
	SDL_Surface* excla[10];
	SDL_Rect posExcla;
	int exclaFrame;
	
	TTF_Font *font;
	SDL_Color color;
	SDL_Rect posTime;
	int collision;
	
	
}MINIMAP;

typedef struct{
SDL_Rect pos1,pos2;
SDL_Surface *img;
}IMAGE;


typedef struct{
SDL_Rect postxt;
TTF_Font *font;
SDL_Surface *windtxt;
SDL_Color col;
}TEXT;
typedef struct{
    IMAGE  x,o,bk;
    int tabSuiv[10];
    int joueur ;
    int nbtour;
    TEXT txt;
    int w,h;
}TicTakTo;



void init_minimap(MINIMAP *m);
void afficher_minimap(MINIMAP m,SDL_Surface *screen);
void annimer_minimap(MINIMAP *m);
void MAJMinimap(SDL_Rect posPerso,MINIMAP *m, SDL_Rect camera, int rd);
SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y);
int collisionPP(SDL_Rect posPerso,SDL_Surface* masque);
void display_time(int time,MINIMAP m,SDL_Surface *screen);



void initialiserTic (TicTakTo * t);
void afficherTic(TicTakTo t,SDL_Surface* ecran);
int atilgagne(int tabSuivi[]);
void Resultat (TicTakTo t,SDL_Surface* ecran);
void liberer( TicTakTo t);
int minmax(int tabSuivi[], int joueur);
void calcul_coup(int tabSuivi[]);
