#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
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

	EventManager *eventmgr = nullptr;

	WindowManager *winmgr = nullptr;

	int initialize(int w,int h){
		logger = new Log();

		logger->output("Cppie initializing...");

		if(SDL_Init(SDL_INIT_VIDEO) != 0){
			logger->error("Cannot initialize SDL video system");
			return -1;
		}
		logger->output("video system initialized");

		if(TTF_Init() != 0){
			logger->error("Cannot initialize TrueType Font system");
			return -2;
		}
		logger->output("TreuType Font system initialized");

		system = new System();

		graphic = new Graphic(w,h,CPPIE_RENDERER_OPENGL);

		sndmgr = new SoundManager(CPPIE_SOUND_MAXCHANNELS);

		scene = new SceneManager();
		objmgr = new ObjectManager();

		keyboard = new Keyboard();
		mouse = new Mouse();

		taskmgr = new TaskManager();

		eventmgr = new EventManager();

		winmgr = new WindowManager();

		graphic->setTitle("Cppie");

		system->add(scene);
		system->add(objmgr);
		system->add(keyboard);
		system->add(mouse);
		
		system->add(taskmgr);
		system->add(winmgr);

		logger->output("All systems ready...");

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
					{
						Event e;

						e.type = CPPIE_EVENT_EXIT;
						
						eventmgr->raiseEvent(e);

						quit = true;

						break;
					}
				case SDL_MOUSEBUTTONDOWN:
					{
						Event e;

						switch(event.button.button){
						case SDL_BUTTON_LEFT:
							mouse->setState(
								CPPIE_MOUSEBUTTON_LEFT, CPPIE_MOUSESTATE_DOWN);

							e.type = CPPIE_EVENT_LEFTDOWN;
							break;
						case SDL_BUTTON_RIGHT:
							mouse->setState(
								CPPIE_MOUSEBUTTON_RIGHT, CPPIE_MOUSESTATE_DOWN);

							e.type = CPPIE_EVENT_RIGHTDOWN;
							break;
						case SDL_BUTTON_MIDDLE:
							mouse->setState(
								CPPIE_MOUSEBUTTON_WHEEL, CPPIE_MOUSESTATE_DOWN);
							break;
						}

						e.x = event.button.x;
						e.y = event.button.y;

						eventmgr->raiseEvent(e);

						break;
					}
				case SDL_MOUSEBUTTONUP:
					{
						Event e;

						switch(event.button.button){
						case SDL_BUTTON_LEFT:
							mouse->setState(
								CPPIE_MOUSEBUTTON_LEFT, CPPIE_MOUSESTATE_UP);

							e.type = CPPIE_EVENT_LEFTUP;
							break;
						case SDL_BUTTON_RIGHT:
							mouse->setState(
								CPPIE_MOUSEBUTTON_RIGHT, CPPIE_MOUSESTATE_UP);

							e.type = CPPIE_EVENT_RIGHTUP;
							break;
						case SDL_BUTTON_MIDDLE:
							mouse->setState(
								CPPIE_MOUSEBUTTON_WHEEL, CPPIE_MOUSESTATE_UP);
							break;
						}
						break;

						e.x = event.button.x;
						e.y = event.button.y;

						eventmgr->raiseEvent(e);

						break;
					}
				case SDL_MOUSEMOTION:
					{
						Event e;

						e.type = CPPIE_EVENT_MOUSEMOVE;
						e.x = event.motion.x;
						e.y = event.motion.y;

						eventmgr->raiseEvent(e);

						break;
					}

				case SDL_KEYDOWN:
					{
						Event e;

						e.type = CPPIE_EVENT_KEYDOWN;
						e.key = event.key.keysym.sym;
						e.repeated = event.key.repeat;

						eventmgr->raiseEvent(e);

						break;
					}
				case SDL_KEYUP:
					{
						Event e;

						e.type = CPPIE_EVENT_KEYUP;
						e.key = event.key.keysym.sym;
						e.repeated = event.key.repeat;

						eventmgr->raiseEvent(e);

						break;
					}
				}
			}

			system->update();
			SDL_RenderPresent(renderer);

			system->loopCount ++;

			unsigned int elapsed;
			elapsed = (SDL_GetTicks() - startTick);
			if(elapsed == 0) elapsed = 1;
			fps = 1000.0f / elapsed;
			{
				char title[128];
				sprintf_s(title, "%s - fps : %.1f",
									graphic->getTitle(), fps);
				SDL_SetWindowTitle(window, title);
			}
		}

		scene->dispose();
	}
};