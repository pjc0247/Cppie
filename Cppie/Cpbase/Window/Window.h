#pragma once

#include "../GameObject/GameObject.h"

namespace Cppie{
	class Window : public GameObject{
	public:
		int w,h;

	public:
		Window();
		Window(int x,int y,int w,int h);
		virtual ~Window();

		virtual int initialize(int x,int y,int w,int h);
		virtual void dispose();

		virtual void draw(float x,float y);
		virtual void update();

	};
};