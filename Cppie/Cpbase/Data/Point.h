#pragma once

namespace Cppie{
	class Point{
	public:
		int x,y;

	public:
		Point(int x,int y){
			set(x,y);
		}
		~Point(){
		}

		virtual int initialize(){
			return 0;
		}
		virtual void dispose(){
		}

		void set(int x=0,int y=0){
			this->x = x;
			this->y = y;
		}

	public:
		const static Point Zero;
	};
};