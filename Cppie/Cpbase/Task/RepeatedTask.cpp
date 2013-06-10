#include "RepeatedTask.h"

#include "../System/Core.h"

#include "TaskManager.h"

namespace Cppie{
	RepeatedTask::RepeatedTask(){
	}
	RepeatedTask::RepeatedTask(Task task){
		initialize(task);
	}
	RepeatedTask::~RepeatedTask(){
		dispose();
	}

	void RepeatedTask::update(){
		if(this->state != CPPIE_TASKSTATE_WAITING)
			return;

		if(paused)
			return;

		if(delay == CPPIE_TASK_NEXT_LOOP){
			if(startCount != system->loopCount){
				this->state = CPPIE_TASKSTATE_RUNNING;

				task();

				run(delay);
			}
		}
		else{
			if(getTicks() - startTick >= delay){
				this->state = CPPIE_TASKSTATE_RUNNING;

				task();
				
				run(delay);
			}
		}
	}
};