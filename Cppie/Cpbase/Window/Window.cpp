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
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;

		return 0;
	}
	void Window::dispose(){
	}

	void Window::draw(float x,float y){
		graphic->color = Color::White;
		graphic->fill(x,y,w,h);
	}
	void Window::update(){
		GameObject::update();
	}
};