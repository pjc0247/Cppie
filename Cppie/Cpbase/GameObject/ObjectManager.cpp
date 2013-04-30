#pragma once

#include "ObjectManager.h"

namespace Cppie{
	class Z_Sort{
	public:
		bool operator() (const Layer *a,const Layer *b){
			return a->z < b->z;
		}
	};

	ObjectManager::ObjectManager(){
	}

	void ObjectManager::update(){
		std::list<Layer *>::iterator itor;

		for(itor=o.begin();itor!=o.end();++itor){
			(*itor)->update();
		}
	}

	void ObjectManager::add(Layer *obj){
		o.push_back(obj);

		o.sort(Z_Sort());
	}
	void ObjectManager::remove(Layer *obj){
		o.remove(obj);
	}
};
