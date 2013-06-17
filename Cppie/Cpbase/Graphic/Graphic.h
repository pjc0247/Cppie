#pragma once

#include <SDL.h>
#include <Windows.h>
#include <gl/GL.h>

#include "../Data/Color.h"
#include "../Data/Rect.h"

#include "DrawableObject.h"
#include "Texture.h"

#define CPPIE_RENDERER_SOFTWARE "software"
#define CPPIE_RENDERER_OPENGL	"opengl"
#define CPPIE_RENDERER_OPENGLES "opengles"
#define CPPIE_RENDERER_DIRECT3D "direct3d"

#define CPPIE_RENDERTARGET_WINDOW	nullptr

namespace Cppie{
	extern SDL_Renderer *renderer;
	extern SDL_Window *window;

	class Graphic : public DrawableObject{
	private:
		char title[256];
		Texture *renderTarget;

	public:

		Graphic(int w,int h,const char *rdriver);
		virtual ~Graphic();

		int initialize(int w,int h,const char *rdriver);
		void dispose();

		void clear();

		void line(int x1,int y1,int x2,int y2);
		void rect(int x,int y,int w,int h);
		void fill(int x,int y,int w,int h);

		void drawCircle(int x,int y,int rad);
		void fillCircle(int x,int y,int rad);

		void setSize(Rect size);
		Rect getSize();

		void setTitle(const char *title);
		const char *getTitle();

		void setRenderTarget(Texture *tex);
		Texture *getRenderTarget();
	};
};	