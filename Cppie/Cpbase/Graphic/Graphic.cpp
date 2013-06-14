#pragma once

#include <stdio.h>
#include <SDL.h>

#include "../System/Core.h"

#include "Graphic.h"

namespace Cppie{
	Graphic::Graphic(int w,int h,const char *rdriver){
		color = Color::White;
		blend = CPPIE_BLENDMODE_NONE;

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
		if(renderer == nullptr){
			logger->error("Open GL not supported");

			return -3;
		}

		logger->output("Graphic system initialized");

		logger->output("Graphic Device Info");
		logger->output("  - Renderer : %s", "OpenGL");
		logger->output("  - Renderer Version : %s", glGetString(GL_VERSION));
		logger->output("  - Rendering Device : %s", glGetString(GL_RENDERER));
		logger->output("  - Vendor : %s", glGetString(GL_VENDOR));

		return 0;
	}
	void Graphic::dispose(){
	}

	void Graphic::clear(){
		SDL_SetRenderDrawColor(renderer,color.r, color.g, color.b, color.a);

		SDL_RenderClear(renderer);
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

		SDL_RenderFillRect(renderer, &rect);
	}

	void Graphic::drawCircle(int x,int y,int rad){
		SDL_SetRenderDrawColor(renderer,color.r, color.g, color.b, color.a);
		SDL_SetRenderDrawBlendMode(renderer, blend);

		int old_x = sin(3.14/180 * 0) * rad;
		int old_y = cos(3.14/180 * 0) * rad;
		for(int i=0;i<360;i++){
			int x1 = old_x;
			int y1 = old_y;
			int x2 = sin(3.14/180 * (i+1)) * rad;
			int y2 = cos(3.14/180 * (i+1)) * rad;
			
			SDL_RenderDrawLine(renderer,
				x1+x,y1+y,x2+x,y2+y);

			old_x = x2;
			old_y = y2;
		}
	}
	void Graphic::fillCircle(int x,int y,int rad){
		SDL_SetRenderDrawColor(renderer,color.r, color.g, color.b, color.a);
		SDL_SetRenderDrawBlendMode(renderer, blend);

		for(int i=0;i<180;i++){
			int x1 = sin(3.14/180 * i) * rad;
			int y1 = cos(3.14/180 * i) * rad;
			int x2 = sin(3.14/180 * (360-i)) * rad;
			int y2 = cos(3.14/180 * (360-i)) * rad;

			SDL_RenderDrawLine(renderer,
				x1+x,y1+y,x2+x,y2+y);
		}
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

	void Graphic::setRenderTarget(Texture *tex){
		if(tex == CPPIE_RENDERTARGET_WINDOW){
			SDL_SetRenderTarget(renderer, nullptr);
			renderTarget = nullptr;
		}
		else{
			int result;
			
			result = SDL_SetRenderTarget(renderer, tex->texture);
			renderTarget = tex;

			if(result != 0)
				logger->error("Failed to change render target");
		}
	}
	Texture *Graphic::getRenderTarget(){
		return renderTarget;
	}
};
