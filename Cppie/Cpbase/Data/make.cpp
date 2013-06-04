#include "make.h"

namespace Cppie{
	Size cpSize(int w,int h){
		Size size(w,h);
		return size;
	}
	Rect cpRect(int x,int y,int w,int h){
		Rect rect(x,y,w,h);
		return rect;
	}
	Point cpPoint(int x,int y){
		Point point(x,y);
		return point;
	}
	Color cpColor(int r,int g,int b,int a){
		Color color(r,g,b,a);
		return color;
	}
	Version cpColor(char major,char minor,char fix){
		Version version(major,minor,fix);
		return version;
	}
};