#include "AsyncTask.h"

#include "Task.h"

namespace Cppie{

	struct AsyncTaskParam{
		AsyncTask	*klass;
		int			posepone;
	};

	AsyncTask::AsyncTask(Task task){
		this->task = task;
	}
	AsyncTask::~AsyncTask(){
	}

	unsigned int __stdcall AsyncTask::TaskThread(void *arg){
		AsyncTaskParam *p;
		p = (AsyncTaskParam*)arg;

		Delay(p->posepone);
		p->klass->task();

		delete p;

		return 0;
	}
	void AsyncTask::run(int postpone){
		AsyncTaskParam *p = new AsyncTaskParam;

		p->klass = this;
		p->posepone = postpone;

		thread = _beginthreadex(
			NULL,0, Cppie::AsyncTask::TaskThread, p,NULL,NULL);
	}
};