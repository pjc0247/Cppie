#pragma once

#include "../System/object.h"
#include "Scene.h"

namespace Cppie{
	class SceneManager : public Object{
		Scene *scene;

	public:
		SceneManager();
		~SceneManager();

		int initialize();
		void dispose();
		void update();

		int change(Scene *new_scene);
	};
}