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
		Texture::initialize(image);

		this->wSlice = wSlice;
		this->hSlice = hSlice;

		this->w = w / wSlice;
		this->h = h / hSlice;

		step = 0;
		angle = 0;
		alpha =  255;

		flip = SDL_FLIP_NONE;

		origin.x = w/2;
		origin.y = h/2;

		return 0;
	}
	void Sprite::dispose(){
		Texture::dispose();
	}

	void Sprite::doStep(){
		step++;
		printf("%d \n", step);
		if(step >= wSlice * hSlice){
			step = 0;
		}
	}

	void Sprite::draw(int x,int y){
		Rect srcRect;
		srcRect.set(
			step % wSlice * w,
			step / wSlice * h,
			w,h);
		Texture::draw(x,y,
			srcRect.x,srcRect.y,
			srcRect.w,srcRect.h);
	}
	void Sprite::stretch(int x,int y,int w,int h){
		Rect srcRect;
		srcRect.set(
			step % wSlice * w,
			step / wSlice * h,
			w,h);
		Texture::stretch(x,y,w,h,
			srcRect.x,srcRect.y,
			srcRect.w,srcRect.h);
	}
};