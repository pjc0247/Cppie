#include "DelayedTask.h"

#include "../System/Core.h"

namespace Cppie{
	DelayedTask::DelayedTask(){
	}
	DelayedTask::DelayedTask(Task task){
		initialize(task);
	}
	DelayedTask::~DelayedTask(){
		dispose();
	}

	int DelayedTask::initialize(Task task){
		this->task = task;
		this->state = CPPIE_TASKSTATE_RUNNING;

		taskmgr->add(this);

		return 0;
	}
	void DelayedTask::dispose(){
	}

	void DelayedTask::update(){
		if(this->state != CPPIE_TASKSTATE_WAITING)
			return;

		if(delay == CPPIE_TASK_NEXT_LOOP){
			if(startCount != system->loopCount){
				this->state = CPPIE_TASKSTATE_RUNNING;

				task();

				this->state = CPPIE_TASKSTATE_DEAD;
			}
		}
		else{
			if(getTicks() - startTick >= delay){
				this->state = CPPIE_TASKSTATE_RUNNING;

				task();
				
				this->state = CPPIE_TASKSTATE_DEAD;
			}
		}
	}

	void DelayedTask::run(int delay){
		if(delay == CPPIE_TASK_NEXT_LOOP){
			this->startCount = system->loopCount;

			this->state = CPPIE_TASKSTATE_WAITING;
		}
		else{
			this->delay = delay;
			this->startTick = getTicks();

			this->state = CPPIE_TASKSTATE_WAITING;
		}
	}
};