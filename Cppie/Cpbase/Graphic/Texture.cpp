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
	Texture::Texture(SDL_Surface *surface,int access){
		initializeWithSurface(surface, access);
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

		flip = CPPIE_FLIP_NONE;
		angle = 0;
		alpha = 255;
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
		alpha = 255;
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
		
		flip = CPPIE_FLIP_NONE;
		angle = 0;
		alpha = 255;
		origin.x = w/2;
		origin.y = h/2;

		return 0;
	}
	int Texture::initializeWithSurface(SDL_Surface *surface, int access){
		if(surface == nullptr){
			logger->error("Invalid surface - %x", surface);

			return -1;
		}

		if(access == CPPIE_TEXTUREACCESS_STATIC){
			texture = SDL_CreateTextureFromSurface(renderer, surface);

			if(texture == nullptr){
				logger->error("Failed to create texture - %x, %d", surface, access);

				return -3;
			}
		}
		else if(access == CPPIE_TEXTUREACCESS_STREAMING){
			void *pixels = nullptr;
			int pitch;

			unsigned int format;

			int pixelBufferSize;

			bool needAlphaChannel;
			SDL_RendererInfo rendererInfo;

			if (surface->format->Amask || SDL_GetColorKey(surface, NULL) == 0)
				needAlphaChannel = true;
			else
				needAlphaChannel = false;

			SDL_GetRendererInfo(renderer, &rendererInfo);
			format = rendererInfo.texture_formats[0];
			for (int i = 0; i < rendererInfo.num_texture_formats; ++i) {
				if (!SDL_ISPIXELFORMAT_FOURCC(rendererInfo.texture_formats[i]) &&
					SDL_ISPIXELFORMAT_ALPHA(rendererInfo.texture_formats[i]) == needAlphaChannel) {
						format = rendererInfo.texture_formats[i];
						break;
				}
			}

			texture = SDL_CreateTexture(renderer, format,
				SDL_TEXTUREACCESS_STREAMING, surface->w, surface->h);

			printf("f %d %d\n", SDL_PIXELFORMAT_ARGB8888, format);

			if(texture == nullptr){
				logger->error("Failed to create texture - %x, %d", surface, access);

				return -3;
			}

			pixelBufferSize = surface->w * surface->h * surface->format->BytesPerPixel;
			
			if(SDL_LockTexture(texture, NULL, (void**)&pixels, &pitch) != 0){
				logger->error("Failed to access pixel buffer - %x", this);

				return -4;
			}
			memcpy(pixels, surface->pixels, pixelBufferSize);
			SDL_UnlockTexture(texture);
		}
		else if(access == CPPIE_TEXTUREACCESS_TARGET){
			texture = SDL_CreateTexture(renderer, surface->format->format,
				SDL_TEXTUREACCESS_TARGET, surface->w, surface->h);

			if(texture == nullptr){
				logger->error("Failed to create texture - %x, %d", surface, access);

				return -3;
			}

			// todo
			//
			//
		}
		else{
			logger->error("Wrong access type - %d", access);

			return -2;
		}

		SDL_BlendMode surfaceBlendMode;
		SDL_GetSurfaceBlendMode(surface, &surfaceBlendMode);

		blend = surfaceBlendMode;

		w = surface->w;
		h = surface->h;

		flip = CPPIE_FLIP_NONE;
		angle = 0;
		alpha = 255;
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

		src.x = 0;
		src.y = 0;
		src.w = this->w, src.h = this->h;

		dst.x = x, dst.y = y;
		dst.w = this->w, dst.h = this->h;

		pt.x = origin.x;
		pt.y = origin.y;

		SDL_SetTextureColorMod(texture,
				color.r, color.g, color.b);
		SDL_SetTextureBlendMode(texture, blend);
		SDL_SetTextureAlphaMod(texture, alpha);

		SDL_RenderCopyEx(renderer, texture, &src, &dst,
						angle, &pt, flip);
	}
	void Texture::draw(int x,int y,int srcX,int srcY,int srcW,int srcH){
		SDL_Rect src;
		SDL_Rect dst;
		SDL_Point pt;

		src.x = srcX;
		src.y = srcY;
		src.w = srcW;
		src.h = srcH;

		dst.x = x, dst.y = y;
		dst.w = srcW, dst.h = srcH;

		pt.x = origin.x;
		pt.y = origin.y;

		SDL_SetTextureColorMod(texture,
				color.r, color.g, color.b);
		SDL_SetTextureBlendMode(texture, blend);
		SDL_SetTextureAlphaMod(texture, alpha);

		SDL_RenderCopyEx(renderer, texture, &src, &dst,
						angle, &pt, flip);
	}
	void Texture::stretch(int x,int y,int w,int h){
		SDL_Rect src;
		SDL_Rect dst;
		SDL_Point pt;

		src.x = 0;
		src.y = 0;
		src.w = this->w, src.h = this->h;

		dst.x = x, dst.y = y;
		dst.w = w, dst.h = h;

		pt.x = origin.x;
		pt.y = origin.y;

		SDL_SetTextureColorMod(texture,
				color.r, color.g, color.b);
		SDL_SetTextureBlendMode(texture, blend);
		SDL_SetTextureAlphaMod(texture, alpha);

		SDL_RenderCopyEx(renderer, texture, &src, &dst,
						angle, &pt, flip);
	}
	void Texture::stretch(int x,int y,int w,int h,int srcX,int srcY,int srcW,int srcH){
		SDL_Rect src;
		SDL_Rect dst;
		SDL_Point pt;

		src.x = srcX;
		src.y = srcY;
		src.w = srcW;
		src.h = srcH;

		dst.x = x, dst.y = y;
		dst.w = w, dst.h = h;

		pt.x = origin.x;
		pt.y = origin.y;

		SDL_SetTextureColorMod(texture,
				color.r, color.g, color.b);
		SDL_SetTextureBlendMode(texture, blend);
		SDL_SetTextureAlphaMod(texture, alpha);

		SDL_RenderCopyEx(renderer, texture, &src, &dst,
						angle, &pt, flip);
	}

};