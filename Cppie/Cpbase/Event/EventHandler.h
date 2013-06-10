#pragma once

#include "Event.h"
#include "EventType.h"

namespace Cppie{
	class EventHandler{
	public:
		EventHandler();
		virtual ~EventHandler();

		virtual void onEvent(Event e);

		virtual void onKeyDown(int key, bool repeated);
		virtual void onKeyUp(int key, bool repeated);

		virtual void onLeftDown(int x,int y);
		virtual void onLeftUp(int x,int y);
		virtual void onRightDown(int x,int y);
		virtual void onRightUp(int x,int y);

		virtual void onMouseMove(int x,int y);

		virtual void onExit();
	};
};