#pragma once

#include "../System/object.h"
#include "Scene.h"

namespace Cppie{
	class SceneManager : public Object{
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