#include "Rect.h"

namespace Cppie{
	Rect::Rect(){
		set(0,0);
	}
	Rect::Rect(int x,int y,int w,int h){
		set(x,y,w,h);
	}

	Rect::~Rect(){
	}

	int Rect::initialize(int x,int y,int w,int h){
		set(x,y,w,h);
	}

	void Rect::set(int x,int y,int w,int h){
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}

	bool Rect::collideWith(Rect r){
		return HasIntersection(*this, r);
	}

	bool HasIntersection(Rect a,Rect b){
		int Amin, Amax, Bmin, Bmax;

		Amin = a.x;
		Amax = Amin + a.w;
		Bmin = b.x;
		Bmax = Bmin + b.w;
		if (Bmin > Amin)
			Amin = Bmin;
		if (Bmax < Amax)
			Amax = Bmax;
		if (Amax <= Amin)
			return false;

		Amin = a.y;
		Amax = Amin + a.h;
		Bmin = b.y;
		Bmax = Bmin + b.h;
		if (Bmin > Amin)
			Amin = Bmin;
		if (Bmax < Amax)
			Amax = Bmax;
		if (Amax <= Amin)
			return false;

		return true;
	}
};