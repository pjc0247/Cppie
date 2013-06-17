#include "Sound.h"

#include "../System/Core.h"

#include "SoundManager.h"

namespace Cppie{

	Sound::Sound(){
	}
	Sound::Sound(const char *sound,bool loop){
		FMOD_RESULT result;

		this->sound = nullptr;
		this->channel = nullptr;

		if(loop)
			result = sndmgr->getSystem()->createSound(
				sound, FMOD_HARDWARE | FMOD_LOOP_NORMAL | FMOD_2D, NULL, &this->sound);
		else
			result = sndmgr->getSystem()->createSound(
				sound, FMOD_HARDWARE | FMOD_LOOP_OFF | FMOD_2D, NULL, &this->sound);

		if(result != 0){
			logger->error("Failed to open audio file - %s", sound);
			this->sound = nullptr;
		}
		else{
			sndmgr->add(this);
			logger->output("loaded : Sound(%x) - %s", this, sound);
		}
	}
	Sound::~Sound(){
		dispose();
	}

	int Sound::initialize(){
		return 0;
	}
	void Sound::dispose(){
		if(playing()){
			channel->stop();
		}
		if(sound != nullptr){
			sound->release();
		}

		sndmgr->remove(this);

		logger->output("disposed : Sound(%x)", this);
	}

	bool Sound::play(){
		FMOD_RESULT result;

		result = sndmgr->getSystem()->playSound(
			FMOD_CHANNEL_FREE, sound, false, &channel);

		if(result == 0)
			return true;
		else{
			logger->error("Failed to play sound - object : %x, code : %d",
				this, result);
			return false;
		}
	}
	bool Sound::Stop(){
		FMOD_RESULT result;

		result = channel->stop();
		channel = nullptr;

		if(result == 0)
			return true;
		else{
			logger->error("Failed to stop sound - object : %x, code : %d",
				this, result);
			return false;
		}
	}
	bool Sound::pause(){
		FMOD_RESULT result;

		result = channel->setPaused(true);
		
		if(result == 0)
			return true;
		else{
			logger->error("Failed to pause sound - object : %x, code : %d",
				this, result);
			return false;
		}
	}
	bool Sound::resume(){
		FMOD_RESULT result;

		result = channel->setPaused(false);
		
		if(result == 0)
			return true;
		else{
			logger->error("Failed to resume sound - object : %x, code : %d",
				this, result);
			return false;
		}
	}

	bool Sound::paused(){
		bool tmp;
		channel->getPaused(&tmp);

		return tmp;
	}
	bool Sound::playing(){
		bool tmp;
		channel->isPlaying(&tmp);

		return tmp;
	}

	int Sound::getVolume(){
		float tmp;
		channel->getVolume(&tmp);

		return static_cast<int>(tmp*100);
	}
	void Sound::setVolume(int v){
		float tmp;

		v = static_cast<float>(sndmgr->getVolume()) / 100 * v;

		tmp = (float)v;
		tmp /= 100;

		channel->setVolume(tmp);
	}
};