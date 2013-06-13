#pragma once

#include "../Graphic/Texture.h"
#include "../TTF/Font.h"

#include "Window.h"

namespace Cppie{
	class TextView : public Window{
	public:
		char *text;
		
		Texture *textCache;
		Font *font;

	public:
		TextView();
		TextView(int x,int y, const char *text="", Font *font=nullptr, bool cached=true);
		virtual ~TextView();

		virtual int initialize(int x,int y,const char *text, Font *font=nullptr, bool cached = true);
		virtual void dispose();

		virtual void draw(float x,float y);
	};
};