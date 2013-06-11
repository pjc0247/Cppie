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
			
		}
		virtual ~DrawableObject(){
		}

		virtual int initialize();

		virtual void draw(int x=0,int y=0);
	};
};
};