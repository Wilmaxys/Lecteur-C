//fichier mescalculs.h
#ifndef EVENT
#define EVENT

#include <SDL.h>
#include <SDL_mixer.h>
#include "IHM.h"
#include "Add.h"
#include <windows.h>
#include <commdlg.h>

void playMusic(Mix_Music *musique, Musique currentMusic);

int screenEvent(int *continuer, Ecran *ecranCours, Musique *selectedMusic, Musique listMusic[], int *playing, int *currentPage, int maxPage, int *playList, int *playListSuivant, Musique* listMusicAddPlayList, int *currentAddIndex, int *currentNbMusicAddPlayList, int *currentChamp, int *currentSearch, int *createPlayList, int * nbMusique);

int addEvent(int *continuer, Ecran *ecranCours, int *currentChamp, char retour[100], char ajout[2][46], Musique listMusic[], int * nbMusique, Musique *selectedMusic, int *playing, int *playList, int *playListSuivant);

int listEvent(int *continuer, Ecran *ecranCours, int *playing, int *playList, int *playListSuivant, int *currentMusicNumber, List listPlayList[], List *currentPlayList, int *currentPage, int maxPage);

void clearRetour(char retour[]);

void supMusic(int nbMusic, int indexMusicToSup, Musique listMusic[]);

#endif