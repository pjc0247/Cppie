#pragma once

#include "Object.h"

#include <list>

namespace Cppie{
	class System : public Object{
	public:
		std::list<Object *> o;

	public:
		System();
		virtual ~System();

		virtual void update();
		void add(Object *obj);
		void remove(Object *obj);
	};
};