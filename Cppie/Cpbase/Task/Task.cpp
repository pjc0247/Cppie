#include "Task.h"

namespace Cppie{

	void Delay(int ms){
		if(ms < 0) return;
		SDL_Delay(ms);
	}
};