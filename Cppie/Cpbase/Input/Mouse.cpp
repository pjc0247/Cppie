#include "Mouse.h"

#include <SDL.h>
#include <memory.h>

#include "../System/Core.h"

namespace Cppie{

	Mouse::Mouse(){
		memset(mousebuffer, 
			CPPIE_MOUSESTATE_UP,
			CPPIE_MOUSEBUFFER_SIZE);
	}
	Mouse::~Mouse(){
	}

	int Mouse::initialize(){
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