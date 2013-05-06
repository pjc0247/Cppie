#pragma once

#include "Sound.h"

namespace Cppie{

	class SoundStream : public Sound{
	public:
		SoundStream();
		SoundStream(const char *sound,bool loop=false);
	};
};