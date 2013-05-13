#include "AsyncTask.h"

#include "Task.h"

namespace Cppie{

	struct AsyncTaskParam{
		AsyncTask	*klass;
		int			posepone;
	};

	AsyncTask::AsyncTask(Task task){
		initialize(task);
	}
	AsyncTask::~AsyncTask(){
		dispose();
	}

	int AsyncTask::initialize(Task task){
		this->task = task;
		this->thread = nullptr;

		return 0;
	}
	void AsyncTask::dispose(){
	}

	int AsyncTask::TaskThread(void *arg){
		AsyncTaskParam *p;
		p = (AsyncTaskParam*)arg;

		delay(p->posepone);
		p->klass->task();

		delete p;

		return 0;
	}
	void AsyncTask::run(int postpone){
		AsyncTaskParam *p = new AsyncTaskParam;

		p->klass = this;
		p->posepone = postpone;

		thread = SDL_CreateThread(
			Cppie::AsyncTask::TaskThread, NULL, p);
	}

	int AsyncTask::wait(){
		int result;

		SDL_WaitThread(thread, &result);
		this->thread = nullptr;

		return result;
	}
};