#pragma once

#include "../System/Manager.h"

#include "Scene.h"

namespace Cppie{
	class SceneManager : public ManagerObject{
	public:
		Scene *scene;

	public:
		SceneManager();
		virtual ~SceneManager();

		int initialize();
		void dispose();
		void update();

		int change(Scene *new_scene);
	};
}