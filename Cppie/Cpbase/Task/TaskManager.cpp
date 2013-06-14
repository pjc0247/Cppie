#include "TaskManager.h"

namespace Cppie{

	TaskManager::TaskManager(){
		initialize();
	}
	TaskManager::~TaskManager(){
		dispose();
	}

	void TaskManager::update(){
		for(int i=0;i<o.size();i++){
			o[i]->update();
		}
	}

	void TaskManager::add(TaskObject *obj){
		o.push_back(obj);
	}
	void TaskManager::remove(TaskObject *obj){
		o.erase(std::find(o.begin(), o.end(), obj));
	}
};