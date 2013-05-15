#include "SpriteNumber.h"

namespace Cppie{
	SpriteNumber::SpriteNumber(){
	}
	SpriteNumber::SpriteNumber(const char *image){
		initialize(image, 10,1);
	}
	SpriteNumber::~SpriteNumber(){
		dispose();
	}

	void SpriteNumber::draw(int x,int y,int num){
		int len = 0;

		int tmp = num;
		do{
			len ++;
			tmp /= 10;
		}while(tmp != 0);

		for(int i=0;i<len;i++){
			step = num%10;
			Sprite::draw(x+(len-i-1)*w,y);
			num /= 10;
		}
	}
};