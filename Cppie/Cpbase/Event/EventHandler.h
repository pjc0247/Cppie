#pragma once

#include "../System/Core.h"

#include "Event.h"
#include "EventType.h"

namespace Cppie{
	class EventHandler{
	public:
		virtual void onEvent(Event e){
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

		virtual void onKeyDown(int key){
		}
		virtual void onKeyUp(int key){
		}

		virtual void onLeftDown(int x,int y){
		}
		virtual void onLeftUp(int x,int y){
		}
		virtual void onRightDown(int x,int y){
		}
		virtual void onRightUp(int x,int y){
		}

		virtual void onExit(){
		}
	};
};