#include "FlowParticle.h"

namespace Cppie{
	FlowParticle::FlowParticle(float x,float y,ParticleGenerator *gen){
		Particle::initialize(x,y, gen);
	}
	void FlowParticle::setup(){
		direction = rand()%360;
		angle = rand()%360;
		angleStep = 30;

		sx = cos(180/3.14 * direction) * 1;
		sy = sin(180/3.14 * direction) * 1;
	}

	FlowGenerator::FlowGenerator(int x,int y,Sprite *sprite,int z){
		ParticleGenerator::initialize(x,y,sprite,z);
	}
	void FlowGenerator::generate(){
		FlowParticle *p;
		p = new FlowParticle(x,y, this);

		layer->add(p);
	}
};