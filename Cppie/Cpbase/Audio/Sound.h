#pragma once

#include "../System/Object.h"

#include <fmod.hpp>

namespace Cppie{

	class Sound : public Object{
	protected:
		FMOD::Sound      *sound;
		FMOD::Channel    *channel;

	public:
		Sound();
		Sound(const char *sound,bool loop=false);
		virtual ~Sound();

		virtual int initialize();
		virtual void dispose();

		bool play();
		bool Stop();
		bool pause();
		bool resume();

		bool paused();
		bool playing();

		int getVolume();
		void setVolume(int v);
	};
};