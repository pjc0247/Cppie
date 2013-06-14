#include "FireParticle.h"

namespace Cppie{
	FireParticle::FireParticle(float x,float y,ParticleGenerator *gen){
		Particle::initialize(x,y, gen);
	}
	void FireParticle::setup(){
		direction = rand()%360;
		//angle = rand()%360;
		
		sx = rand()%100 * 0.01;
		sy = -1;

		alpha = 64;
		alphaStep = -0.5;

		scaleX = 1.5;
		scaleY = 1.5;

		lifeTime = 3000;
	}

	FireGenerator::FireGenerator(int x,int y,Sprite *sprite,int z){
		ParticleGenerator::initialize(x,y,sprite,z);
	}
	void FireGenerator::generate(){
		for(int i=0;i<rand()%7;i++){
			FireParticle *p;	

			p = new FireParticle(
				x+rand()%50-25,y+rand()%10-10, this);
			layer->add(p);
		}

		
	}
};