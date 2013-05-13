#pragma once

#include "../System/Object.h"

#include <functional>

using namespace std;

#define CPPIE_TASK(code)		[&](){code}
#define CPPIE_SAFE_TASK(code)	[=](){code}
typedef function<void()>		Task;

#define CPPIE_TASK_IMMEDIATE	0
#define CPPIE_TASK_NEXT_LOOP	0

namespace Cppie{
	class TaskObject : public Object{
	private:
		Task task;

	public:
		TaskObject();
		TaskObject(Task task);
		virtual ~TaskObject();

		virtual int initialize(Task task);
		virtual void dispose();

		virtual void run();
	};

	void Delay(int ms);
};