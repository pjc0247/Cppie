#include "WindowManager.h"

namespace Cppie{
	WindowManager::WindowManager(){
		layer = new Layer(CPPIE_Z_UI);
	}
	WindowManager::~WindowManager(){
		delete layer;
	}

	void WindowManager::update(){
		/*std::list<Window *>::iterator itor;

		for(itor=o.begin();itor!=o.end();++itor){
			(*itor)->update();
		}*/
	}

	void WindowManager::add(Window *window){
		o.push_back(window);
		layer->add(window);
	}
	void WindowManager::remove(Window *window){
		o.remove(window);
		layer->remove(window);
	}
};