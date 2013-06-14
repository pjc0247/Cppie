#pragma once

#include "Task.h"
#include "DelayedTask.h"

namespace Cppie{
	class RepeatedTask : public DelayedTask{
	public:
		RepeatedTask();
		RepeatedTask(Task task);
		virtual ~RepeatedTask();

		virtual void dispose();

		virtual void update();
	};
};