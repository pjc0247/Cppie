#pragma once

#include <stdio.h>
#include <SDL.h>

#include "../System/Core.h"

#include "Graphic.h"

namespace Cppie{
	Graphic::Graphic(int w,int h,const char *rdriver){
		color = Color::White;
		blend = NONE;

		initialize(w,h, rdriver);
	}
	Graphic::~Graphic(){
	}

	int Graphic::initialize(int w,int h,const char *rdriver){
		window = SDL_CreateWindow("chocopie",
						SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
						w,h, 0);
		if(window == NULL){
			logger->error("Failed to create game window");

			return -2;
		}

		
		int n = SDL_GetNumRenderDrivers();
		for(int i=0;i<n;i++){
			SDL_RendererInfo info;

			SDL_GetRenderDriverInfo(i, &info);
			if(!strcmp(info.name, rdriver)){
				renderer = SDL_CreateRenderer(window, i,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			}
		}
		if(renderer == NULL){
			logger->error("Open GL not supported");

			return -3;
		}

		logger->output("Graphic system initialized");
	}
	void Graphic::dispose(){
	}

	void Graphic::line(int x1,int y1,int x2,int y2){
		SDL_SetRenderDrawColor(renderer,color.r, color.g, color.b, color.a);
		SDL_SetRenderDrawBlendMode(renderer, blend);

		SDL_RenderDrawLine(renderer, x1,y1,x2,y2);
	}
	void Graphic::rect(int x,int y,int w,int h){
		SDL_Rect rect = {x,y,w,h};

		SDL_SetRenderDrawColor(renderer,color.r, color.g, color.b, color.a);
		SDL_SetRenderDrawBlendMode(renderer, blend);

		SDL_RenderDrawRect(renderer, &rect);
	}
	void Graphic::fill(int x,int y,int w,int h){
		SDL_Rect rect = {x,y,w,h};

		SDL_SetRenderDrawColor(renderer,color.r, color.g, color.b, color.a);
		SDL_SetRenderDrawBlendMode(renderer, blend);

		SDL_RenderDrawRect(renderer, &rect);
	}

	void Graphic::setSize(Rect size){
		SDL_SetWindowSize(window, size.w,size.h);
	}
	Rect Graphic::getSize(){
		Rect rect;
		SDL_GetWindowSize(window, &rect.w,&rect.h);
		return rect;
	}

	void Graphic::setTitle(const char *title){
		//SDL_SetWindowTitle(window, title);
		strcpy_s(this->title,256, title);
	}
	const char *Graphic::getTitle(){
		//return SDL_GetWindowTitle(window);
		return title;
	}
};
