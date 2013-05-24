#pragma once

#include <SDL.h>
#include <stdio.h>
#include <string.h>

#include "Core.h"

namespace Cppie{
	SDL_Window *window = nullptr;
	SDL_Renderer *renderer = nullptr;

	System *system = nullptr;
	
	Graphic *graphic = nullptr;

	SoundManager *sndmgr = nullptr;

	SceneManager *scene = nullptr;
	ObjectManager *objmgr = nullptr;

	Keyboard *keyboard = nullptr;
	Mouse *mouse = nullptr;

	Log *logger = nullptr;

	TaskManager *taskmgr = nullptr;

	int initialize(int w,int h){
		logger = new Log();

		logger->output("Cppie initializing...");

		if(SDL_Init(SDL_INIT_VIDEO) != 0)
			return -1;

		system = new System();

		graphic = new Graphic(w,h,CPPIE_RENDERER_OPENGL);

		sndmgr = new SoundManager(CPPIE_SOUND_MAXCHANNELS);

		scene = new SceneManager();
		objmgr = new ObjectManager();

		keyboard = new Keyboard();
		mouse = new Mouse();

		taskmgr = new TaskManager();

		graphic->setTitle("Cppie");

		system->add(scene);
		system->add(objmgr);
		system->add(keyboard);
		system->add(mouse);
		
		system->add(taskmgr);

		logger->output("All done");

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
				case SDL_MOUSEBUTTONDOWN:
					switch(event.button.button){
					case SDL_BUTTON_LEFT:
						mouse->setState(
							CPPIE_MOUSEBUTTON_LEFT, CPPIE_MOUSESTATE_DOWN);
						break;
					case SDL_BUTTON_RIGHT:
						mouse->setState(
							CPPIE_MOUSEBUTTON_RIGHT, CPPIE_MOUSESTATE_DOWN);
						break;
					case SDL_BUTTON_MIDDLE:
						mouse->setState(
							CPPIE_MOUSEBUTTON_WHEEL, CPPIE_MOUSESTATE_DOWN);
						break;
					}
					break;
				case SDL_MOUSEBUTTONUP:
					switch(event.button.button){
					case SDL_BUTTON_LEFT:
						mouse->setState(
							CPPIE_MOUSEBUTTON_LEFT, CPPIE_MOUSESTATE_UP);
						break;
					case SDL_BUTTON_RIGHT:
						mouse->setState(
							CPPIE_MOUSEBUTTON_RIGHT, CPPIE_MOUSESTATE_UP);
						break;
					case SDL_BUTTON_MIDDLE:
						mouse->setState(
							CPPIE_MOUSEBUTTON_WHEEL, CPPIE_MOUSESTATE_UP);
						break;
					}
					break;
				}
			}

			system->update();
			SDL_RenderPresent(renderer);

			system->loopCount ++;

			float elapsed;
			elapsed = (SDL_GetTicks() - startTick);
			if(elapsed == 0) elapsed = 1;
			fps = 1000 / elapsed;
			{
				char title[128];
				sprintf_s(title, "%s - fps : %.1f",
									graphic->getTitle(), fps);
				SDL_SetWindowTitle(window, title);
			}
		}
	}
};