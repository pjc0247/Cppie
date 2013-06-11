#pragma once

namespace Cppie{
	class Rect{
	public:
		int x,y,w,h;

	public:
		Rect(){
			set(0,0);
		}
		Rect(int x,int y,int w=1,int h=1){
			set(x,y);
		}
		virtual ~Rect(){
		}

		virtual int initialize(){
			return 0;
		}
		virtual void dispose(){
		}

		void set(int x=0,int y=0,int w=0,int h=0){
			this->x = x;
			this->y = y;
			this->w = w;
			this->h = h;
		}
	};

	bool HasIntersection(Rect a,Rect b);
};