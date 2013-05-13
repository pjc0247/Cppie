#pragma once

#include "../System/Object.h"
#include "ZOrder.h"

#include <list>

namespace Cppie{
	class Layer : public Object{
	public:
		float z;
		std::list<Object *> o;

	public:
		Layer(float z = Z_OBJECT);
		virtual ~Layer();

		virtual void update();
		void add(Object *obj);
		void remove(Object *obj);
	};
};