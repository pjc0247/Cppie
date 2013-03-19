#pragma once

#include "GameObject.h"
#include "ZOrder.h"

#include <list>

namespace Cppie{
	class Layer : public Object{
	public:
		float z;
		std::list<GameObject *> o;

	public:
		Layer(float z = Z_OBJECT);

		virtual void update();
		void add(GameObject *obj);
		void remove(GameObject *obj);
	};
};