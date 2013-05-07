#pragma once

namespace Cppie{
	class Color{
	public:
		int r,g,b,a;

	public:
		Color(){
			set(0,0,0,255);
		}
		Color(int r=0,int g=0,int b=0,int a=255){
			set(r,g,b,a);
		}
		virtual ~Color(){
		}

		virtual int initialize(){
			return 0;
		}
		virtual void dispose(){
		}

		void set(int r=255,int g=255,int b=255,int a=255){
			this->r = r;
			this->g = g;
			this->b = b;
			this->a = a;
		}

	public:
		const static Color White;
		const static Color Black;

		const static Color Red;
		const static Color Blue;
		const static Color Green;
	};
};