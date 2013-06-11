#include "WindowManager.h"

#include "WindowEventType.h"

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
			else if(e.type >= CPPIE_EVENT_LEFTDOWN && e.type <= CPPIE_EVENT_MOUSEMOVE){
				Rect a,b;
				a.set(e.x,e.y,1,1);
				b.set((*itor)->x,(*itor)->y,(*itor)->w,(*itor)->h);

				if(HasIntersection(a,b)){
					e.x -= (*itor)->x;
					e.y -= (*itor)->y;

					if(! (*itor)->mouseHovered){
						Event e;

						e.type = CPPIE_WINDOWEVENT_MOUSE_ENTER;

						e.x = a.x - b.x;
						e.y = a.x - b.x;

						(*itor)->onEvent(e);
					}

					(*itor)->onEvent(e);
				}
				else if((*itor)->mouseHovered){
					e.type = CPPIE_WINDOWEVENT_MOUSE_LEAVE;

					e.x -= (*itor)->x;
					e.y -= (*itor)->y;

					(*itor)->onEvent(e);
				}
			}
			else
				(*itor)->onEvent(e);
		}
	}
};