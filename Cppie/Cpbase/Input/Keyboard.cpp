#include "Keyboard.h"

#include "../System/Core.h"

#include "KeyCode.h"

#include <memory.h>

namespace Cppie{
	Keyboard::Keyboard(){
		initialize();
	}
	Keyboard::~Keyboard(){
	}

	int Keyboard::initialize(){
		memset(keybuffer, 
			CPPIE_KEYBOARDSTATE_UP,
			CPPIE_KEYBUFFER_SIZE);

		logger->output("Keyboard input system initialized");

		return 0;
	}
	void Keyboard::dispose(){
	}

	void Keyboard::update(){
		memcpy(prevKeybuffer, keybuffer, CPPIE_KEYBUFFER_SIZE);

		memcpy(keybuffer, SDL_GetKeyboardState(NULL), CPPIE_KEYBUFFER_SIZE);
	}

	bool Keyboard::pressed(int keycode){
		SDL_Scancode scancode = SDL_GetScancodeFromKey(keycode);
		if(keybuffer[scancode])
			return true;
		else
			return false;
	}
	bool Keyboard::triggered(int keycode){
		SDL_Scancode scancode = SDL_GetScancodeFromKey(keycode);
		if(pressed(keycode) && !prevKeybuffer[scancode])
			return true;
		else
			return false;
	}
	bool Keyboard::repeated(int keycode){
		SDL_Scancode scancode = SDL_GetScancodeFromKey(keycode);
		if(pressed(keycode) && prevKeybuffer[scancode])
			return true;
		else
			return false;
	}
}