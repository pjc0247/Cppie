#pragma once

#include "../Event/EventHandler.h"

#include "WindowEventType.h"

namespace Cppie{
	class Window;

	class WindowEventHandler : public EventHandler{
	public:
		virtual void onEvent(Event e);

		virtual void onFocusGain(Window *before);
		virtual void onFocusLost(Window *after);

		virtual void onMouseEnter(int x,int y);
		virtual void onMouseLeave(int x,int y);
	};
};