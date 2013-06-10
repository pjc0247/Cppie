#include "WindowManager.h"

namespace Cppie{
	WindowManager::WindowManager(){
	}
	WindowManager::~WindowManager(){
	}

	void WindowManager::update(){
		std::list<Window *>::iterator itor;

		for(itor=o.begin();itor!=o.end();++itor){
			(*itor)->update();
		}
	}

	void WindowManager::add(Window *window){
		o.push_back(window);
	}
	void WindowManager::remove(Window *window){
		o.remove(window);
	}
};