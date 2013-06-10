#pragma once

#include "../System/Object.h"
#include "Task.h"

#include <functional>

using namespace std;

namespace Cppie{
	class DelayedTask : public TaskObject{
	public:
		int delay;
		int startCount;
		int startTick;

		int pausedTick;
		bool paused;

	public:
		DelayedTask();
		DelayedTask(Task task);
		virtual ~DelayedTask();

		virtual int initialize(Task task);
		virtual void dispose();

		virtual void update();

		void run(int delay=CPPIE_TASK_NEXT_LOOP);

		void pause();
		void resume();
	};
};