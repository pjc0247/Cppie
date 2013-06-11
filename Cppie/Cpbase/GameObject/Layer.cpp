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

	void Layer::dispose(){
		for(int i=0;i<o.size();i++){
			o[i]->dispose();

			delete o[i];
		}
	}

	void Layer::update(){
		updating = true;
		for(int i=0;i<o.size();i++){
			o[i]->update();
		}
		updating = false;
	}

	void Layer::add(Object *obj){
		obj->parent = this;

		o.push_back(obj);
	}
	void Layer::remove(Object *obj,bool release){
		obj->parent = nullptr;

		o.erase(std::find(o.begin(), o.end(), obj));

		if(release)	delete obj;
	}

};