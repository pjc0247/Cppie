#pragma once

#include "../Event/EventHandler.h"

namespace Cppie{
	class Window;

	class WindowEventHandler : public EventHandler{
	public:
		virtual void onFocusGain(Window *before){
		}
		virtual void onFocusLost(Window *after){
		}
	};
};