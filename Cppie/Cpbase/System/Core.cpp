#pragma once

#include <SDL.h>
#include <stdio.h>
#include <string.h>

#include "Core.h"

namespace Cppie{
	SDL_Window *window = nullptr;
	SDL_Renderer *renderer = nullptr;

	Graphic *graphic = nullptr;

	SceneManager *scene = nullptr;
	ObjectManager *objmgr = nullptr;

	Keyboard *keyboard = nullptr;

	Log *log = nullptr;

	int initialize(){
		log = new Log();

		log->output("Cppie initializing...");

		if(SDL_Init(SDL_INIT_VIDEO) != 0)
			return -1;

		graphic = new Graphic();

		scene = new SceneManager();
		objmgr = new ObjectManager();

		keyboard = new Keyboard();

		graphic->initialize(CPPIE_RENDERER_OPENGL);

		log->output("All done");

		return 0;
	}
	void quit(){
		SDL_Quit();
	}

	void run(){
		SDL_Event event;
		bool quit = false;

		while(!quit){
			int startTick = SDL_GetTicks();
			float fps;

			while(SDL_PollEvent(&event)){
				switch(event.type){
				case SDL_QUIT:
					quit = true;
					break;
				}
			}

			scene->update();
			SDL_RenderPresent(renderer);

			float elapsed;
			elapsed = (SDL_GetTicks() - startTick);
			if(elapsed == 0) elapsed = 1;
			fps = 1000 / elapsed;
			{
				char title[128];
				sprintf_s(title, "Cppie - fps : %.1f", fps);
				SDL_SetWindowTitle(window, title);
			}
		}
	}
};