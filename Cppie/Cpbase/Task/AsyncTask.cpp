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

	int AsyncTask::TaskThread(void *arg){
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

		SDL_CreateThread(
			Cppie::AsyncTask::TaskThread, NULL, p);
	}
};