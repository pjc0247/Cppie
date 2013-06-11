#pragma once

#include "../Event/EventHandler.h"

#include "Window.h"

namespace Cppie{
	class WindowEventHandler : public EventHandler{
	public:
		virtual void onFocusGain(Window *before){
		}
		virtual void onFocusLost(Window *after){
		}
	};
};