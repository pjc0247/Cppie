#include "EventHandler.h"

#include "../System/Core.h"

namespace Cppie{
	EventHandler::EventHandler(){
	}
	EventHandler::~EventHandler(){
	}

	void EventHandler::onEvent(Event e){
		switch(e.type){
		case CPPIE_EVENT_EXIT:
			onExit();
			break;
		case CPPIE_EVENT_LEFTDOWN:
			onLeftDown(e.x,e.y);
			break;
		case CPPIE_EVENT_LEFTUP:
			onLeftUp(e.x,e.y);
			break;
		case CPPIE_EVENT_RIGHTDOWN:
			onRightDown(e.x,e.y);
			break;
		case CPPIE_EVENT_RIGHTUP:
			onRightUp(e.x,e.y);
			break;
		case CPPIE_EVENT_KEYDOWN:
			onKeyDown(e.key, e.repeated);
			break;
		case CPPIE_EVENT_KEYUP:
			onKeyUp(e.key, e.repeated);
			break;
		case CPPIE_EVENT_MOUSEMOVE:
			onMouseMove(e.x,e.y);
			break;
		default:
			logger->warn("Unexcepted event");
			break;
		}
	}

	void EventHandler::onKeyDown(int key,bool repeated){
	}
	void EventHandler::onKeyUp(int key,bool repeated){
	}

	void EventHandler::onLeftDown(int x,int y){
	}
	void EventHandler::onLeftUp(int x,int y){
	}
	void EventHandler::onRightDown(int x,int y){
	}
	void EventHandler::onRightUp(int x,int y){
	}

	void EventHandler::onMouseMove(int x,int y){
	}

	void EventHandler::onExit(){
	}
};