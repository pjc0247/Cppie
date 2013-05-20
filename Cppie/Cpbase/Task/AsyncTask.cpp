#include "AsyncTask.h"

#include "Task.h"

namespace Cppie{

	struct AsyncTaskParam{
		AsyncTask	*klass;
		int			delay;
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

		this->state = CPPIE_TASKSTATE_DEAD;

		return 0;
	}
	void AsyncTask::dispose(){
	}

	int AsyncTask::TaskThread(void *arg){
		AsyncTaskParam *p;
		p = (AsyncTaskParam*)arg;

		delay(p->delay);

		p->klass->state = CPPIE_TASKSTATE_RUNNING;
		p->klass->task();
		p->klass->state = CPPIE_TASKSTATE_DEAD;

		delete p;

		return 0;
	}
	void AsyncTask::run(int delay){
		AsyncTaskParam *p = new AsyncTaskParam;

		p->klass = this;
		p->delay = delay;

		thread = SDL_CreateThread(
			Cppie::AsyncTask::TaskThread, NULL, p);

		this->state = CPPIE_TASKSTATE_WAITING;
	}

	int AsyncTask::wait(){
		int result;

		SDL_WaitThread(thread, &result);
		this->thread = nullptr;

		return result;
	}
};