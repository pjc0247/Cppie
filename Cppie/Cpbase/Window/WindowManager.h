#pragma once

#include "../System/Manager.h"
#include "../GameObject/Layer.h"

#include "Window.h"

#include <list>

namespace Cppie{
	class WindowManager : public ManagerObject{
	public:
		std::list<Window *> o;
		Layer *layer;

	protected:
		Window *focused;

	public:
		WindowManager();
		virtual ~WindowManager();

		virtual int initialize();
		virtual void dispose();

		virtual void update();

		void add(Window *window);
		void remove(Window *window);

		void setFocus(Window *window);
		void clearFocus();
		Window *getFocused();

		void onEvent(Event e);
	};
};