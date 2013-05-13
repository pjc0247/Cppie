#include "TaskManager.h"

namespace Cppie{

	TaskManager::TaskManager(){
		initialize();
	}
	TaskManager::~TaskManager(){
		dispose();
	}

	void TaskManager::update(){
		std::list<Object *>::iterator itor;

		for(itor=o.begin();itor!=o.end();++itor){
			(*itor)->update();
		}
	}

	void TaskManager::add(TaskObject *obj){
		o.push_back(obj);
	}
	void TaskManager::remove(TaskObject *obj){
		o.remove(obj);
	}
};