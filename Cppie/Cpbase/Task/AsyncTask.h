#pragma once

#include "../System/Object.h"
#include "Task.h"

#include <functional>

using namespace std;

namespace Cppie{
	class AsyncTask : public Object{
	private:
		Task task;
		SDL_Thread* thread;

	public:
		AsyncTask(Task task);
		virtual ~AsyncTask();

		virtual int initialize(Task task);
		virtual void dispose();

		static int TaskThread(void *arg);

		void run(int postpone=CPPIE_TASK_IMMEDIATE);
		int wait();
	};
};