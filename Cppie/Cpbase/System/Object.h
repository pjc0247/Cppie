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

	class DrawableObject : public Object{
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

		virtual void update(){
		}
		virtual void draw(int x=0,int y=0){
		}
	};
};