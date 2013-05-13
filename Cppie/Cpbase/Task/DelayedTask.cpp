#include "DelayedTask.h"

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

	void DelayedTask::run(int delay){
		if(delay == CPPIE_TASK_NEXT_LOOP){
		}
		else{

		}
	}
};