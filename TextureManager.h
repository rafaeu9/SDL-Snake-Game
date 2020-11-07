#pragma once

#include "Game.h"

class TextureManager
{
public:

	static SDL_Texture* LoadBMPTexture(const char* FileName, SDL_Rect* destRect = nullptr, bool Transparency = false);

	static SDL_Texture* LoadPNGTexture(const char* FileName, SDL_Rect* destRect = nullptr, bool Transparency = false);

	static void Draw(SDL_Texture* tex, SDL_Rect dest);

};

