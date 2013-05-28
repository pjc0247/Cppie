#pragma once

#include "../System/Object.h"

#include "Event.h"

namespace Cppie{
	class EventManager : public Object{
	public:
		EventManager();
		virtual ~EventManager();

		virtual int initialize();
		virtual void dispose();

		void raiseEvent(Event e);
	};
};