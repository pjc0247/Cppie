#pragma once

#include "AnimatedObject.h"

namespace Cppie{
	class EffectObject : public AnimatedObject{
	public:
		EffectObject();
		EffectObject(float x,float y,Sprite *sprite,int interval=30);

		virtual ~EffectObject();

		virtual void dispose();

		virtual int initialize(float x,float y,Sprite *sprite,int interval=30);
	};
};