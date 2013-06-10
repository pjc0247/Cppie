#pragma once

#include "../System/Manager.h"

#include "Window.h"

#include <list>

namespace Cppie{
	class WindowManager : public ManagerObject{
	public:
		std::list<Window *> o;

	public:
		WindowManager();
		virtual ~WindowManager();

		virtual void update();

		void add(Window *window);
		void remove(Window *window);
	};
};