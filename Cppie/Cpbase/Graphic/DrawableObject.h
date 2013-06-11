#pragma onces

#include "../System/Object.h"
#include "../Data/Color.h"

namespace Cppie{
	
	class DrawableObject : public Object{
	public:
		Color color;
		BlendMode blend;
		int alpha;

	public:
		DrawableObject(){
			color = Color::White;
			blend = CPPIE_BLENDMODE_BLEND;	
			alpha = 255;
		}
		virtual ~DrawableObject(){
		}

		virtual void update(){
		}
		virtual void draw(int x=0,int y=0){
		}
	};
};
};