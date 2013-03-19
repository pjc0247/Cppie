#pragma once

#include "Layer.h"

#include <list>

namespace Cppie{
	class ObjectManager : public Object{
	public:
		std::list<Layer *> o;

	public:
		ObjectManager();

		virtual void update();

		void add(Layer *obj);
		void remove(Layer *obj);
	};
};
