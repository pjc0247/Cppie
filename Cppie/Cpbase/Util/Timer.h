#pragma once

#include "../System/Object.h"

namespace Cppie{
	class Timer : public Object{
	public:
		int interval;

	private:
		int tick;
		int pauseTick;

	public:
		Timer();
		Timer(int interval);
		virtual ~Timer();

		virtual int initialize(int interval);
		virtual void dispose();

		virtual void update();

		bool done();

		void reset();

		void start();
		void stop();

		void pause();
		bool paused();
		void resume();

		int getTicks();
	};
};