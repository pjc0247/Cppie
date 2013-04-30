#pragma once

#include "Layer.h"
#include "ObjectManager.h"

namespace Cppie{
	extern ObjectManager *objmgr;

	Layer::Layer(float z){
		this->z = z;

		objmgr->add(this);
	}

	void Layer::update(){
		std::list<Object *>::iterator itor;

		for(itor=o.begin();itor!=o.end();++itor){
			(*itor)->update();
		}
	}

	void Layer::add(Object *obj){
		o.push_back(obj);
	}
	void Layer::remove(Object *obj){
		o.remove(obj);
	}

};