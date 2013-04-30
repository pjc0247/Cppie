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
		std::list<DrawableObject *>::iterator itor;

		for(itor=o.begin();itor!=o.end();++itor){
			(*itor)->update();
		}
	}

	void Layer::add(DrawableObject *obj){
		o.push_back(obj);
	}
	void Layer::remove(DrawableObject *obj){
		o.remove(obj);
	}

};