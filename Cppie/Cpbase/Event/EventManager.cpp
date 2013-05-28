#include "EventManager.h"

#include "../System/Core.h"

namespace Cppie{
	EventManager::EventManager(){
		initialize();
	}
	EventManager::~EventManager(){
		dispose();
	}

	int EventManager::initialize(){
		logger->output("Event management system initialized");

		return 0;
	}
	void EventManager::dispose(){
	}

	void EventManager::raiseEvent(Event e){
		scene->scene->onEvent(e);
	}
};