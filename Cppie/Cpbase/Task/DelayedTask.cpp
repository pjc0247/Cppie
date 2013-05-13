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

		return 0;
	}
	void DelayedTask::dispose(){
	}

	void DelayedTask::update(){
		if(delay == CPPIE_TASK_NEXT_LOOP){
			if(startCount != system->loopCount){
				task();
			}
		}
		else{
			if(getTicks() - startTick >= delay){
				task();
			}
		}
	}

	void DelayedTask::run(int delay){
		if(delay == CPPIE_TASK_NEXT_LOOP){
			startCount = system->loopCount;
		}
		else{
			startTick = getTicks();
		}
	}
};