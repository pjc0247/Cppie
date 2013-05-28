#pragma once

#include "../System/Object.h"
#include "Sound.h"

#include <fmod.hpp>
#include <list>

#define CPPIE_SOUND_MAXCHANNELS 32

namespace Cppie{

	class SoundManager : public Object {
	private:
		FMOD::System *system;
		
		std::list<Sound *> o;

		int volume;
	public:
		SoundManager();
		SoundManager(int maxChannels);
		virtual ~SoundManager();

		virtual int initialize(int maxChannels);
		virtual void dispose();

		void add(Sound *sound);
		void remove(Sound *sound);

		void setVolume(int v);
		int getVolume();

		FMOD::System *getSystem();
	};
};