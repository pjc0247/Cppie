#pragma once

#include "../System/Object.h"
#include "Sound.h"

#include <fmod.hpp>

#define CPPIE_SOUND_MAXCHANNELS 32

namespace Cppie{

	class SoundManager : public Object {
	private:
		FMOD::System *system;

	public:
		SoundManager(int maxChannels);
		virtual ~SoundManager();

		virtual int initialize();
		virtual void dispose();

		FMOD::System *getSystem();
	};
};