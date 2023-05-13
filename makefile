prog:main.o ES.o fonction.o perso.o minimap.o
	gcc main.o perso.o ES.o fonction.o minimap.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer
main.o:main.c
	gcc -c main.c -g
ES.o:ES.c
	gcc -c ES.c -g

perso.o:perso.c
	gcc -c perso.c -g
fonction.o:fonction.c
	gcc -c fonction.c -g
minimap.o:minimap.c
	gcc -c minimap.c -g

