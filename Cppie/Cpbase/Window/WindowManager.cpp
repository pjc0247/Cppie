#include "WindowManager.h"

namespace Cppie{
	WindowManager::WindowManager(){
		initialize();
	}
	WindowManager::~WindowManager(){
		dispose();
	}

	int WindowManager::initialize(){
		layer = new Layer(CPPIE_Z_UI);

		focused = nullptr;

		return 0;
	}
	void WindowManager::dispose(){
		focused = nullptr;

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

	void WindowManager::setFocus(Window *window){
		Window *before = nullptr;

		if(focused != nullptr){
			focused->onFocusLost(window);
			before = focused;
		}

		focused = window;

		window->onFocusGain(before);
	}
	void WindowManager::clearFocus(){
		if(focused != nullptr)
			focused->onFocusLost(nullptr);

		focused = nullptr;
	}
	Window *WindowManager::getFocused(){
		return focused;
	}

	void WindowManager::onEvent(Event e){
		
		std::list<Window *>::iterator itor;

		for(itor=o.begin();itor!=o.end();++itor){
			if(e.type >= CPPIE_EVENT_KEYDOWN && e.type <= CPPIE_EVENT_KEYUP &&
				getFocused() != *itor){
					// do nothing
			}
			(*itor)->onEvent(e);
		}
	}
};