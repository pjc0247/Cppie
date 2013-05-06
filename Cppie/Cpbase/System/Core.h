#pragma once

#include <SDL.h>

#include "SystemManager.h"
#include "../Log/Log.h"
#include "../Scene/SceneManager.h"
#include "../Graphic/Graphic.h"
#include "../Audio/SoundManager.h"
#include "../GameObject/ObjectManager.h"
#include "../Input/Keyboard.h"
#include "../Input/Mouse.h"

namespace Cppie{
	extern SDL_Window *window;
	extern SDL_Renderer *renderer;

	extern Log *logger;

	extern System *system;

	extern Graphic *graphic;

	extern SoundManager *sndmgr;

	extern SceneManager *scene;
	extern ObjectManager *objmgr;

	extern Keyboard *keyboard;
	extern Mouse *mouse;

	int initialize();
	void quit();
	void run();
};