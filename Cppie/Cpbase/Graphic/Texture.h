#pragma once

#include <SDL.h>
#include <sdl_gdiplus.h>

#include "../System/Object.h"
#include "../Data/Size.h"
#include "../Data/Point.h"

namespace Cppie{
	class Texture : public DrawableObject{
	protected:
		SDL_Texture *texture;

	public:
		int w,h;
		float angle;
		Point origin;
		SDL_RendererFlip flip;

	public:
		Texture();
		Texture(int w,int h);
		Texture(Size size);
		Texture(const char *image);
		Texture(SDL_Texture *texture);
		virtual ~Texture();

		virtual int initialize(const char *image);
		virtual int initializeWithImage(const char *image);
		virtual int initializeWithSize(Size size);
		virtual int initializeWithTexture(SDL_Texture *texture);
		virtual void dispose();
		
		virtual void draw(int x,int y);
		virtual void draw(int x,int y, int srcX,int srcY,int srcW,int srcH);
		void stretch(int x,int y,int w,int h);
		void stretch(int x,int y,int w,int h,int srcX,int srcY,int srcW,int srcH);
	};
};