#include"Event.h"

void playMusic(Mix_Music *musique, Musique currentMusic) {

	//, Musique *currentMusic, int *playing, int *currentstart

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer

	{

		printf("%s", Mix_GetError());

	}


	musique = Mix_LoadMUS(currentMusic.Path); //Chargement de la musique
	Mix_PlayMusic(musique, -1); //Jouer infiniment la musique



}

void playListMusic(Musique music[]) {

}

int screenEvent(int *continuer, Ecran *ecranCours, Musique *selectedMusic, Musique listMusic[], int *playing, int *currentPage, int maxPage, int *playList, int *playListSuivant, Musique* listMusicAddPlayList, int *currentAddIndex, int *currentNbMusicAddPlayList, int *currentChamp, int *currentSearch, int *createPlayList, int * nbMusique)
{
	SDL_Event event;

	SDL_PollEvent(&event);

	int indexMusicToSup;




	switch (event.type)
	{
	case SDL_QUIT:
		*continuer = 0;
		break;
	case SDL_KEYUP:
		if (*currentChamp == 2) {
			if (event.key.keysym.sym == SDLK_1 || event.key.keysym.sym == SDLK_KP1)
			{
				*currentSearch = 1;
			}
			else if (event.key.keysym.sym == SDLK_2 || event.key.keysym.sym == SDLK_KP2)
			{
				*currentSearch = 2;
			}
			else if (event.key.keysym.sym == SDLK_3 || event.key.keysym.sym == SDLK_KP3)
			{
				*currentSearch = 3;
			}
			else if (event.key.keysym.sym == SDLK_4 || event.key.keysym.sym == SDLK_KP4)
			{
				*currentSearch = 4;
			}
			else if (event.key.keysym.sym == SDLK_5 || event.key.keysym.sym == SDLK_KP5)
			{
				*currentSearch = 5;
			}
			else if (event.key.keysym.sym == SDLK_6 || event.key.keysym.sym == SDLK_KP6)
			{
				*currentSearch = 6;
			}
			else if (event.key.keysym.sym == SDLK_7 || event.key.keysym.sym == SDLK_KP7)
			{
				*currentSearch = 7;
			}
			else if (event.key.keysym.sym == SDLK_8 || event.key.keysym.sym == SDLK_KP8)
			{
				*currentSearch = 8;
			}
			else if (event.key.keysym.sym == SDLK_9 || event.key.keysym.sym == SDLK_KP9)
			{
				*currentSearch = 9;
			}
		}
		break;
	case SDL_MOUSEBUTTONUP:
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			if (event.button.x >= 20 && event.button.x <= 95 && event.button.y >= 60 && event.button.y <= 90)
			{
				*ecranCours = AJOUT;
			}
			else if (event.button.x >= 95 && event.button.x <= 170 && event.button.y >= 60 && event.button.y <= 90)
			{
				*ecranCours = PLAY;
			}
			else if (event.button.x >= 170 && event.button.x <= 245 && event.button.y >= 60 && event.button.y <= 90)
			{
				*ecranCours = LISTE;
			}
			if (event.button.x >= 520 && event.button.x <= 535 && event.button.y >= 120 && event.button.y <= 145)
			{

				if (*currentPage > 0)
				{
					*currentPage = *currentPage - 1;
				}

			}
			else if (event.button.x >= 560 && event.button.x <= 575 && event.button.y >= 120 && event.button.y <= 145)
			{

				if (*currentPage < maxPage)
				{
					*currentPage = *currentPage + 1;
				}

			}
			else if (event.button.x >= 20 && event.button.x <= 50 && event.button.x >= 20 && event.button.y >= 410 && event.button.y <= 440)
			{
				if (strcmp(selectedMusic, " ") != 0)
				{
					*playing = 1;
				}

			}
			else if (event.button.x >= 70 && event.button.x <= 100 && event.button.x >= 20 && event.button.y >= 410 && event.button.y <= 440)
			{
				*playList = 0;

				*playing = 0;

				*playListSuivant = 0;

				

				Mix_PauseMusic();
			}
			else if (event.button.x >= 40 && event.button.x <= 200  && event.button.y >= 115 && event.button.y <= 135)
			{
				*selectedMusic = listMusic[1 + (5 * *currentPage)];
			}
			else if (event.button.x >= 40 && event.button.x <= 200 && event.button.y >= 165 && event.button.y <= 185)
			{
				*selectedMusic = listMusic[2 + (5 * *currentPage)];
			}
			else if (event.button.x >= 40 && event.button.x <= 200 && event.button.y >= 215 && event.button.y <= 235)
			{
				*selectedMusic = listMusic[3 + (5 * *currentPage)];
			}
			else if (event.button.x >= 40 && event.button.x <= 200 && event.button.y >= 265 && event.button.y <= 285)
			{
				*selectedMusic = listMusic[4 + (5 * *currentPage)];
			}
			else if (event.button.x >= 40 && event.button.x <= 200 && event.button.y >= 315 && event.button.y <= 335)
			{
				*selectedMusic = listMusic[5 + (5 * *currentPage)];
			}
			//Delete
			else if (event.button.x >= 385 && event.button.x <= 445 && event.button.y >= 115 && event.button.y <= 135)
			{
				indexMusicToSup = 1;
				supMusic(*nbMusique, indexMusicToSup, listMusic);
				*nbMusique = *nbMusique - 1;
			}
			else if (event.button.x >= 385 && event.button.x <= 445 && event.button.y >= 160 && event.button.y <= 190)
			{
				indexMusicToSup = 2;
				supMusic(*nbMusique, indexMusicToSup, listMusic);
				*nbMusique = *nbMusique - 1;
			}
			else if (event.button.x >= 385 && event.button.x <= 445 && event.button.y >= 215 && event.button.y <= 235)
			{
				indexMusicToSup = 3;
				supMusic(*nbMusique, indexMusicToSup, listMusic);
				*nbMusique = *nbMusique - 1;
			}
			else if (event.button.x >= 385 && event.button.x <= 445 && event.button.y >= 265 && event.button.y <= 285)
			{
				indexMusicToSup = 4;
				supMusic(*nbMusique, indexMusicToSup, listMusic);
				*nbMusique = *nbMusique - 1;
			}
			else if (event.button.x >= 385 && event.button.x <= 445 && event.button.y >= 315 && event.button.y <= 335)
			{
				indexMusicToSup = 5;
				supMusic(*nbMusique, indexMusicToSup, listMusic);
				*nbMusique = *nbMusique - 1;
			}
			//Fin Delete
			else if (event.button.x >= 400 && event.button.x <= 450 && event.button.y >= 55 && event.button.y <= 75)
			{
				*selectedMusic = listMusic[*currentSearch];
			}
			// Ajout a la playlist
			else if (event.button.x >= 5 && event.button.x <= 30 && event.button.y >= 115 && event.button.y <= 135)
			{
				if (*currentNbMusicAddPlayList < 5)
				{
					listMusicAddPlayList[*currentAddIndex] = listMusic[1 + (5 * *currentPage)];
					*currentAddIndex = *currentAddIndex + 1;
					*currentNbMusicAddPlayList = *currentNbMusicAddPlayList + 1;
				}
			}
			else if (event.button.x >= 5 && event.button.x <= 30 && event.button.y >= 165 && event.button.y <= 185)
			{
				if (*currentNbMusicAddPlayList < 5)
				{
					listMusicAddPlayList[*currentAddIndex] = listMusic[2 + (5 * *currentPage)];
					*currentAddIndex = *currentAddIndex + 1;
					*currentNbMusicAddPlayList = *currentNbMusicAddPlayList + 1;
				}
			}
			else if (event.button.x >= 5 && event.button.x <= 30 && event.button.y >= 215 && event.button.y <= 235)
			{
				if (*currentNbMusicAddPlayList < 5)
				{
					listMusicAddPlayList[*currentAddIndex] = listMusic[3 + (5 * *currentPage)];
					*currentAddIndex = *currentAddIndex + 1;
					*currentNbMusicAddPlayList = *currentNbMusicAddPlayList + 1;
				}
			}
			else if (event.button.x >= 5 && event.button.x <= 30 && event.button.y >= 265 && event.button.y <= 285)
			{
				if (*currentNbMusicAddPlayList < 5)
				{
					listMusicAddPlayList[*currentAddIndex] = listMusic[4 + (5 * *currentPage)];
					*currentAddIndex = *currentAddIndex + 1;
					*currentNbMusicAddPlayList = *currentNbMusicAddPlayList + 1;
				}
			}
			else if (event.button.x >= 5 && event.button.x <= 30 && event.button.y >= 315 && event.button.y <= 335)
			{
				if (*currentNbMusicAddPlayList < 5)
				{
					listMusicAddPlayList[*currentAddIndex] = listMusic[5 + (5 * *currentPage)];
					*currentAddIndex = *currentAddIndex + 1;
					*currentNbMusicAddPlayList = *currentNbMusicAddPlayList + 1;
				}
			}
			else if (event.button.x >= 580 && event.button.x <= 640 && event.button.y >= 350 && event.button.y <= 380)
			{
				*currentAddIndex = 0;
				*currentNbMusicAddPlayList = 0;
				listMusicAddPlayList[0] = listMusic[0];
				listMusicAddPlayList[1] = listMusic[0];
				listMusicAddPlayList[2] = listMusic[0];
				listMusicAddPlayList[3] = listMusic[0];
				listMusicAddPlayList[4] = listMusic[0];
			}
			else if (event.button.x >= 520 && event.button.x <= 575 && event.button.y >= 350 && event.button.y <= 380)
			{
				*createPlayList = 1;
			}
			else if (event.button.x >= 295 && event.button.x <= 350 && event.button.y >= 55 && event.button.y <= 80)
			{
				*currentChamp = 2;
			}

		}

		break;
	}

}

int addEvent(int *continuer, Ecran *ecranCours, int *currentChamp, char retour[100], char ajout[2][46], Musique listMusic[], int * nbMusique, Musique *selectedMusic, int *playing, int *playList, int *playListSuivant) {

	SDL_Event event;
	char currentChar;
	int fin = 0;
	int i = 0;

	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		*continuer = 0;
		break;
	case SDL_MOUSEBUTTONUP:
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			if (event.button.x >= 20 && event.button.x <= 95 && event.button.y >= 60 && event.button.y <= 90)
			{
				*ecranCours = AJOUT;

			}
			else if (event.button.x >= 95 && event.button.x <= 170 && event.button.y >= 60 && event.button.y <= 90)
			{
				*ecranCours = PLAY;
			}
			else if (event.button.x >= 170 && event.button.x <= 245 && event.button.y >= 60 && event.button.y <= 90)
			{
				*ecranCours = LISTE;
			}
			else if (event.button.x >= 20 && event.button.x <= 50 && event.button.x >= 20 && event.button.y >= 410 && event.button.y <= 440)
			{
				if (strcmp(selectedMusic, " ") != 0)
				{
					*playing = 1;
				}

			}
			else if (event.button.x >= 70 && event.button.x <= 100 && event.button.x >= 20 && event.button.y >= 410 && event.button.y <= 440)
			{
				*playList = 0;

				*playing = 0;

				*playListSuivant = 0;

				Mix_PauseMusic();
			}
			else if (event.button.x >= 520 && event.button.x <= 570 && event.button.y >= 120 && event.button.y <= 145)
			{

				// Gobal Variables and declarations.
				OPENFILENAME ofn;
				// a another memory buffer to contain the file name
				char szFile[300];


				ZeroMemory(&ofn, sizeof(ofn));
				ofn.lStructSize = sizeof(ofn);
				ofn.hwndOwner = NULL;
				ofn.lpstrFile = szFile;
				ofn.lpstrFile[0] = '\0';
				ofn.nMaxFile = sizeof(szFile);
				ofn.nFilterIndex = 1;
				ofn.lpstrFileTitle = NULL;
				ofn.nMaxFileTitle = 0;
				ofn.lpstrInitialDir = NULL;
				ofn.Flags = OFN_NOCHANGEDIR;
				GetOpenFileName(&ofn);

				getPath(szFile, retour);

				getFileName(retour, ajout[0]);

			}
			else if (event.button.x >= 520 && event.button.x <= 570 && event.button.y >= 170 && event.button.y <= 220)
			{
				Musique music;

				strcpy(music.Nom, ajout[0]);
				strcpy(music.Path, retour);
				music.lenght = 600;

				listMusic[*nbMusique] = music;

				strcpy(ajout[0], "Nom");
				clearRetour(retour);

				*nbMusique = *nbMusique + 1;
			}
			else if (event.button.x >= 20 && event.button.x <= 75 && event.button.y >= 120 && event.button.y <= 170)
			{
				*currentChamp = 0;
			}
			else if (event.button.x >= 20 && event.button.x <= 75 && event.button.y >= 170 && event.button.y <= 220)
			{
				*currentChamp = 1;
			}
		}
		break;
	case SDL_KEYUP:
		currentChar = getLetter(event.key.keysym.sym);
		if (currentChar != SDLK_BACKSPACE)
		{
			while (!fin)
			{
				if (ajout[*currentChamp][i] == '\0')
				{
					fin = 1;
				}
				i++;
			}
			ajout[*currentChamp][i - 1] = currentChar;
		}
		else
		{
			while (!fin)
			{
				if (ajout[*currentChamp][i] == '\0')
				{
					fin = 1;
				}
				i++;
			}
			ajout[*currentChamp][i - 2] = '\0';
		}
		fin = 0;
		break;
	}


}

int listEvent(int *continuer, Ecran *ecranCours, int *playing, int *playList, int *playListSuivant, int *currentMusicNumber, List listPlayList[], List *currentPlayList, int *currentPage, int maxPage) {

	SDL_Event event;
	char currentChar;
	int fin = 0;
	int i = 0;

	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		*continuer = 0;
		break;
	case SDL_MOUSEBUTTONUP:
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			if (event.button.x >= 20 && event.button.x <= 95 && event.button.y >= 60 && event.button.y <= 90)
			{
				*ecranCours = AJOUT;
			}
			else if (event.button.x >= 95 && event.button.x <= 170 && event.button.y >= 60 && event.button.y <= 90)
			{
				*ecranCours = PLAY;
			}
			else if (event.button.x >= 170 && event.button.x <= 245 && event.button.y >= 60 && event.button.y <= 90)
			{
				*ecranCours = LISTE;
			}
			else if (event.button.x >= 20 && event.button.x <= 200 && event.button.x >= 20 && event.button.y >= 120 && event.button.y <= 170)
			{
				*currentPlayList = listPlayList[0];
			}
			else if (event.button.x >= 20 && event.button.x <= 200 && event.button.x >= 20 && event.button.y >= 170 && event.button.y <= 220)
			{
				*currentPlayList = listPlayList[1];
			}
			else if (event.button.x >= 20 && event.button.x <= 200 && event.button.x >= 20 && event.button.y >= 220 && event.button.y <= 270)
			{
				*currentPlayList = listPlayList[2];
			}
			else if (event.button.x >= 20 && event.button.x <= 200 && event.button.x >= 20 && event.button.y >= 270 && event.button.y <= 320)
			{
				*currentPlayList = listPlayList[3];
			}
			else if (event.button.x >= 20 && event.button.x <= 200 && event.button.x >= 20 && event.button.y >= 320 && event.button.y <= 370)
			{
				*currentPlayList = listPlayList[4];
			}
			else if (event.button.x >= 20 && event.button.x <= 50 && event.button.x >= 20 && event.button.y >= 410 && event.button.y <= 440)
			{
				*playList = 1;
				*playListSuivant = 1;
				*currentMusicNumber = 0;
			}
			else if (event.button.x >= 70 && event.button.x <= 100 && event.button.x >= 20 && event.button.y >= 410 && event.button.y <= 440)
			{
				*playList = 0;
				
				*playing = 0;

				*playListSuivant = 0;

				Mix_PauseMusic();
			}
			if (event.button.x >= 520 && event.button.x <= 535 && event.button.y >= 120 && event.button.y <= 145)
			{

				if (*currentPage > 0)
				{
					*currentPage = *currentPage - 1;
				}

			}
			else if (event.button.x >= 560 && event.button.x <= 575 && event.button.y >= 120 && event.button.y <= 145)
			{

				if (*currentPage < maxPage)
				{
					*currentPage = *currentPage + 1;
				}

			}
		}
		break;
	}


}

void clearRetour(char retour[300]) {
	for (int i = 0; i < 300; i++)
	{
		retour[i] = '\0';
	}
}

void supMusic(int nbMusic, int indexMusicToSup, Musique listMusic[]) {
	for (int i = indexMusicToSup; i < nbMusic; i++)
	{
		listMusic[i] = listMusic[i + 1];
	}
}