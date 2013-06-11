#pragma once

#include "../GameObject/GameObject.h"

#include "ParticleGenerator.h"

namespace Cppie{
	class Particle : public GameObject{
	public:
		float sx,sy;
		float angleStep;
		float direction;
		float alpha, alphaStep;
		float speed;
		int lifeTime;
		int startTick;
		
		float scaleX, scaleY;

		ParticleGenerator *generator;

	public:
		Particle();
		Particle(float x,float y,ParticleGenerator *gen);
		virtual ~Particle();
		
		virtual int initialize(float x,float y,ParticleGenerator *gen);
		virtual void dispose();

		virtual void draw(float x,float y);
		virtual void update();

		virtual void setup();
		virtual void process();
	};
};