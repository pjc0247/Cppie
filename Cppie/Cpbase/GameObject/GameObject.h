#pragma once

#include "../Graphic/DrawableObject.h"
#include "../Graphic/Sprite.h"
#include "../Data/Rect.h"

#include "Layer.h"

namespace Cppie{
	class GameObject : public DrawableObject{
	public:
		float x,y;
		bool visible;
		float angle;
		int step;

		Sprite *sprite;
		Rect rect;

	public:
		GameObject(float x=0,float y=0,Sprite *sprite=nullptr);
		virtual ~GameObject();

		virtual int initialize(float x=0,float y=0,Sprite *sprite=nullptr);
		virtual void dispose();

		virtual void draw(float x,float y);

		virtual void update();
	};
};