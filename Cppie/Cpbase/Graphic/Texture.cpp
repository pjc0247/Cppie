#pragma once

#include "../System/Core.h"
#include "../Data/Make.h"

#include "Texture.h"

namespace Cppie{
	
	Texture::Texture(){
	}
	Texture::Texture(const char *image){
		initializeWithImage(image);
	}
	Texture::Texture(int w,int h){
		initializeWithSize(cpSize(w,h));
	}
	Texture::Texture(Size size){
		initializeWithSize(size);
	}
	Texture::Texture(SDL_Texture *texture){
		initializeWithTexture(texture);
	}
	Texture::~Texture(){
		dispose();
	}
	
	int Texture::initialize(const char *image){
		return initializeWithImage(image);
	}
	int Texture::initializeWithImage(const char *image){
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

			return -1;
		}
		if(texture != nullptr){
			SDL_QueryTexture(texture, NULL, NULL, &w, &h);
		}
		else{
			logger->error("Failed to create texture - %s", image);

			return -2;
		}

		flip = SDL_FLIP_NONE;
		angle = 0;
		origin.x = w/2;
		origin.y = h/2;
		
		logger->output("loaded - %s, %x", image, this);

		return 0;
	}
	int Texture::initializeWithSize(Size size){
		SDL_Texture *texture;

		texture = SDL_CreateTexture(renderer,
			SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_TARGET,
			size.w, size.h);

		if(texture == nullptr){
			logger->error("Failed to create texture - %x", this);
			return -1;
		}

		w = size.w;
		h = size.h;

		flip = SDL_FLIP_NONE;
		angle = 0;
		origin.x = w/2;
		origin.y = h/2;

		return 0;
	}
	int Texture::initializeWithTexture(SDL_Texture *texture){
		if(texture == nullptr){
			logger->error("Invalid texture - %x", texture);
			return -1;
		}

		this->texture = texture;
		
		SDL_QueryTexture(texture, NULL,NULL, &w,&h);

		flip = SDL_FLIP_NONE;
		angle = 0;
		origin.x = w/2;
		origin.y = h/2;

		return 0;
	}

	void Texture::dispose(){
		if(texture != nullptr){
			SDL_DestroyTexture(texture);
			texture = nullptr;
		}
	}

	void Texture::draw(int x,int y){
		SDL_Rect src;
		SDL_Rect dst;
		SDL_Point pt;

		applyColor(), applyBlendMode(), applyAlpha();

		src.x = 0;
		src.y = 0;
		src.w = this->w, src.h = this->h;

		dst.x = x, dst.y = y;
		dst.w = this->w, dst.h = this->h;

		pt.x = origin.x;
		pt.y = origin.y;

		SDL_RenderCopyEx(renderer, texture, &src, &dst,
						angle, &pt, flip);
	}
	void Texture::draw(int x,int y,int srcX,int srcY,int srcW,int srcH){
		SDL_Rect src;
		SDL_Rect dst;
		SDL_Point pt;

		applyColor(), applyBlendMode(), applyAlpha();

		src.x = srcX;
		src.y = srcY;
		src.w = srcW;
		src.h = srcH;

		dst.x = x, dst.y = y;
		dst.w = srcW, dst.h = srcH;

		pt.x = origin.x;
		pt.y = origin.y;

		SDL_RenderCopyEx(renderer, texture, &src, &dst,
						angle, &pt, flip);
	}
	void Texture::stretch(int x,int y,int w,int h){
		SDL_Rect src;
		SDL_Rect dst;
		SDL_Point pt;

		applyColor(), applyBlendMode(), applyAlpha();

		src.x = 0;
		src.y = 0;
		src.w = this->w, src.h = this->h;

		dst.x = x, dst.y = y;
		dst.w = w, dst.h = h;

		pt.x = origin.x;
		pt.y = origin.y;

		SDL_RenderCopyEx(renderer, texture, &src, &dst,
						angle, &pt, flip);
	}
	void Texture::stretch(int x,int y,int w,int h,int srcX,int srcY,int srcW,int srcH){
		SDL_Rect src;
		SDL_Rect dst;
		SDL_Point pt;

		applyColor(), applyBlendMode(), applyAlpha();

		src.x = srcX;
		src.y = srcY;
		src.w = srcW;
		src.h = srcH;

		dst.x = x, dst.y = y;
		dst.w = w, dst.h = h;

		pt.x = origin.x;
		pt.y = origin.y;

		SDL_RenderCopyEx(renderer, texture, &src, &dst,
						angle, &pt, flip);
	}

	void Texture::applyColor(){
		SDL_SetTextureColorMod(texture,
				color.r, color.g, color.b);
	}
	void Texture::applyBlendMode(){
		SDL_SetTextureBlendMode(texture, blend);
	}
	void Texture::applyAlpha(){
		SDL_SetTextureAlphaMod(texture, alpha);
	}
};