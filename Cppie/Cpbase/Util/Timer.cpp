#include "Timer.h"

#include "../Task/Task.h"

namespace Cppie{
	Timer::Timer(){
	}
	Timer::Timer(int interval){
		initialize(interval);
	}
	Timer::~Timer(){
		dispose();
	}

	int Timer::initialize(int interval){
		this->interval = interval;

		tick = 0;
		pauseTick = -1;

		return 0;
	}
	void Timer::dispose(){
	}

	void Timer::update(){
	}

	int Timer::getTicks(){
		return Cppie::getTicks() - tick;
	}

	void Timer::reset(){
		tick = Cppie::getTicks();
		pauseTick = -1;
	}
	bool Timer::done(){
		if(paused() || tick == 0) return false;

		if(getTicks() >= interval){
			reset();

			return true;
		}
		return false;
	}

	void Timer::start(){
		reset();
	}
	void Timer::stop(){
		tick = 0;
	}
	void Timer::pause(){
		pauseTick = Cppie::getTicks();
	}
	bool Timer::paused(){
		if(pauseTick == -1) return true;
		else return false;
	}
	void Timer::resume(){
		pauseTick = -1;

		tick += Cppie::getTicks() - pauseTick;
	}
};