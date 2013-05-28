#include "SoundManager.h"

#include "../System/Core.h"

namespace Cppie{
	SoundManager::SoundManager(){
		initialize(CPPIE_SOUND_MAXCHANNELS);
	}
	SoundManager::SoundManager(int maxChannels){
		initialize(maxChannels);
	}
	SoundManager::~SoundManager(){
		if(system == nullptr){
			system->close();
			system->release();

			system = nullptr;
		}
	}

	int SoundManager::initialize(int maxChannels){
		int result;

		result = FMOD::System_Create(&system);

		if(result != 0){
			logger->error("Failed to create sound system - code : %d",
				result);

			return -1;
		}

		result = system->init(maxChannels, FMOD_INIT_NORMAL, 0);

		if(result != 0){
			logger->error("Failed to initialize sound system - code : %d",
				result);
			
			return -2;
		}

		volume = 50;

		logger->output("Sound system initialized");

		return 0;
	}
	void SoundManager::dispose(){
	}

	FMOD::System *SoundManager::getSystem(){
		return system;
	}

	void SoundManager::add(Sound *sound){
		o.push_back(sound);
	}
	void SoundManager::remove(Sound *sound){
		o.remove(sound);
	}

	void SoundManager::setVolume(int v){
		this->volume = v;

		std::list<Sound *>::iterator itor;
		for(itor=o.begin();itor!=o.end();++itor){
			int original = (*itor)->getVolume();
			(*itor)->setVolume(original);
		}
	}
	int SoundManager::getVolume(){
		return this->volume;
	}
};