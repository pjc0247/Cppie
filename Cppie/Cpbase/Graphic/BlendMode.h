#pragma once

#include <SDL.h>

#define CPPIE_BLENDMODE_NONE	SDL_BLENDMODE_NONE
#define CPPIE_BLENDMODE_ADD		SDL_BLENDMODE_ADD
#define CPPIE_BLENDMODE_BLEND	SDL_BLENDMODE_BLEND
#define CPPIE_BLENDMODE_MOD		SDL_BLENDMODE_MOD

namespace Cppie{
	typedef SDL_BlendMode BlendMode;

};