#include "EventHandler.h"

namespace Cppie{
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
			onKeyDown(e.key);
			break;
		case CPPIE_EVENT_KEYUP:
			onKeyDown(e.key);
			break;
		default:
			logger->warn("Unexcepted event");
			break;
		}
	}

	void EventHandler::onKeyDown(int key){
	}
	void EventHandler::onKeyUp(int key){
	}

	void EventHandler::onLeftDown(int x,int y){
	}
	void EventHandler::onLeftUp(int x,int y){
	}
	void EventHandler::onRightDown(int x,int y){
	}
	void EventHandler::onRightUp(int x,int y){
	}

	void EventHandler::onExit(){
	}
};