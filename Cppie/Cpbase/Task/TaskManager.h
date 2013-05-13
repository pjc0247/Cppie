#pragma once

#include "../System/Object.h"

#include "Task.h"

#include <list>

namespace Cppie{

	class TaskManager : public Object{
	private:
		std::list<Object *> o;

	public:
		TaskManager();
		virtual ~TaskManager();

		virtual void update();

		void add(TaskObject *obj);
		void remove(TaskObject *obj);
	};
};