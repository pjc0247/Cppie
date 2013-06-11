#include "DrawableObject.h"

namespace Cppie{
	DrawableObject::DrawableObject(){
		initialize();
	}
	DrawableObject::~DrawableObject(){
		dispose();
	}

	int DrawableObject::initialize(){
		color = Color::White;
		blend = CPPIE_BLENDMODE_BLEND;	
		alpha = 255;
	}

	void DrawableObject::draw(int x,int y){
	}
};