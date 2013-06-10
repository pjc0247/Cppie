#pragma once

#include "../System/Manager.h"

#include "Event.h"

namespace Cppie{
	class EventManager : public ManagerObject{
	protected:
		bool keyRepeat;

	public:
		EventManager();
		virtual ~EventManager();

		virtual int initialize();
		virtual void dispose();

		void raiseEvent(Event e);

		void enableKeyRepeat();
		void disableKeyRepeat();

		bool queryKeyRepeat();
	};
};