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
		texture = new Texture(image);

		this->wSlice = wSlice;
		this->hSlice = hSlice;

		this->w = texture->w / wSlice;
		this->h = texture->h / hSlice;

		step = 0;
		angle = 0;
		alpha =  255;

		flip = SDL_FLIP_NONE;

		origin.x = w/2;
		origin.y = h/2;

		logger->output("loaded - %s, %x", image, this);

		return 0;
	}
	void Sprite::dispose(){
		if(texture != nullptr){
			texture->dispose();
			texture = nullptr;
		}
	}

	void Sprite::doStep(){
		step++;
		if(step >= wSlice * hSlice){
			step = 0;
		}
	}

	void Sprite::draw(int x,int y){
		texture->alpha = alpha;
		texture->angle = angle;
		texture->color = color;
		texture->blend = blend;
		texture->flip = flip;

		texture->draw(x,y);
	}
	void Sprite::stretch(int x,int y,int w,int h){
		texture->alpha = alpha;
		texture->angle = angle;
		texture->color = color;
		texture->blend = blend;
		texture->flip = flip;

		texture->stretch(x,y,w,h);
	}
};