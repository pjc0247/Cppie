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

		pauseTick = -1;

		taskmgr->add(this);

		return 0;
	}
	void DelayedTask::dispose(){
		taskmgr->remove(this);
	}

	void DelayedTask::update(){
		if(this->state != CPPIE_TASKSTATE_WAITING)
			return;

		if(paused())
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

	void DelayedTask::pause(){
		pauseTick = getTicks();
	}
	void DelayedTask::resume(){
		startTick += getTicks() - pauseTick;

		pauseTick = -1;
	}

	bool DelayedTask::paused(){
		if(pauseTick > 0)
			return true;
		else return false;
	}

	void DelayedTask::stop(){
		this->state = CPPIE_TASKSTATE_DEAD;
	}
};