#pragma once

#include "GameObject.h"

#include "../Graphic/Sprite.h"
#include "../Task/RepeatedTask.h"

namespace Cppie{
	class AnimatedObject : public GameObject{
	public:
		RepeatedTask *animateTask;

		bool repeat;

	public:
		AnimatedObject();
		AnimatedObject(float x,float y,Sprite *sprite,int interval);
		~AnimatedObject();

		virtual int initialize(float x,float y,Sprite *sprite,int interval);
		virtual void dispose();

		virtual void update();
	};
};