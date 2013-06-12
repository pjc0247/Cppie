#pragma once

#include "../Data/Color.h"
#include "../Graphic/BlendMode.h"	

namespace Cppie{
	class Object{
	public:
		Object *parent;

	public:
		Object(){
			initialize();
		}
		virtual ~Object(){
			dispose();
		}

		virtual int initialize(){
			parent = nullptr;

			return 0;
		}
		virtual void dispose(){
		}

		virtual void update(){
		}
	};
}