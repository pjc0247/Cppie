#include "SoundStream.h"

#include "../System/Core.h"

namespace Cppie{

	SoundStream::SoundStream(){
	}
	SoundStream::SoundStream(const char *sound,bool loop){
		FMOD_RESULT result;

		this->sound = nullptr;
		this->channel = nullptr;

		result = sndmgr->getSystem()->createStream(
			sound, FMOD_HARDWARE | FMOD_LOOP_NORMAL | FMOD_2D, NULL, &this->sound);

		if(result != 0){
			logger->error("Failed to open audio file - %s", sound);
			this->sound = nullptr;
		}
		else{
			sndmgr->add(this);
			logger->output("loaded : Sound(%x) - %s", this, sound);
		}
	}
};