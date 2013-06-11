#pragma once

#include "../Data//Color.h"
#include "../Graphic/BlendMode.h"	

#include <stdio.h>

namespace Cppie{
	class Object{
	public:
		

		Object *parent;

	public:
		Object();
		virtual ~Object();

		virtual int initialize();
		virtual void dispose();

		virtual void update();
	};
}