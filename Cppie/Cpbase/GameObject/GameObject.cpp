#include "GameObject.h"

namespace Cppie{

	GameObject::GameObject(float x,float y,Sprite *sprite){
		initialize(x,y, sprite);
	}

	GameObject::~GameObject(){
		dispose();
	}

	int GameObject::initialize(float x,float y,Sprite *sprite){
		DrawableObject::initialize();

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

		return 0;
	}
	void GameObject::dispose(){
		dynamic_cast<Layer *>(parent)->remove(this);
	}

	void GameObject::draw(float x,float y){
		if(sprite != nullptr){
			sprite->color = color;
			sprite->angle = angle;
			sprite->alpha = alpha;
			sprite->step = step;
			sprite->draw(x,y);
		}
	}

	void GameObject::update(){
		if(visible) draw(x,y);
	}

};