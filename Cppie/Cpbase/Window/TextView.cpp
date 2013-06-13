#include "TextView.h"

namespace Cppie{
	TextView::TextView(){
	}
	TextView::TextView(int x,int y,const char *text,Font *font,bool cached){
		initialize(x,y, text, font, cached);
	}

	TextView::~TextView(){
		dispose();
	}

	int TextView::initialize(int x,int y,const char *text,Font *font,bool cached){
		int length;

		length = strlen(text);

		if(length > 0)
			this->text = new char[length];
		else
			this->text = nullptr;

		if(font == nullptr){
		}

		if(cached){
			textCache = font->render(text);
		}

		return 0;
	}
	void TextView::dispose(){
		if(textCache != nullptr)
			delete textCache;
		if(text != nullptr)
			delete text;
	}

	void TextView::draw(float x,float y){
		if(textCache == nullptr)
			font->draw(x,y, text);
		else
			textCache->draw(x,y);
	}


};