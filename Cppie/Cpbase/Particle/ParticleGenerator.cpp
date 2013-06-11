#include "ParticleGenerator.h"

#include "../Util/Random.h"

#include "Particle.h"

namespace Cppie{
	ParticleGenerator::ParticleGenerator(int x,int y,Sprite *sprite,int z){
		initialize(x,y, sprite, z);
	}
	ParticleGenerator::~ParticleGenerator(){
		dispose();
	}

	int ParticleGenerator::initialize(int x,int y,Sprite *sprite,int z){
		GameObject::initialize(x,y, sprite);

		activity = 100;

		layer = new Layer(z);

		layer->add(this);

		return 0;
	}
	void ParticleGenerator::dispose(){
		delete layer;
	}

	void ParticleGenerator::update(){
		if(CPPIE_TOSS_100(activity)){
			generate();
		}
	}

	void ParticleGenerator::generate(){
		Particle *p;
		p = new Particle(x,y, this);
		
		layer->add(p);
	}
};