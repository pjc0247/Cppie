#pragma once

#include "Particle.h"
#include "ParticleGenerator.h"

namespace Cppie{
	class FireParticle : public Particle{
	public:
		FireParticle(float x,float y,ParticleGenerator *gen);

		virtual void setup();
	};

	class FireGenerator : public ParticleGenerator{
	public:
		FireGenerator(int x,int y,Sprite *sprite,int z = CPPIE_Z_OBJECT);

		virtual void generate();
	};
};