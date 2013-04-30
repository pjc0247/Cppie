#pragma once

#include <SDL.h>

#include "../System/Object.h"

#include "KeyCode.h"

#define CPPIE_KEYBUFFER_LENGTH 256
#define CPPIE_KEYBUFFER_SIZE sizeof(unsigned char)*CPPIE_KEYBUFFER_LENGTH

namespace Cppie{
	class Keyboard : public Object{
	private:
		unsigned char keybuffer[CPPIE_KEYBUFFER_LENGTH];
		unsigned char prevKeybuffer[CPPIE_KEYBUFFER_LENGTH];

	public:

		Keyboard();
		~Keyboard();

		virtual int initialize();
		virtual void dispose();

		virtual void update();

		bool pressed(int keycode);
		bool triggered(int keycode);
		bool repeated(int keycode);
	};
};