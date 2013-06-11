#pragma once

namespace Cppie{
	class Rect{
	public:
		int x,y,w,h;

	public:
		Rect();
		Rect(int x,int y,int w=1,int h=1);
		
		virtual ~Rect();

		virtual int initialize(int x,int y,int w,int h);

		void set(int x=0,int y=0,int w=0,int h=0);

		bool collideWith(Rect r);
	};

	bool HasIntersection(Rect a,Rect b);
};