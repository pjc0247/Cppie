#pragma once

#include "../System/object.h"

namespace Cppie{
	class Scene : public Object{
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