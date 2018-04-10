#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include <string.h>
#include <windows.h>
#include <commdlg.h>

#include "IHM.h"
#include "Event.h"
#include "Calcul.h"


int main(int argc, char *argv[])
{

	// Variables systèmes SDL
	HWND windowHandle = GetConsoleWindow();
	ShowWindow(windowHandle, SW_HIDE);
	SDL_Surface *ecran = NULL;
	SDL_Surface	*texte = NULL, *header = NULL, *footer = NULL, *chargement = NULL, *right = NULL;
	SDL_Rect position;
	TTF_Font *police = NULL;
	SDL_Color couleurBlanc = { 255, 255, 255 };
	SDL_Color couleurNoire = { 0, 0, 0 };
	Mix_Music *musique = NULL;
	int continuer = 1;

	
	// Compteur de temps
	Uint32 temps;

	char *buffer;
	buffer = malloc(20 * sizeof(char));


	char *buffer2;
	buffer2 = malloc(20 * sizeof(char));


	char *buffer3;
	buffer3 = malloc(20 * sizeof(char));


	//Création des menus
	char musicMenu[100][9] = { "Ajout", "PlayList", "Musique"};
	char ajout[2][46] = { "Ajout", "Musique" };
	char retour[300] = "";



	//Liste des musiques

	Musique* listMusic;
	listMusic = malloc(50 * sizeof(Musique));

	Musique* listMusicAddPlayList;
	listMusicAddPlayList = malloc(50 * sizeof(Musique));


	Musique music1;
	Musique music2;
	Musique music3;
	Musique music4;

	strcpy(music1.Nom, " ");
	strcpy(music2.Nom, "oldelaf");
	strcpy(music3.Nom, "piano");
	strcpy(music4.Nom, "ella");

	strcpy(music1.Path, "music\\test.mp3");
	strcpy(music2.Path, "music\\oldelaf.mp3");
	strcpy(music3.Path, "music\\piano.mp3");
	strcpy(music4.Path, "music\\ella.mp3");

	music1.lenght = 10;
	music2.lenght = 10;
	music3.lenght = 10;
	music4.lenght = 10;

	listMusic[0] = music1;
	listMusic[1] = music2;
	listMusic[2] = music3;
	listMusic[3] = music4;

	int musicNumber = 4;


	List* listPlayList;
	listPlayList = malloc(50 * sizeof(List));

	List PlayList1;

	PlayList1.PlayList[0] = music2;
	PlayList1.PlayList[1] = music3;
	PlayList1.PlayList[2] = music4;

	strcpy(PlayList1.Nom, "Playlist 1");


	PlayList1.musicNumber = 3;

	List PlayList2;

	PlayList2.PlayList[0] = music3;
	PlayList2.PlayList[1] = music3;
	PlayList2.PlayList[2] = music4;

	strcpy(PlayList2.Nom, "Playlist 2");

	PlayList2.musicNumber = 3;


	listPlayList[0] = PlayList1;
	listPlayList[1] = PlayList2;

	List currentPlayList;

	currentPlayList = listPlayList[1];
	



	int playList = 0;
	int playListSuivant = 0;
	int playing = 0;

	int currentMusicNumber = 0;


	Ecran ecranCours = LISTE;
	int currentChamp = 1;
	Musique		selectedMusic = listMusic[0];
	Musique		currentMusic = listMusic[0];
	Uint32		currentStart = SDL_GetTicks() / 1000;
	int currentAddIndex = 0;
	int currentNbMusicAddPlayList = 0;
	int currentSearch = 0;
	int currentNbPlaylist = 2;
	int createPlayList = 0;

	//Calcul page
	int currentPage = 0;
	int currentPagePlayList = 0;
	int maxpage = 1;
	int maxpagePlayList = 1;




	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();

	ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Lecteur de musique", NULL);
	



	while (continuer)
	{

		maxpage = CalculMaxPage(musicNumber);
		maxpagePlayList = CalculMaxPage(currentNbPlaylist);

		temps = SDL_GetTicks() / 1000;
		itoa(temps, buffer, 10);

		police = TTF_OpenFont("Police.ttf", 15);
		header = SDL_LoadBMP("src\\Header.bmp");
		footer = SDL_LoadBMP("src\\Footer.bmp");
		right = SDL_CreateRGBSurface(SDL_HWSURFACE, 150, 480, 32, 0, 0, 0, 0);
		SDL_FillRect(right, NULL, SDL_MapRGB(ecran->format, 77, 79, 83));
		
		if (playList == 1 && playListSuivant == 1)
		{

			selectedMusic = currentPlayList.PlayList[currentMusicNumber];

			currentStart = SDL_GetTicks() / 1000;

			playing = 1;

			playListSuivant = 0;
		}
		
		if (playing == 1 && strcmp(currentMusic.Path,selectedMusic.Path) != 0)
		{
			Mix_PauseMusic();

			playMusic(musique, selectedMusic);

			currentMusic = selectedMusic;

			currentStart = SDL_GetTicks() / 1000;
		}

		if (createPlayList == 1)
		{
			List PlayList;

			PlayList.PlayList[0] = listMusicAddPlayList[0];
			PlayList.PlayList[1] = listMusicAddPlayList[1];
			PlayList.PlayList[2] = listMusicAddPlayList[2];
			PlayList.PlayList[3] = listMusicAddPlayList[3];
			PlayList.PlayList[4] = listMusicAddPlayList[4];

			PlayList.musicNumber = currentNbMusicAddPlayList;


			strcpy(PlayList.Nom, listMusicAddPlayList[0].Nom);

			listPlayList[currentNbPlaylist] = PlayList;

			createPlayList = 0;
			currentNbPlaylist++;

			currentAddIndex = 0;
			currentNbMusicAddPlayList = 0;
			listMusicAddPlayList[0] = listMusic[0];
			listMusicAddPlayList[1] = listMusic[0];
			listMusicAddPlayList[2] = listMusic[0];
			listMusicAddPlayList[3] = listMusic[0];
			listMusicAddPlayList[4] = listMusic[0];
		}

		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 80, 82, 87));
		
		position.x = 500;
		position.y = 0;
		SDL_BlitSurface(right, NULL, ecran, &position);

		position.x = 0;
		position.y = 0;
		SDL_BlitSurface(header, NULL, ecran, &position);

		position.x = 0;
		position.y = 400;
		SDL_BlitSurface(footer, NULL, ecran, &position); 

		texte = TTF_RenderText_Blended(police, buffer, couleurBlanc);
		position.x = 20;
		position.y = 10;
		SDL_BlitSurface(texte, NULL, ecran, &position); 
		SDL_FreeSurface(texte);


		texte = TTF_RenderText_Blended(police, &selectedMusic.Nom, couleurBlanc);
		position.x = 150;
		position.y = 415;
		SDL_BlitSurface(texte, NULL, ecran, &position);
		SDL_FreeSurface(texte);

		if (playList == 1)
		{
			texte = TTF_RenderText_Blended(police, currentPlayList.Nom, couleurBlanc);
			position.x = 520;
			position.y = 415;
			SDL_BlitSurface(texte, NULL, ecran, &position);
			SDL_FreeSurface(texte);

			texte = TTF_RenderText_Blended(police, "PlayList :", couleurBlanc);
			position.x = 400;
			position.y = 415;
			SDL_BlitSurface(texte, NULL, ecran, &position);
			SDL_FreeSurface(texte);
		}


		drawMenu(musicMenu, ecran);


		if (ecranCours == AJOUT)
		{


			texte = TTF_RenderText_Blended(police, retour, couleurBlanc);
			position.x = 20;
			position.y = 220;
			SDL_BlitSurface(texte, NULL, ecran, &position);
			SDL_FreeSurface(texte);

			texte = TTF_RenderText_Blended(police, "path", couleurBlanc);
			position.x = 520;
			position.y = 120;
			SDL_BlitSurface(texte, NULL, ecran, &position);
			SDL_FreeSurface(texte);

			texte = TTF_RenderText_Blended(police, "valider", couleurBlanc);
			position.x = 520;
			position.y = 170;
			SDL_BlitSurface(texte, NULL, ecran, &position);
			SDL_FreeSurface(texte);
		}
		else if (ecranCours == LISTE)
		{
			texte = TTF_RenderText_Blended(police, "<< ", couleurBlanc);
			position.x = 520;
			position.y = 120;
			SDL_BlitSurface(texte, NULL, ecran, &position);
			SDL_FreeSurface(texte);

			itoa(currentPage + 1, buffer2, 10);

			texte = TTF_RenderText_Blended(police, buffer2, couleurBlanc);
			position.x = 540;
			position.y = 120;
			SDL_BlitSurface(texte, NULL, ecran, &position);
			SDL_FreeSurface(texte);

			itoa(maxpage + 1, buffer2, 10);

			texte = TTF_RenderText_Blended(police, buffer2, couleurBlanc);
			position.x = 550;
			position.y = 120;
			SDL_BlitSurface(texte, NULL, ecran, &position);
			SDL_FreeSurface(texte);

			texte = TTF_RenderText_Blended(police, " >>", couleurBlanc);
			position.x = 560;
			position.y = 120;
			SDL_BlitSurface(texte, NULL, ecran, &position);
			SDL_FreeSurface(texte);

			texte = TTF_RenderText_Blended(police, "Nouvelle Playlist:", couleurBlanc);
			position.x = 520;
			position.y = 170;
			SDL_BlitSurface(texte, NULL, ecran, &position);
			SDL_FreeSurface(texte);


			texte = TTF_RenderText_Blended(police, "Reset", couleurBlanc);
			position.x = 580;
			position.y = 350;
			SDL_BlitSurface(texte, NULL, ecran, &position);
			SDL_FreeSurface(texte);

			texte = TTF_RenderText_Blended(police, "Valider", couleurBlanc);
			position.x = 520;
			position.y = 350;
			SDL_BlitSurface(texte, NULL, ecran, &position);
			SDL_FreeSurface(texte);

			texte = TTF_RenderText_Blended(police, "Recherche :", couleurBlanc);
			position.x = 300;
			position.y = 60;
			SDL_BlitSurface(texte, NULL, ecran, &position);
			SDL_FreeSurface(texte);

			itoa(currentSearch, buffer3, 10);

			texte = TTF_RenderText_Blended(police, buffer3, couleurBlanc);
			position.x = 380;
			position.y = 60;
			SDL_BlitSurface(texte, NULL, ecran, &position);
			SDL_FreeSurface(texte);

			texte = TTF_RenderText_Blended(police, listMusic[currentSearch].Nom, couleurBlanc);
			position.x = 400;
			position.y = 60;
			SDL_BlitSurface(texte, NULL, ecran, &position);
			SDL_FreeSurface(texte);

			drawListMusic(listMusic, ecran, &musicNumber, &currentPage);

			drawListPlayList(listMusicAddPlayList, ecran, &musicNumber, &currentPage);

		}
		else
		{
			texte = TTF_RenderText_Blended(police, "<< ", couleurBlanc);
			position.x = 520;
			position.y = 120;
			SDL_BlitSurface(texte, NULL, ecran, &position);
			SDL_FreeSurface(texte);

			itoa(currentPagePlayList + 1, buffer2, 10);

			texte = TTF_RenderText_Blended(police, buffer2, couleurBlanc);
			position.x = 540;
			position.y = 120;
			SDL_BlitSurface(texte, NULL, ecran, &position);
			SDL_FreeSurface(texte);

			itoa(maxpagePlayList + 1, buffer2, 10);

			texte = TTF_RenderText_Blended(police, buffer2, couleurBlanc);
			position.x = 550;
			position.y = 120;
			SDL_BlitSurface(texte, NULL, ecran, &position);
			SDL_FreeSurface(texte);

			texte = TTF_RenderText_Blended(police, " >>", couleurBlanc);
			position.x = 560;
			position.y = 120;
			SDL_BlitSurface(texte, NULL, ecran, &position);
			SDL_FreeSurface(texte);



			if (playList == 0)
			{
				texte = TTF_RenderText_Blended(police, currentPlayList.Nom, couleurBlanc);
				position.x = 520;
				position.y = 415;
				SDL_BlitSurface(texte, NULL, ecran, &position);
				SDL_FreeSurface(texte);

				texte = TTF_RenderText_Blended(police, "PlayList sélectionné :", couleurBlanc);
				position.x = 375;
				position.y = 415;
				SDL_BlitSurface(texte, NULL, ecran, &position);
				SDL_FreeSurface(texte);
			}

			drawAllListPlayList(listPlayList, ecran, &musicNumber, &currentPagePlayList);

		}


		if (playing == 1 && (1.0 * (temps + 1 - currentStart) / (currentMusic.lenght) * 100 <= 100))
		{
			chargement = SDL_CreateRGBSurface(SDL_HWSURFACE, 1.0 * (temps-currentStart) / (currentMusic.lenght) * 100 * 5, 10, 32, 0, 0, 0, 0);
			SDL_FillRect(chargement, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
			position.x = 20;
			position.y = 460;
			SDL_BlitSurface(chargement, NULL, ecran, &position);
			SDL_FreeSurface(chargement);

		}
		else if (playing == 1 && (1.0 * (temps + 1 - currentStart) / (selectedMusic.lenght) * 100 >= 100))
		{
			chargement = SDL_CreateRGBSurface(SDL_HWSURFACE, 500, 10, 32, 0, 0, 0, 0);
			SDL_FillRect(chargement, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
			position.x = 20;
			position.y = 460;
			SDL_BlitSurface(chargement, NULL, ecran, &position);

			if (currentPlayList.musicNumber == currentMusicNumber + 1)
			{
				playList = 0;

				playing = 0;

				playListSuivant = 0;

				currentMusicNumber = 0;

				Mix_PauseMusic();
			}
			else if (playList == 1)
			{
				playListSuivant = 1;
				currentMusicNumber++;
			}
			else {
				Mix_PauseMusic();
			}

			playing = 0;
		}




		if (ecranCours == AJOUT)
		{
			if (currentChamp == 1) {
				addEvent(&continuer, &ecranCours, &currentChamp, retour, ajout, listMusic, &musicNumber, &selectedMusic, &playing, &playList, &playListSuivant);
			}
			else
			{
				addEvent(&continuer, &ecranCours, &currentChamp, retour, ajout, listMusic, &musicNumber, &selectedMusic, &playing, &playList, &playListSuivant);
			}
		}
		else if (ecranCours == LISTE)
		{
			screenEvent(&continuer, &ecranCours, &selectedMusic, listMusic, &playing, &currentPage, maxpage, &playList, &playListSuivant, listMusicAddPlayList, &currentAddIndex, &currentNbMusicAddPlayList, &currentChamp, &currentSearch, &createPlayList, &musicNumber);
		}
		else
		{
			listEvent(&continuer, &ecranCours, &playing, &playList, &playListSuivant, &currentMusicNumber, listPlayList, &currentPlayList, &currentPagePlayList, maxpagePlayList);
		}



		TTF_CloseFont(police);
		SDL_FreeSurface(header);
		SDL_FreeSurface(right);
		SDL_FreeSurface(footer);
		SDL_Flip(ecran);
	}

	TTF_Quit();
	SDL_Quit();

	return EXIT_SUCCESS;
}



