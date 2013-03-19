#pragma once

#include <SDL.h>
#include <Windows.h>
#include <gl/GL.h>

#include "../System/Object.h"

#include "../Data/Color.h"
#include "../Data/Rect.h"

namespace Cppie{
	extern SDL_Renderer *renderer;
	extern SDL_Window *window;

	class Graphic : public DrawableObject{
	public:

		Graphic();
		~Graphic();

		void line(int x1,int y1,int x2,int y2);
		void rect(int x,int y,int w,int h);
		void fill(int x,int y,int w,int h);

		void setSize(Rect size);
		Rect getSize();

		void setTitle(const char *title);
		const char *getTitle();
	};
};