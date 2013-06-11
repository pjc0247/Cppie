#pragma once

#include "../GameObject/GameObject.h"
#include "../GameObject/ZOrder.h"
#include "../GameObject/Layer.h"

namespace Cppie{
	class ParticleGenerator : public GameObject{
	public:
		int activity;

		Layer *layer;

	public:
		ParticleGenerator(int x=0,int y=0,Sprite *sprite=nullptr,int z = CPPIE_Z_OBJECT);
		virtual ~ParticleGenerator();

		virtual int initialize(int x,int y,Sprite *sprite,int z=CPPIE_Z_OBJECT);
		virtual void dispose();

		virtual void update();

		virtual void generate();
	};
};