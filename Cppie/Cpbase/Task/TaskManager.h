#pragma once

#include "../System/Object.h"
#include "../System/Manager.h"

#include "Task.h"

#include <vector>

namespace Cppie{

	class TaskManager : public ManagerObject{
	private:
		std::vector<Object *> o;

	public:
		TaskManager();
		virtual ~TaskManager();

		virtual void update();

		void add(TaskObject *obj);
		void remove(TaskObject *obj);
	};
};