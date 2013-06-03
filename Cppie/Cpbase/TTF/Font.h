#pragma once 

#include <SDL_TTF.h>

#include "../System/Object.h"
#include "../Graphic/Texture.h"

namespace Cppie{
	class Font : public DrawableObject{
	protected:
		TTF_Font *font;
	public:
		Font();
		Font(const char *font,int size=20);
		~Font();

		virtual int initialize(const char *font,int size);
		virtual void dispose();

		Size querySize(char *msg);

		Texture *render(const char *msg);
		void draw(int x,int y,const char *msg);
	};
};