#pragma once

#include "../System/Object.h"
#include "../Graphic/Sprite.h"
#include "../Data/Rect.h"

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

		GameObject(float x=0,float y=0,Sprite *sprite=nullptr){
			this->x = x;
			this->y = y;

			this->sprite = sprite;
			if(sprite == nullptr){
				visible = false;
				rect.set();
			}
			else{
				visible = true;
				rect.set(x,y,sprite->w,sprite->h);
			}

			step = 0;
			angle = 0;
		}

		virtual int initialize(){
			return 0;
		}
		virtual void dispose(){
		}
		virtual void draw(float x,float y){
			if(sprite != nullptr){
				sprite->color = color;
				sprite->angle = angle;
				sprite->step = step;
				sprite->draw(x,y);
			}
		}
		virtual void update(){
			if(visible) draw(x,y);
		}
	};
};