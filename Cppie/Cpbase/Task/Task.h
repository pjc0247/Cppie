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
#define CPPIE_TASKSTATE_DEAD	0	// �۾��� ����ǰ� �ִ� ���µ� �ƴϰ�, ����� ������ ���� ����
#define CPPIE_TASKSTATE_WAITING	1	// �۾��� ������ ����ϰ� �ִ� ����
#define CPPIE_TASKSTATE_RUNNING	2	// �۾��� �������� ����
#define CPPIE_TASkSTATE_PAUSED	3	// �۾��� �Ͻ� ������ ����
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