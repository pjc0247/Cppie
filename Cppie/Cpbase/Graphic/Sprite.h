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
	public:
		Sprite();
		Sprite(const char *image, int wSlice=1,int hSlice=1);
		virtual ~Sprite();

		virtual int initialize(const char *image, int wSlice=1,int hSlice=1);
		virtual void dispose();
		
		void doStep();

		virtual void draw(int x,int y);
		void stretch(int x,int y,int w,int h);
	};
};