#pragma once

#include <SDL.h>
#include <sdl_gdiplus.h>

#include "../System/Object.h"

#include "Texture.h"

namespace Cppie{
	class Sprite : public Texture{
	public:
		int wSlice, hSlice;

		int step;

		float angle;
		SDL_RendererFlip flip;
		SDL_Point origin;
	public:
		Sprite();
		Sprite(const char *image, int wSlice=1,int hSlice=1);
		virtual ~Sprite();

		virtual int initialize(const char *image, int wSlice,int hSlice);
		virtual void dispose();
		
		void doStep();

		virtual void draw(int x,int y);
		void stretch(int x,int y,int w,int h);
	};
};