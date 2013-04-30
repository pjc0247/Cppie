#pragma once

#include "../System/Object.h"
#include "ZOrder.h"

#include <list>

namespace Cppie{
	class Layer : public Object{
	public:
		float z;
		std::list<DrawableObject *> o;

	public:
		Layer(float z = Z_OBJECT);

		virtual void update();
		void add(DrawableObject *obj);
		void remove(DrawableObject *obj);
	};
};