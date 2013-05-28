#pragma once

#include "../System/Core.h"

#include "Event.h"
#include "EventType.h"

namespace Cppie{
	class EventHandler{
	public:
		virtual void onEvent(Event e);

		virtual void onKeyDown(int key);
		virtual void onKeyUp(int key);

		virtual void onLeftDown(int x,int y);
		virtual void onLeftUp(int x,int y);
		virtual void onRightDown(int x,int y);
		virtual void onRightUp(int x,int y);

		virtual void onExit();
	};
};