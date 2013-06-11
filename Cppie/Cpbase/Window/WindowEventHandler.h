#pragma once

#include "../Event/EventHandler.h"

#include "Window.h"

namespace Cppie{
	class WindowEventHandler : public EventHandler{

		virtual void onFocusGain(Window *before){
		}
		virtual void onFocusLost(Window *after){
		}
	};
};