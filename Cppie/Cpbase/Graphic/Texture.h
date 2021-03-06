#pragma once

#include <SDL.h>
#include <sdl_gdiplus.h>

#include "../Data/Size.h"
#include "../Data/Point.h"

#include "DrawableObject.h"
#include "BlendMode.h"
#include "Flip.h"

#define CPPIE_TEXTUREACCESS_STATIC		1
#define CPPIE_TEXTUREACCESS_STREAMING	2
#define CPPIE_TEXTUREACCESS_TARGET		3

namespace Cppie{
	class Texture : public DrawableObject{
	public:
		int w,h;
		float angle;
		Point origin;
		Flip flip;

		SDL_Texture *texture;

	public:
		Texture();
		Texture(int w,int h);
		Texture(Size size);
		Texture(const char *image);
		Texture(SDL_Texture *texture);
		Texture(SDL_Surface *texture,int access = CPPIE_TEXTUREACCESS_STATIC);
		virtual ~Texture();

		virtual int initialize(const char *image);
		virtual int initializeWithImage(const char *image);
		virtual int initializeWithSize(Size size);
		virtual int initializeWithTexture(SDL_Texture *texture);
		virtual int initializeWithSurface(SDL_Surface *surface,int access = CPPIE_TEXTUREACCESS_STATIC);
		virtual void dispose();
		
		virtual void draw(int x,int y);
		virtual void draw(int x,int y, int srcX,int srcY,int srcW,int srcH);
		void stretch(int x,int y,int w,int h);
		void stretch(int x,int y,int w,int h,int srcX,int srcY,int srcW,int srcH);
	};
};