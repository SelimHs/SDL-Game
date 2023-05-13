#include "minimap.h"
#include "math.h"


void init_minimap(MINIMAP *m)
{
	m->minimap=IMG_Load("minimap.jpeg");
	m->bonhomme=IMG_Load("reddot.png");
	m->masque=IMG_Load("masque.png");
	m->excla[0]=IMG_Load("excla/1.jpg");
	m->excla[1]=IMG_Load("excla/2.jpg");
	m->excla[2]=IMG_Load("excla/3.jpg");
	m->excla[3]=IMG_Load("excla/4.jpg");
	m->excla[4]=IMG_Load("excla/5.jpg");
	m->excla[5]=IMG_Load("excla/6.jpg");
	m->excla[6]=IMG_Load("excla/7.jpg");
	m->excla[7]=IMG_Load("excla/8.jpg");
	m->excla[8]=IMG_Load("excla/9.jpg");
	m->excla[9]=IMG_Load("excla/10.jpg");
	m->posExcla.x=1080-300;
	m->posExcla.y=20;
	m->exclaFrame=0;
	m->collision=0;
	
	m->posMm.x=1080-300;
	m->posMm.y=20;
	m->posMm.x=1080-300;
	m->posMm.y=20;
	m->camera.x=0;
	m->camera.y=0;
	m->camera.w=270;
	m->camera.h=147;
	
	
	
	m->font=TTF_OpenFont("Minecraft.ttf",26);
	m->color.r=255;
	m->color.b=255;
	m->color.g=255;
	m->posTime.x=30;
	m->posTime.y=20;
}

void afficher_minimap(MINIMAP m,SDL_Surface *screen)
{
	SDL_BlitSurface(m.minimap,&m.camera,screen,&m.posMm);
	SDL_BlitSurface(m.bonhomme,NULL,screen,&m.posBh);
	if(m.collision==1)
	SDL_BlitSurface(m.excla[m.exclaFrame],NULL,screen,&m.posExcla);
	
	
}

void annimer_minimap(MINIMAP *m)
{
	m->exclaFrame++;
	if(m->exclaFrame>9)
	m->exclaFrame=0;
	
	
}

void MAJMinimap(SDL_Rect posPerso,MINIMAP *m, SDL_Rect camera, int rd)
{
	float ratio = (float) rd/100;
	m->camera.x=camera.x * ratio;
	m->camera.y=camera.y * ratio;
	m->posBh.x=(posPerso.x-camera.x) * ratio + m->posMm.x;
	m->posBh.y=(posPerso.y-camera.y) * ratio + m->posMm.y;
}
SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y)
{
    SDL_Color color;
    Uint32 col = 0;
    // Determine Pos
    char *pPosition = (char *)pSurface->pixels;
    pPosition += (pSurface->pitch * y);
    pPosition += (pSurface->format->BytesPerPixel * x);
    memcpy(&col, pPosition, pSurface->format->BytesPerPixel);
    // convertir color
    SDL_GetRGB(col, pSurface->format, &color.r, &color.g, &color.b);
    return (color);
}      




int collisionPP(SDL_Rect posPerso,SDL_Surface* masque)
{
	SDL_Color col;
	for(int i=posPerso.x;i<posPerso.x+100;i++)
	{
		col=GetPixel(masque,i,posPerso.y);
		if(col.r==0 && col.b==255 && col.g==0)
		{
			return 1;
		}
	}
	
	for(int i=posPerso.x;i<posPerso.x+100;i++)
	{
		col=GetPixel(masque,i,posPerso.y+74);
		if(col.r==0 && col.b==255 && col.g==0)
		{
			return 1;
		}
	}
	
	for(int i=posPerso.y;i<posPerso.y+74;i++)
	{
		col=GetPixel(masque,posPerso.x,i);
		if(col.r==0 && col.b==255 && col.g==0)
		{
			return 1;
		}
	}
	
	for(int i=posPerso.y;i<posPerso.y+74;i++)
	{
		col=GetPixel(masque,posPerso.x+100,i);
		if(col.r==0 && col.b==255 && col.g==0)
		{
			return 1;
		}
	}
	return 0;
}

void display_time(int time,MINIMAP m,SDL_Surface *screen)
{
	int  timeToSeconds;
	timeToSeconds=time/1000;
	int mins;
	mins=timeToSeconds/60;
	int seconds;
	seconds=timeToSeconds % 60;

	char secondsStr[20];
	char minsStr[20];
	char timeStr[20];
	
	sprintf(minsStr,"%d",mins);
	sprintf(secondsStr,"%d",seconds);
	strcat(timeStr,minsStr);
	strcat(timeStr," : ");
	strcat(timeStr,secondsStr);
	
	SDL_Surface *timeIMG;
	timeIMG=TTF_RenderText_Blended(m.font, timeStr, m.color);
	SDL_BlitSurface(timeIMG,NULL,screen,&m.posTime);
	
}





/////////////: ticktacktooo


void initialiserTic (TicTakTo * t){
    t->bk.img=IMG_Load("tic/b.png");
    t->o.img=IMG_Load("tic/o.png");
    t->x.img=IMG_Load("tic/x.png");

    t->bk.pos1.x=t->w/2-t->bk.img->w/2;
    t->bk.pos1.y=t->h/2-t->bk.img->h/2;

    for (int i = 0; i < 9; i++)
        t->tabSuiv[i]=0;

    t->txt.font=TTF_OpenFont("28 Days Later.ttf",60);
    t->txt.postxt.x=t->w-300;
    t->txt.postxt.y=t->h-400;
    t->txt.col.r=255;
    t->txt.col.g=255;
    t->txt.col.b=255;

    t->nbtour=0;
    t->joueur=1;
}

void afficherTic(TicTakTo t,SDL_Surface* ecran){
    SDL_BlitSurface(t.bk.img,NULL,ecran,&t.bk.pos1);
    int j=0;
    for(int i=0;i<9;i++){
        if(i>2&&i<6)
            j=1;
        else if(i>5&&i<9)
            j=2;
        if(t.tabSuiv[i]==-1){
            t.x.pos1.x=t.bk.pos1.x+(t.bk.img->w*(i%3))/3; 
            t.x.pos1.y=t.bk.pos1.y+(t.bk.img->h*j)/3;
            SDL_BlitSurface(t.x.img,NULL,ecran,&t.x.pos1);
        }
        else if(t.tabSuiv[i]==1){
            t.o.pos1.x=t.bk.pos1.x+(t.bk.img->w*(i%3))/3;
            t.o.pos1.y=t.bk.pos1.y+(t.bk.img->h*j)/3;
            SDL_BlitSurface(t.o.img,NULL,ecran,&t.o.pos1);
        }
    }
}


// 1 1 1 0 0 0 0 0 0
// -1 -1 -1 0 0 0 0 0 0

int atilgagne(int tabSuivi[]){
    int lGagnantes[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int gameStillOn=0;
    for(int i=0;i<8;i++){
        if(tabSuivi[lGagnantes[i][0]]==tabSuivi[lGagnantes[i][1]]&&tabSuivi[lGagnantes[i][1]]==tabSuivi[lGagnantes[i][2]])
            return tabSuivi[lGagnantes[i][0]];
    }
    //return -1;
}


void Resultat(TicTakTo t,SDL_Surface* ecran){
    char message[100];
    if(atilgagne(t.tabSuiv)==1)
        strcpy(message,"computer won");
    else if(atilgagne(t.tabSuiv)==-1)
        strcpy(message,"player won");
    else 
        strcpy(message,"t3adol");


    t.txt.windtxt= TTF_RenderText_Blended(t.txt.font,message,t.txt.col);
    SDL_BlitSurface(t.txt.windtxt,NULL,ecran,&t.txt.postxt);
}


int minmax(int tabSuivi[],int joueur){
    int gagnant = atilgagne(tabSuivi);
    if (gagnant != 0)
        return gagnant * joueur;
    int coup = -1;
    int score = -2;
    int i;
    for (i = 0; i < 9; i++)
    {
        if (tabSuivi[i] == 0)
        {
        {
            tabSuivi[i] = joueur;
            int mmscore = -minmax(tabSuivi, joueur * -1);
            if (mmscore > score)
            {
            score == mmscore;
            coup = i;
            }
            tabSuivi[i] = 0;
        }
        }
    }
    if (coup == -1)
        return 0;
    return score;
}

void calcul_coup(int tabSuivi[]){
    int coup = -1;
    int score = -2;
    int i;
    for (i = 0; i < 9; i++)
    {
        if (tabSuivi[i] == 0)
        {
        tabSuivi[i] = 1;
        int mmscore = -minmax(tabSuivi, -1);
        tabSuivi[i] = 0;
        if (mmscore > score)
        {
            score = mmscore;
            coup = i;
        }
        }
    }
    tabSuivi[coup] = 1;
}

