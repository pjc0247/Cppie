#pragma once

#include "Layer.h"
#include "ObjectManager.h"

namespace Cppie{
	extern ObjectManager *objmgr;

	Layer::Layer(float z){
		initialize();

		this->z = z;
		updating = false;

		objmgr->add(this);
	}
	Layer::~Layer(){
		dispose();
	}

	void Layer::update(){
		updating = true;
		for(int i=0;i<o.size();i++){
			o[i]->update();
		}
		updating = false;
	}

	void Layer::add(Object *obj){
		o.push_back(obj);
	}
	void Layer::remove(Object *obj){
		o.erase(std::find(o.begin(), o.end(), obj));
	}

};