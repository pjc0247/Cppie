#pragma once 

#include "../System/Core.h"
#include "../Data/Size.h"

#include "Font.h"

#include "han2unicode.h"

namespace Cppie{

	Font::Font(){
	}
	Font::Font(const char *font,int size){
		initialize(font, size);
	}
	Font::~Font(){
		dispose();
	}

	int Font::initialize(const char *font,int size){

		this->font = TTF_OpenFont(font, size);
		
		return 0;
	}
	void Font::dispose(){
		TTF_CloseFont(font);
	}

	Size Font::querySize(char *msg){
		Uint16 string_han[256];
		Size size;

		han2unicode(msg, string_han);

		TTF_SizeText(font, msg, &size.w, &size.h);

		return size;
	}

	Texture *Font::render(const char *msg){
		SDL_Surface *text;
		Uint16 string_han[256];
		SDL_Color color;

		Texture *finalTexture;

		han2unicode(const_cast<char*>(msg), string_han);

		color.r = this->color.r;
		color.g = this->color.g;
		color.b = this->color.b;
		text = TTF_RenderUNICODE_Blended(font, string_han, color);

		finalTexture = new Texture(text);
		finalTexture->alpha = alpha;
		finalTexture->blend = blend;

		SDL_FreeSurface(text);

		return finalTexture;
	}
	void Font::draw(int x,int y,const char *msg){
		SDL_Surface *text;
		SDL_Texture *texture;
		Uint16 string_han[256];
		SDL_Color color;

		han2unicode(const_cast<char*>(msg), string_han);

		color.r = this->color.r;
		color.g = this->color.g;
		color.b = this->color.b;
		text = TTF_RenderUNICODE_Blended(font, string_han, color);

		texture = SDL_CreateTextureFromSurface(renderer, text);

		SDL_Rect src = {0,0, text->w, text->h};
		SDL_Rect dst = {x,y, text->w, text->h};

		SDL_SetTextureBlendMode(texture, blend);
		SDL_SetTextureAlphaMod(texture, alpha);

		SDL_RenderCopy(renderer, texture, &src, &dst);

		SDL_DestroyTexture(texture);
		SDL_FreeSurface(text);
	}
};