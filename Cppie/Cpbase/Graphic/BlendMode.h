#pragma once

#include <SDL.h>

namespace Cppie{
	typedef SDL_BlendMode BlendMode;

	const BlendMode NONE = SDL_BLENDMODE_NONE;
	const BlendMode BLEND = SDL_BLENDMODE_BLEND;
	const BlendMode ADD = SDL_BLENDMODE_ADD;
	const BlendMode MOD = SDL_BLENDMODE_MOD;
};