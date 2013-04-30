#include "SystemManager.h"

namespace Cppie{
	System::System(){
	}
	System::~System(){
	}

	void System::update(){
		std::list<Object *>::iterator itor;

		for(itor=o.begin();itor!=o.end();++itor){
			(*itor)->update();
		}
	}

	void System::add(Object *obj){
		o.push_back(obj);
	}
	void System::remove(Object *obj){
		o.remove(obj);
	}

};