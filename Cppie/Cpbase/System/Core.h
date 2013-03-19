#pragma once

#include <SDL.h>

#include "../Debug/Log.h"
#include "../Scene/SceneManager.h"
#include "../Graphic/Graphic.h"
#include "../GameObject/ObjectManager.h"

namespace Cppie{
	extern SDL_Window *window;
	extern SDL_Renderer *renderer;

	extern Graphic *graphic;

	extern SceneManager *scene;
	extern ObjectManager *objmgr;

	int initialize();
	void quit();
	void run();
};