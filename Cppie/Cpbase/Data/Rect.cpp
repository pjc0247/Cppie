#include "Rect.h"

namespace Cppie{
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