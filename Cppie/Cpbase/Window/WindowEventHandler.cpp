#include "WindowEventHandler.h"

#include <stdio.h>

namespace Cppie{
	void WindowEventHandler::onEvent(Event e){
		switch(e.type){
		case CPPIE_WINDOWEVENT_FOCUS_GAIN:
			onFocusGain((Window*)e.data1);
			break;
		case CPPIE_WINDOWEVENT_FOCUS_LOST:
			onFocusLost((Window*)e.data1);
			break;
		case CPPIE_WINDOWEVENT_MOUSE_ENTER:
			onMouseEnter(e.x, e.y);
			break;
		case CPPIE_WINDOWEVENT_MOUSE_LEAVE:
			onMouseLeave(e.x, e.y);
			break;
		default:
			EventHandler::onEvent(e);
			break;
		}
	}

	void WindowEventHandler::onFocusGain(Window *before){
	}
	void WindowEventHandler::onFocusLost(Window *after){
	}

	void WindowEventHandler::onMouseEnter(int x,int y){
	}
	void WindowEventHandler::onMouseLeave(int x,int y){
	}
};