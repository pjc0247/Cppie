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

		repeat = true;

		animateTask = new RepeatedTask(CPPIE_SAFE_TASK(
				step ++;

				if(step >= sprite->wSlice*sprite->hSlice){
					if(repeat)
						step = 0;
					else
						step --;
				}
			));

		animateTask->run(interval);
		
		return 0;
	}
	void AnimatedObject::dispose(){
		delete animateTask;
	}

	void AnimatedObject::update(){
		GameObject::draw(x,y);
	}
};