#pragma once

#include "Object.h"
#include "Manager.h"

#include <list>

namespace Cppie{
	class System : public ManagerObject{
	public:
		std::list<Object *> o;

		int loopCount;

	public:
		System();
		virtual ~System();

		virtual void update();
		void add(Object *obj);
		void remove(Object *obj);
	};
};