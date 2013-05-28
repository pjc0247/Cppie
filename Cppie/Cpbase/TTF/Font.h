#pragma once 

#include <SDL_TTF.h>

#include "../System/Object.h"
#include "../System/Core.h"

#include "../Data/Size.h"

#include "han2unicode.h"

namespace Cppie{
	class Font : public DrawableObject{
	protected:
		TTF_Font *font;
	public:
		Font(const char *font,int size=20){
			initialize(font, size);
		}
		~Font(){
			dispose();
		}

		virtual int initialize(const char *font,int size){
			
			this->font = TTF_OpenFont(font, size);
			printf("%s\n", TTF_GetError());
			printf("f%x", this->font);
			return 0;
		}
		virtual void dispose(){
			TTF_CloseFont(font);
		}

		Size querySize(char *msg){
			Uint16 string_han[256];
			Size size;

			han2unicode(msg, string_han);

			TTF_SizeText(font, msg, &size.w, &size.h);

			return size;
		}
		void draw(int x,int y,const char *msg){
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

			SDL_RenderCopy(renderer, texture, &src, &dst);

			SDL_DestroyTexture(texture);
			SDL_FreeSurface(text);
		}
	};
};