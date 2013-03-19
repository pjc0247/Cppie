#pragma once

#include "SceneManager.h"

namespace Cppie{
	SceneManager::SceneManager(){
		scene = nullptr;
	}
	SceneManager::~SceneManager(){
	}

	int SceneManager::initialize(){
		return 0;
	}
	void SceneManager::dispose(){
		if(scene != nullptr)
			scene->dispose();
	}
	void SceneManager::update(){
		if(scene != nullptr)
			scene->update();
	}

	int SceneManager::change(Scene *new_scene){
		Scene *old_scene = scene;

		if(old_scene != nullptr){
			old_scene->dispose();
		}

		scene = new_scene;
		return scene->initialize();
	}
};
