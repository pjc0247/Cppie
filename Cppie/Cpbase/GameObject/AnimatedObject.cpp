#include "AnimatedObject.h"

#include "../System/Core.h"

namespace Cppie{
	AnimatedObject::AnimatedObject(){
	}
	AnimatedObject::AnimatedObject(float x,float y,Sprite *sprite,int interval){
		initialize(x,y, sprite, interval);
	}
	AnimatedObject::~AnimatedObject(){
		dispose();
	}

	int AnimatedObject::initialize(float x,float y,Sprite *sprite,int interval){
		GameObject::initialize(x,y, sprite);

		animateTask = new RepeatedTask(CPPIE_SAFE_TASK(
				step ++;
				if(step >= sprite->wSlice*sprite->hSlice){
					step = 0;
				}
			));

		animateTask->run(interval);
		
		return 0;
	}
	void AnimatedObject::dispose(){
	}

	void AnimatedObject::update(){
		GameObject::draw(x,y);
	}
};