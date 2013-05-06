#include "SoundManager.h"

namespace Cppie{
	SoundManager::SoundManager(int maxChannels){
		FMOD::System_Create(&system);
		system->init(maxChannels, FMOD_INIT_NORMAL, 0);
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
};