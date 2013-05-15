#include "Task.h"

namespace Cppie{

	TaskObject::TaskObject(){
	}
	TaskObject::TaskObject(Task task){
		initialize(task);
	}
	TaskObject::~TaskObject(){
		dispose();
	}

	int TaskObject::initialize(Task task){
		return 0;
	}
	void TaskObject::dispose(){
		this->task = nullptr;
	}

	void TaskObject::run(){
		this->task();
			
	}


	int getTicks(){
		return SDL_GetTicks();
	}
	void delay(int ms){
		if(ms <= 0) return;
		SDL_Delay(ms);
	}
};