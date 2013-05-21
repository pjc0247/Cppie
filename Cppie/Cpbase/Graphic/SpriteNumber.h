#pragma once

#include "Sprite.h"

namespace Cppie{
	class SpriteNumber : public Sprite{
	public:
		float gap;
	public:
		SpriteNumber();
		SpriteNumber(const char *image);
		virtual ~SpriteNumber();

		void draw(int x,int y,int num);
		void stretch(int x,int y,int w,int h);
	};
};