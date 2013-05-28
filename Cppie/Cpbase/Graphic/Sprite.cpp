#include "Sprite.h"

#include <stdio.h>

#include "../System/Core.h"

#include "Sprite.h"

namespace Cppie{

	Sprite::Sprite(){
	}
	Sprite::Sprite(const char *image, int wSlice,int hSlice){
		initialize(image, wSlice, hSlice);
	}
	Sprite::~Sprite(){
		dispose();
	}

	int Sprite::initialize(const char *image, int wSlice,int hSlice){
		SDL_Surface *surface;
		char new_path[256];

		sprintf_s(new_path, "resource\\%s", image);
		surface = IMG_Load(new_path);

		if(surface != nullptr){
			texture = SDL_CreateTextureFromSurface(renderer, surface);
			SDL_FreeSurface(surface);
		}
		else{
			logger->error("Failed to load image - %s", image);
		}
		if(texture != nullptr){
			SDL_QueryTexture(texture, NULL, NULL, &w, &h);

			w /= wSlice;
			h /= hSlice;
		}
		else{
			logger->error("Failed to create texture - %s", image);
		}
		this->wSlice = wSlice;
		this->hSlice = hSlice;

		step = 0;
		angle = 0;
		alpha =  255;

		flip = SDL_FLIP_NONE;

		origin.x = w/2;
		origin.y = h/2;

		return 0;
	}
	void Sprite::dispose(){
		if(texture != nullptr){
			SDL_DestroyTexture(texture);
			texture = nullptr;
		}
	}

	void Sprite::draw(int x,int y){
		stretch(x,y,w,h);
	}
	void Sprite::stretch(int x,int y,int w,int h){
		SDL_Rect src;
		SDL_Rect dst;

		src.x = this->w * (step % wSlice);
		src.y = this->h * (step / wSlice);
		src.w = this->w, src.h = this->h;

		dst.x = x, dst.y = y;
		dst.w = w, dst.h = h;

		origin.x = src.x + w/2;
		origin.y = src.y + h/2;

		SDL_SetTextureColorMod(texture, color.r, color.g, color.b);
		SDL_SetTextureAlphaMod(texture, alpha);
		SDL_RenderCopyEx(renderer, texture, &src, &dst, angle,  &origin, flip);
	}

};