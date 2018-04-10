#ifndef IHM
#define IHM

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

typedef struct
{
	char	Nom[100];
	char	Path[100];
	int		lenght;

} Musique;

typedef struct
{
	char	Nom[100];
	Musique	PlayList[100];
	int musicNumber;


} List;

typedef enum Ecran Ecran;
enum Ecran
{
	LISTE,
	AJOUT,
	PLAY
};


void drawMenu(char [100][9], SDL_Surface *);
void drawAjout(char [], SDL_Surface *, SDL_Rect );
void drawListMusic(Musique listMusic[5], SDL_Surface *ecran, int *nbMusic, int *currentPage);
void drawListPlayList(Musique listMusic[5], SDL_Surface *ecran, int *nbMusic, int *currentPage);

#endif