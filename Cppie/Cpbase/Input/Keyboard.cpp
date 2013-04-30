#include "Keyboard.h"
#include "KeyCode.h"

#include <memory.h>

namespace Cppie{
	Keyboard::Keyboard(){
		memset(keybuffer, 0, CPPIE_KEYBUFFER_SIZE);
	}
	Keyboard::~Keyboard(){
	}

	int Keyboard::initialize(){
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