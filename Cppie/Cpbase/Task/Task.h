#pragma once

#include "../System/Object.h"

#include <functional>

using namespace std;

#define CPPIE_TASK(code)		[&](){code}
#define CPPIE_SAFE_TASK(code)	[=](){code}
typedef function<void()>		Task;

#define CPPIE_TASK_IMMEDIATE	0
#define CPPIE_TASK_NEXT_LOOP	0

/*
#define CPPIE_TASKSTATE_DEAD	0	// 작업이 실행되고 있는 상태도 아니고, 실행될 예정도 없는 상태
#define CPPIE_TASKSTATE_WAITING	1	// 작업이 실행을 대기하고 있는 상태
#define CPPIE_TASKSTATE_RUNNING	2	// 작업이 실행중인 상태
#define CPPIE_TASkSTATE_PAUSED	3	// 작업이 일시 중지된 상태
*/

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