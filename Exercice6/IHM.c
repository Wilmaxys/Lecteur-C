#include "IHM.h"

void drawMenu(char JOUR[100][9], SDL_Surface *ecran) {
	TTF_Font *police = NULL;
	SDL_Color couleurNoire = { 255, 255, 255 };
	SDL_Rect position;
	SDL_Surface	*texte = NULL;

	police = TTF_OpenFont("Police.ttf", 15);
	position.x = 20;
	position.y = 60;


	for (int i = 0; i < 3; i++)
	{
		texte = TTF_RenderText_Blended(police, *(JOUR + i), couleurNoire);
		SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte */
		position.x += 75;
		SDL_FreeSurface(texte);

	}

	TTF_CloseFont(police);


}

void drawAjout(char ajout[], SDL_Surface *ecran, SDL_Rect position) {
	TTF_Font *police = NULL;
	SDL_Color couleurNoire = { 255, 255, 255 };
	SDL_Surface	*texte = NULL;

	police = TTF_OpenFont("Police.ttf", 15);

	int i = 0;


	texte = TTF_RenderText_Blended(police, ajout, couleurNoire);
	//texte = TTF_RenderText_Blended(police, ajout[i], couleurNoire);
	SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte */
	SDL_FreeSurface(texte);


	TTF_CloseFont(police);


}


void drawListMusic(Musique listMusic[5], SDL_Surface *ecran, int *nbMusic, int *currentPage) {

	TTF_Font *police = NULL;
	SDL_Color couleurNoire = { 255, 255, 255 };
	SDL_Rect position;
	SDL_Rect position2;
	SDL_Rect position3;
	SDL_Surface	*texte = NULL;

	police = TTF_OpenFont("Police.ttf", 15);
	position.x = 40;
	position.y = 120;

	position2.x = 10;
	position2.y = 120;

	position3.x = 400;
	position3.y = 120;

	for (int i = 1; i < 6; i++)
	{

		texte = TTF_RenderText_Blended(police, listMusic[i + (5 * *currentPage)].Nom, couleurNoire);
		SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte */
		position.y += 50;
		SDL_FreeSurface(texte);

		if (i < *nbMusic - (*currentPage * 5))
		{
			texte = TTF_RenderText_Blended(police, "+", couleurNoire);
			SDL_BlitSurface(texte, NULL, ecran, &position2); /* Blit du texte */
			position2.y += 50;
			SDL_FreeSurface(texte);

			texte = TTF_RenderText_Blended(police, "Delete", couleurNoire);
			SDL_BlitSurface(texte, NULL, ecran, &position3); /* Blit du texte */
			position3.y += 50;
			SDL_FreeSurface(texte);
		}

	}

	TTF_CloseFont(police);

}

void drawListPlayList(Musique listMusic[5], SDL_Surface *ecran, int *nbMusic, int *currentPage) {

	TTF_Font *police = NULL;
	SDL_Color couleurNoire = { 255, 255, 255 };
	SDL_Rect position;
	SDL_Surface	*texte = NULL;

	police = TTF_OpenFont("Police.ttf", 15);
	position.x = 520;
	position.y = 200;

	for (int i = 0; i < 5; i++)
	{

		texte = TTF_RenderText_Blended(police, listMusic[i + (5 * *currentPage)].Nom, couleurNoire);
		SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte */
		position.y += 20;
		SDL_FreeSurface(texte);

	}

	TTF_CloseFont(police);

}

void drawAllListPlayList(List listPlayList[5], SDL_Surface *ecran, int *nbMusic, int *currentPage) {

	TTF_Font *police = NULL;
	SDL_Color couleurNoire = { 255, 255, 255 };
	SDL_Rect position;
	SDL_Surface	*texte = NULL;

	police = TTF_OpenFont("Police.ttf", 15);
	position.x = 20;
	position.y = 120;

	for (int i = 0; i < 5; i++)
	{

		texte = TTF_RenderText_Blended(police, listPlayList[i + (5 * *currentPage)].Nom, couleurNoire);
		SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte */
		position.y += 50;
		SDL_FreeSurface(texte);

	}

	TTF_CloseFont(police);

}