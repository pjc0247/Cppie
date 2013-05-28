#pragma once

#include "../System/object.h"
#include "../Event/EventHandler.h"

namespace Cppie{
	class Scene : public Object, public EventHandler{
	public:
		virtual int initialize(){
			return 0;
		}
		virtual void dispose(){
		}
		virtual void update(){
		}
	};
};