#include "SoundManager.h"

namespace Cppie{
	SoundManager::SoundManager(int maxChannels){
		FMOD::System_Create(&system);
		system->init(maxChannels, FMOD_INIT_NORMAL, 0);

		volume = 50;
	}
	SoundManager::~SoundManager(){
		if(system == nullptr){
			system->close();
			system->release();

			system = nullptr;
		}
	}

	int SoundManager::initialize(){
		return 0;
	}
	void SoundManager::dispose(){
	}

	FMOD::System *SoundManager::getSystem(){
		return system;
	}

	void SoundManager::setVolume(int v){
		this->volume = v;
	}
	int SoundManager::getVolume(){
		return this->volume;
	}
};