#pragma once

#include "../Data//Color.h"
#include "../Graphic/BlendMode.h"

#include <stdio.h>

namespace Cppie{
	class Object{
	public:
		virtual int initialize(){
			return 0;
		}
		virtual void dispose(){
		}
		virtual void update(){
		}
	};

	class DrawableObject{
	public:
		Color color;
		BlendMode blend;

	public:
		DrawableObject(){
			color = Color::White;
			blend = BLEND;
		}
		~DrawableObject(){
		}

		virtual void draw(int x,int y){
		}

		void setColor(Color color){
			this->color = color;
		}
		Color getColor(){
			return this->color;
		}
		void setBlendMode(BlendMode blend){
			this->blend = blend;
		}
		BlendMode getBlendMode(){
			return this->blend;
		}
	};
};