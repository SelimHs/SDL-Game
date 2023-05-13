#include "perso.h"
#include "ES.h"
#include "fonction.h"
#include "minimap.h"


void init_background_jeux(Image *Backg);
int score=120;
char scorechar[100];
SDL_Rect pos_sprite;
SDL_Rect pos_screen;
SDL_Event event; 
int main()
{
TTF_Font*police=NULL;
TTF_Font*policee=NULL;
SDL_Color red={125,0,0};
SDL_Color black={255,255,255};
police=TTF_OpenFont("Trajan Pro.ttf",20); 
policee=TTF_OpenFont("Trajan Pro.ttf",30);


Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
Mix_Chunk* soundbtn;
soundbtn = Mix_LoadWAV("song.wav");


SDL_Surface *surface_score=NULL;

SDL_Color blue={253,63,146};
SDL_Color green={0,255,255};

surface_score=TTF_RenderText_Blended(police,"score :",blue);
SDL_Rect position_score; 

position_score.x=450;
position_score.y=40;

SDL_Surface *surface_message=NULL;
surface_message=TTF_RenderText_Blended(police,"",green);
SDL_Rect position_message; 
position_message.x=350;
position_message.y=200;


sprintf(scorechar,"%d",score);
SDL_Surface *surface_total_score=NULL;
surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);
SDL_Rect position_total_score;
 
position_total_score.x=520;
position_total_score.y=40;
int cont=1;



int detect_sound=0;
int detect_reponse=0;

int collision;
    SDL_Init(SDL_INIT_VIDEO);
    atexit(SDL_Quit);
    int done = 0;

    SDL_Surface *screen;
    screen = SDL_SetVideoMode(1250, 666, 32, SDL_HWSURFACE | SDL_RESIZABLE);
    if (!screen)
    {
        printf("unable to set 1250x666 video: %s\n", SDL_GetError());
        return 1;
    }
    SDL_Event event;
    Uint32 t_prev1, t_prev2,t_prev3;
    
    Image temp_background;
    init_background_jeux(&temp_background);
    
    Personne player1;
    initPerso(&player1);
    initlise_matrice(&player1);
    
    Personne player2;
   initPerso(&player2);
    initlise_matrice(&player2);
    
    SDL_Rect pos_sprite;


    int multiplayer=0;
 
  
    if (TTF_Init() == -1)
    {
        fprintf(stderr, "Failed to initialize SDL_ttf: %s\n", TTF_GetError());
        exit(1);
    }
     player1.newscore = 300;
     player1.bonus = 1;
    player1.malus = 0;
      player2.newscore = 200;
     player2.bonus = 1;
    player2.malus = 0;   
    player1.action=0;
	Ennemi e;
	InitEnnemi(&e);
	enigme ee;
	SDL_Surface *skull=NULL;
skull=IMG_Load("skulltest.png");
	init_enigmes(&ee);
	
	
	SDL_Init(SDL_INIT_EVERYTHING);
TTF_Init();


SDL_Surface *bg;
bg=IMG_Load("map.jpeg");
SDL_Rect cameraB;
cameraB.x=0;
cameraB.y=0;
cameraB.w=1080;
cameraB.h=587;
SDL_Event event1;
Uint8 *keystate;
SDL_Surface *person;
SDL_Rect personPos,personPosAbs;
person=IMG_Load("person.png");
personPos.x=0;
personPos.y=250;
personPosAbs.x=0;
personPosAbs.y=250;
MINIMAP m;
TicTakTo tik;
    tik.h=720;
    tik.w=1200;
    initialiserTic(&tik);
    int x,y,coup;
    int state=0;
init_minimap(&m);
	
    while (!done)
    {
    
	afficherEnnemi(e, screen);
	move (&e);
	animerEnnemi(&e);
	SDL_Flip(screen);
	collision=collisionBB(&player1,&e);
	int j=0;
	
	if((perso.posinscreen.x>700)&&(perso.posinscreen.x<900)) {
		annimer_minimap(&m);
	//printf("collision existe \n "); 
	animer(&ee,&pos_sprite,j);
	afficherenigme(ee,screen);
	 switch(event.type)
        {
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                cont=0;
                break;
             case SDLK_a:
            {
		if(detect_reponse==0){ 
			if(ee.reponse!=1){
				score-=20;
				init_enigmes(&ee); 
				sprintf(scorechar,"%d",score);
				surface_message=TTF_RenderText_Blended(policee,"Wrong!",red);	
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);
					
				pos_sprite.x=0;
				pos_sprite.y=0;
				
		
		for(int i=0;i<2;i++){
			for(int j=0;j<9;j++){
				SDL_Flip(screen);
				animer(&ee,&pos_sprite,j);
				SDL_BlitSurface(skull,&pos_sprite,screen,&pos_screen);
				SDL_Flip(screen);
				SDL_Delay(100);
				SDL_BlitSurface(surface_message,NULL,screen,&position_message);
				SDL_Flip(screen);}

				pos_sprite.x=0;
				pos_sprite.y+=pos_sprite.h;}
				surface_message=TTF_RenderText_Blended(policee,"",red);
				}
                               else if(ee.reponse==1){score+=20;
				sprintf(scorechar,"%d",score);
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);	
				detect_reponse=1;
				surface_message=TTF_RenderText_Blended(policee,"You Won",green);
				}}
										}break;
                        
  case SDLK_b:

            {	
		if(detect_reponse==0){
			if(ee.reponse!=2){
				score-=20;
				init_enigmes(&ee);
				detect_reponse=0;
				sprintf(scorechar,"%d",score);
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);
				surface_message=TTF_RenderText_Blended(policee,"Wrong!",red);
				pos_sprite.x=0;
				pos_sprite.y=0;
		for(int i=0;i<2;i++){
			for(int j=0;j<9;j++){
						SDL_Flip(screen);
						animer(&ee,&pos_sprite,j);
						SDL_BlitSurface(skull,&pos_sprite,screen,&pos_screen);
						SDL_BlitSurface(surface_message,NULL,screen,&position_message);
						SDL_Flip(screen);
						SDL_Delay(100);
						SDL_Flip(screen);}
				pos_sprite.x=0;
				pos_sprite.y+=pos_sprite.h;}
				surface_message=TTF_RenderText_Blended(policee,"",red);	
				}
				else if(ee.reponse==2){score+=20;
				sprintf(scorechar,"%d",score);
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);
				detect_reponse=1;
				surface_message=TTF_RenderText_Blended(policee,"You Won",green);}}
		

		}
		break;
 

		case SDLK_c:
            {	
		if(detect_reponse==0){
			if(ee.reponse!=3){
				score-=20;	
				detect_reponse=0;			
				init_enigmes(&ee);
				sprintf(scorechar,"%d",score);
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);
				surface_message=TTF_RenderText_Blended(policee,"Wrong !",red);
				pos_sprite.x=0;
				pos_sprite.y=0;
for(int i=0;i<2;i++){
		for(int j=0;j<9;j++){
				SDL_Flip(screen);
				animer(&ee,&pos_sprite,j);
				SDL_BlitSurface(skull,&pos_sprite,screen,&pos_screen);
				SDL_BlitSurface(surface_message,NULL,screen,&position_message);
				SDL_Flip(screen);
				SDL_Delay(100);
				SDL_Flip(screen);}
				pos_sprite.x=0;
				pos_sprite.y+=pos_sprite.h;
				}
				surface_message=TTF_RenderText_Blended(policee,"",red);	
				}
			else if(ee.reponse==3){score+=20;
				sprintf(scorechar,"%d",score);
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);
				detect_reponse=1;surface_message=TTF_RenderText_Blended(policee,"You Won",green);
				}}}
				break;} 
}}
	else {
	printf(" pas de collision \n "); }
	
        SDL_PollEvent(&event);
        

        switch (event.type)
        {
        case SDL_QUIT:
            done = 1;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_RIGHT:
                player1.direction = 0;
                player1.action = 1;

                break;
            case SDLK_LEFT:
                player1.direction = 1;
                player1.action = 1;
                break;
            case SDLK_UP:
                player1.saut = 1;
                break;
                         if(multiplayer==1){
            case SDLK_d:
                player2.direction = 0;
                player2.action = 1;

                break;
            case SDLK_q:
                player2.direction = 1;
                player2.action = 1;
                break;
            case SDLK_z:
                player2.saut = 1;
                break;}

            }
            break;

        case SDL_KEYUP:
            switch (event.key.keysym.sym)
            {
            case SDLK_RIGHT:
                player1.action = 0;

                break;
            case SDLK_LEFT:
                player1.action = 0;

                break;
            case SDLK_UP:
                player1.saut = 0;
                break;
                         if(multiplayer==1){
            case SDLK_d:
                player2.action = 0;

                break;
            case SDLK_q:
                player2.action = 0;

                break;
            case SDLK_z:
                player2.saut = 0;
                break;   }             
            }
            break;
        }

        if (SDL_GetTicks() - t_prev1 > 20)
        {

            afficher(temp_background, screen);
           saut(&player1);
            MovePerso(&player1);
            animerPerso(&player1);
 
             afficher_perso(player1, screen);
             if(multiplayer==1){
            saut(&player2);
            MovePerso(&player2);
            animerPerso(&player2);
            afficher_perso(player2, screen);
            player2.scoreimg.posinscreen.x=1000;
 
            }
            t_prev1 = SDL_GetTicks();
  
        }
 
 
        //

        SDL_Flip(screen); 
        SDL_PollEvent(&event);
	keystate=SDL_GetKeyState(NULL);
	if(event.type==SDL_QUIT)
	break;
	if(keystate[SDLK_RIGHT])
	{
		if(personPosAbs.x<(1080/2)-50 || (personPosAbs.x>=840+(1080/2)-50 && personPosAbs.x<1920-100))
		{
			personPosAbs.x++;
			personPos.x++;
		}
		else if(cameraB.x<=840) 
		{
			cameraB.x++;
			personPosAbs.x++;
		}
	}
	if(keystate[SDLK_LEFT])
	{
		if((personPosAbs.x<=(1080/2)-50 && personPosAbs.x>0) || personPosAbs.x>=840+(1080/2)-50 && personPosAbs.x<1920-100)
		{
			personPosAbs.x--;
			personPos.x--;
		}
		else if(cameraB.x>0) 
		{
			cameraB.x--;
			personPosAbs.x--;
		}
	}
	if(keystate[SDLK_x]){
		        if(state==1)
		            state=0;
		        else 
		            state=1;
		    }
		    
		    
		    
    	MAJMinimap(personPosAbs,&m,cameraB,25);
	display_time(SDL_GetTicks(),m,screen);
	afficher_minimap(m,screen);
    	if(state==1){
            afficherTic(tik,screen);
            if(tik.nbtour<9){
                if((tik.nbtour+tik.joueur)%2==0&&atilgagne(tik.tabSuiv)!=-1){
                    calcul_coup(tik.tabSuiv);
                    tik.nbtour++;
                }
                else{
                    if(event.type==SDL_MOUSEBUTTONDOWN){
                        x=(event.button.x-tik.bk.pos1.x)/(tik.bk.img->w/3);
                        y=(event.button.y-tik.bk.pos1.y)/(tik.bk.img->h/3);
                        coup=3*y+x;
                        if(tik.tabSuiv[coup]==0){
                            tik.tabSuiv[coup]=-1;
                            tik.nbtour++;
                        }
                    }
                }
            }
            if(atilgagne(tik.tabSuiv)!=0) {
                afficherTic(tik,screen);
                Resultat(tik,screen);
            }
        }
	m.collision=collisionPP(personPosAbs,m.masque);
	if(m.collision==1)
	annimer_minimap(&m);

	
	
	SDL_Flip(screen);
	
    }
}

void init_background_jeux(Image *Backg)
{
    Backg->img = IMG_Load("images/background.png");
    if (Backg->img == NULL)
    {
        printf("unable to load bitmap:%s\n", SDL_GetError());
        return;
    }
    Backg->posfromimg.x = 0;
    Backg->posfromimg.y = 0;
    Backg->posfromimg.h = Backg->img->h;
    Backg->posfromimg.w = Backg->img->w;

    Backg->posinscreen.x = 0;
    Backg->posinscreen.y = 0;
}
