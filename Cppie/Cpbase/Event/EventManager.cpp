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
		if(scene->scene != nullptr)
			scene->scene->onEvent(e);
		else
			logger->error("Failed to raise event - scene is null");
	}

	void EventManager::enableKeyRepeat(){
		keyRepeat = true;
	}
	void EventManager::disableKeyRepeat(){
		keyRepeat = false;
	}

	bool EventManager::queryKeyRepeat(){
		return keyRepeat;
	}
};