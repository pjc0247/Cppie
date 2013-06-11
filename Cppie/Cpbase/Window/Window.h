#pragma once

#include "../GameObject/GameObject.h"

#include "WindowEventHandler.h"

namespace Cppie{
	class Window : public GameObject, public WindowEventHandler{
	public:
		int w,h;

		bool mouseHovered;

	public:
		Window();
		Window(int x,int y,int w,int h);
		virtual ~Window();

		virtual int initialize(int x,int y,int w,int h);
		virtual void dispose();

		virtual void draw(float x,float y);
		virtual void update();

		void focus();
		void unfocus();
		bool focused();
	};
};