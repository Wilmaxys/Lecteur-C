#include"Add.h"

char getLetter(SDLKey key) {
	// magic numbers courtesy of SDL docs :)
	const int INTERNATIONAL_MASK = 0xFF80, UNICODE_MASK = 0x7F;

	int uni = key;

	if (uni == 0) // not translatable key (like up or down arrows)
	{
		// probably not useful as string input
		// we could optionally use this to get some value
		// for it: SDL_GetKeyName( key );
		return 0;
	}

	if ((uni & INTERNATIONAL_MASK) == 0)
	{
		if (SDL_GetModState() & KMOD_SHIFT)
		{
			return (char)(toupper(uni & UNICODE_MASK));
		}
		else
		{
			return (char)(uni & UNICODE_MASK);
		}
	}
	else // we have a funky international character. one we can't read :(
	{
		// we could do nothing, or we can just show some sign of input, like so:
		return '?';
	}
}

void getPath(char szFile[100], char retour[100]) {
	int continuer = 1;
	int i = 0;
	int x = 0;


	while (continuer)
	{

		if (*(szFile + i) != '\0')
		{
			retour[x] = szFile[i];
			x++;
		}
		else
		{
			if (*(szFile + i + 1) == '\0')
			{
				continuer = 0;
			}
		}


		i++;

	}
}

void getFileName(char szFile[100], char test[9]) {
	int continuer = 1;
	int i = 0;
	int x = 0;

	while (continuer)
	{

		if (*(szFile + i) == '\\')
		{
			x = i;
		}
		else
		{
			if (*(szFile + i) == '\0')
			{
				continuer = 0;
			}
		}


		i++;

	}

	continuer = 1;
	i = 0;
	x++;

	while (continuer)
	{

		if (*(szFile + i) != '.')
		{
			test[i] = szFile[x];
			i++;

		}
		else
		{
			continuer = 0;
		}


		x++;


	}

	continuer = 1;
}