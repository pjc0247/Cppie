#pragma once

#include "../System/Object.h"

#include <functional>
#include <process.h>

using namespace std;

#define CPPIE_TASK(code)		[&](){code}
#define CPPIE_SAFE_TASK(code)	[=](){code}
typedef function<void()>		Task;

#define CPPIE_TASK_IMMEDIATE	0

namespace Cppie{
	class AsyncTask : public Object{
	private:
		Task task;
		unsigned int thread;

	public:
		AsyncTask(Task task);
		~AsyncTask();

		static unsigned int __stdcall TaskThread(void *arg);

		void run(int postpone=CPPIE_TASK_IMMEDIATE);
	};
};