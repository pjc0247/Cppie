#include "Mouse.h"

#include "../System/Core.h"

#include <SDL.h>
#include <memory.h>

namespace Cppie{

	Mouse::Mouse(){
		initialize();
	}
	Mouse::~Mouse(){
	}

	int Mouse::initialize(){
		memset(mousebuffer, 
			CPPIE_MOUSESTATE_UP,
			CPPIE_MOUSEBUFFER_SIZE);

		logger->output("Mouse input system initialized");

		return 0;
	}
	void Mouse::dispose(){
	}
	void Mouse::update(){
		SDL_GetMouseState(&x, &y);
	}

	bool Mouse::getState(int button){
		if(button < CPPIE_MOUSEBUTTON_LEFT &&
			button > CPPIE_MOUSEBUTTON_WHEEL){
				//logger->output("%s
				return false;
		}
		return mousebuffer[button];
	}
	void Mouse::setState(int button,bool state){
		if(button < CPPIE_MOUSEBUTTON_LEFT &&
			button > CPPIE_MOUSEBUTTON_WHEEL){
				//logger->output("%s
		}
		mousebuffer[button] = state;
	}
};