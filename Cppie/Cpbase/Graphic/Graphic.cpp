#pragma once

#include <stdio.h>
#include <SDL.h>

#include "Graphic.h"

namespace Cppie{
	Graphic::Graphic(){
		color = Color::White;
		blend = NONE;
	}
	Graphic::~Graphic(){
	}

	int Graphic::initialize(const char *rdriver){
		window = SDL_CreateWindow("chocopie",
						SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
						480, 320, 0);
		if(window == NULL)
			return -2;

		
		int n = SDL_GetNumRenderDrivers();
		for(int i=0;i<n;i++){
			SDL_RendererInfo info;

			SDL_GetRenderDriverInfo(i, &info);
			if(!strcmp(info.name, rdriver)){
				renderer = SDL_CreateRenderer(window, i,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			}
		}
		if(renderer == NULL)
			return -3;
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
		SDL_SetWindowTitle(window, title);
	}
	const char *Graphic::getTitle(){
		return SDL_GetWindowTitle(window);
	}
};
