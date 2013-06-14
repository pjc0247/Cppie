#include "EffectObject.h"

namespace Cppie{
	EffectObject::EffectObject(){
	}
	EffectObject::EffectObject(float x,float y,Sprite *sprite,int interval){
		initialize(x,y, sprite, interval);
	}

	EffectObject::~EffectObject(){
		dispose();
	}

	void EffectObject::dispose(){
	}

	int EffectObject::initialize(float x,float y,Sprite *sprite,int interval){
		GameObject::initialize(x,y, sprite);

		repeat = false;

		animateTask = new RepeatedTask(CPPIE_SAFE_TASK(
				step ++;

				if(step >= sprite->wSlice*sprite->hSlice){
					if(repeat)
						step = 0;
					else
						delete this;
				}
			));

		animateTask->run(interval);
		
		return 0;
	}
};