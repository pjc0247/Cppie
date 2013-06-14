#pragma once

#include "../System/Object.h"

namespace Cppie{
	class SharedResource : public Object{
	public:

	public:
		SharedResource(){
		}
		virtual ~SharedResource(){
		}

		virtual int initialize(){
			return 0;
		}
		virtual void dispose(){
		}

		virtual void update(){
		}
	};
};