#include "Window.h"

#include "../System/Core.h"

namespace Cppie{
	Window::Window(){
	}
	Window::Window(int x,int y,int w,int h){
		initialize(x,y,w,h);
	}
	Window::~Window(){
		dispose();
	}

	int Window::initialize(int x,int y,int w,int h){
		GameObject::initialize(x,y, nullptr);

		visible = true;
		mouseHovered = false;

		this->w = w;
		this->h = h;

		winmgr->add(this);

		return 0;
	}
	void Window::dispose(){
		winmgr->remove(this);
	}

	void Window::draw(float x,float y){
		graphic->color = Color::White;
		graphic->fill(x,y,w,h);
	}
	void Window::update(){
		GameObject::update();
	}

	void Window::focus(){
		winmgr->setFocus(this);
	}
	void Window::unfocus(){
		if(focused())
			winmgr->clearFocus();
	}
	bool Window::focused(){
		if(winmgr->getFocused() == this)
			return true;
		else return false;
	}
};