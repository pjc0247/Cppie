#include "Particle.h"

#include "../System/Core.h"

namespace Cppie{

	Sprite *par = nullptr;

	Particle::Particle(){
		initialize(0,0, nullptr);
	}
	Particle::Particle(float x,float y,ParticleGenerator *gen){
		initialize(x,y, gen);
	}
	Particle::~Particle(){
		dispose();
	}

	int Particle::initialize(float x,float y,ParticleGenerator *gen){
		GameObject::initialize(
			x,y, nullptr);

		visible = true;

		this->generator = gen;
		if(gen != nullptr)
			this->sprite = gen->sprite;

		sx = 0;
		sy = 0;

		alpha = 255;

		angleStep = 0;
		alphaStep = -1;
		direction = rand() % 360;
		lifeTime = 1000;
		speed = 1;

		scaleX = 1;
		scaleY = 1;

		startTick = getTicks();

		setup();

		return 0;
	}
	void Particle::dispose(){
	}

	void Particle::draw(float x,float y){
		sprite->alpha = alpha;
		sprite->angle = angle;
		sprite->color = color;
		sprite->step = step;
		
		sprite->stretch(x,y, 
			sprite->w * scaleX,
			sprite->h * scaleY);
	}
	void Particle::update(){
		GameObject::update();

		process();

		if(alpha <= 0 ||
			getTicks() - startTick >= lifeTime){
				delete this;
		}
	}

	void Particle::setup(){

	}
	void Particle::process(){
		x += sx * speed;
		y += sy * speed;
		alpha += alphaStep;
		angle += angleStep;

		step = (getTicks() - startTick) / (lifeTime / (sprite->wSlice * sprite->wSlice));
	}
};