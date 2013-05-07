#include "SoundManager.h"

#include "../System/Core.h"

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