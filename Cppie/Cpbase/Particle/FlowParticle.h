#pragma once

#include "Particle.h"
#include "ParticleGenerator.h"

namespace Cppie{
	class FlowParticle : public Particle{
	public:
		FlowParticle(float x,float y,ParticleGenerator *gen);

		virtual void setup();
	};

	class FlowGenerator : public ParticleGenerator{
	public:
		FlowGenerator(int x,int y,Sprite *sprite,int z = CPPIE_Z_OBJECT);

		virtual void generate();
	};
};