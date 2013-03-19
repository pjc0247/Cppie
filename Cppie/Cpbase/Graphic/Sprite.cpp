#include "Sprite.h"

#include <stdio.h>

#include "Sprite.h"

namespace Cppie{

	Sprite::Sprite(const char *image, int wSlice,int hSlice){
		SDL_Surface *surface;
		char new_path[256];

		sprintf_s(new_path, "resource\\%s", image);
		surface = IMG_Load(new_path);

		if(surface != nullptr){
			texture = SDL_CreateTextureFromSurface(renderer, surface);
			SDL_FreeSurface(surface);
		}
		if(texture != nullptr){
			SDL_QueryTexture(texture, NULL, NULL, &w, &h);

			w /= wSlice;
			h /= hSlice;
		}

		step = 0;
		angle = 0;

		blend = BLEND;
		flip = SDL_FLIP_NONE;

		origin.x = w/2;
		origin.y = h/2;

		color = Color::White;
	}
	Sprite::~Sprite(){
		dispose();
	}

	int Sprite::initialize(){
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

		src.x = w * (step % wSlice);
		src.y = h * (step / wSlice);
		src.w = w, src.h = h;

		dst.x = x, dst.y = y;
		dst.w = w, dst.h = h;
		
		SDL_SetTextureColorMod(texture, color.r, color.g, color.b);
		SDL_SetTextureAlphaMod(texture, color.a);
		SDL_RenderCopyEx(renderer, texture, &src, &dst, angle,  &origin, flip);
	}

};