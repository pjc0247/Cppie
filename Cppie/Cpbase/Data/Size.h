#pragma once

namespace Cppie{
	class Size{
	public:
		int w,h;

	public:
		Size(int w,int h){
			set(w,h);
		}
		virtual ~Size(){
		}

		virtual int initialize(){
			return 0;
		}
		virtual void dispose(){
		}

		void set(int w=0,int h=0){
			this->w = w;
			this->h = h;
		}
	};
};