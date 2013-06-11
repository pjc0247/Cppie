#include "Object.h"

namespace Cppie{
	Object::Object(){
		initialize();
	}
	Object::~Object(){
		dispose();
	}

	int Object::initialize(){
		parent = nullptr;
	}
	void Object::dispose(){
	}
	void Object::update(){
	}
};