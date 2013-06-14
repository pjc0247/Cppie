// Cppie.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#pragma once

#include <stdio.h>
#include <tchar.h>
#include <string.h>

#include <sdl.h>
#include <sdl_gdiplus.h>
#pragma comment (lib,"sdl")
#pragma comment (lib,"sdl_gdiplus")
#pragma comment (lib,"sdl_ttf")
#pragma comment (lib,"fmodex_vc")
#pragma comment (lib,"opengl32")

#include "Cpbase/CpBase.h"

#include "Cpbase/Particle/ParticleGenerator.h"
#include "Cpbase/Particle/Particle.h"
#include "Cpbase/Particle/FlowParticle.h"
#include "Cpbase/Particle/FireParticle.h"


#include "Cpbase/GameObject/EffectObject.h"


using namespace Cppie;

class Flare : public AnimatedObject{
public:
	virtual void update(){
	}
};

class TestScene : public Scene {
protected:
	Texture *gear;
	Texture *red, *blue;
	Texture *cd;

	Sprite *flare1;

	Layer *layerEffect;

	FireGenerator *gen;
	Sprite *par;

	int pressed[7];
public:
	virtual int initialize(){
		gear = new Texture("gear.png");

		red = new Texture("red.png");
		blue = new Texture("blue.png");
		red->blend = CPPIE_BLENDMODE_ADD;
		blue->blend = CPPIE_BLENDMODE_ADD;

		cd = new Texture("Cd.png");
		cd->blend = CPPIE_BLENDMODE_ADD;
		
		flare1 = new Sprite("flare1.png", 6,1);
		flare1->blend = CPPIE_BLENDMODE_ADD;

		par = new Sprite("orange.png", 4,4);
		par->blend = CPPIE_BLENDMODE_ADD;

		layerEffect = new Layer(CPPIE_Z_OBJECT);

		memset(pressed, 0, sizeof(int) * 7);

		gen = new FireGenerator(80,460, par);
		gen->activity = 30;

		gen = new FireGenerator(150,460, par);
		gen->activity = 30;

		gen = new FireGenerator(220,460, par);
		gen->activity = 30;

		SDL_SetRenderTarget();

		return 0;
	}
	virtual void dispose(){
	}
	virtual void update(){
		graphic->color = Color::Black;
		graphic->clear();

		cd->angle += 10;

		gear->draw(0,0);
		cd->draw(8,483);
		for(int i=0;i<7;i++){
			if(pressed[i]){
				Texture *target;
				if(i % 2 == 0) target = red;
				else target = blue;

				target->alpha = pressed[i];
				target->draw(60+i*24,0);

				pressed[i] -= 5;
			}
		}

		graphic->color = Color::Red;
		graphic->line(50,470,225,470);
	}

	virtual void onKeyDown(int key,bool repeated){
		if(repeated) return ;

		int idx = -1;

		switch(key){
		case CPPIE_a:
				idx = 0;
			break;
		case CPPIE_s:
				idx = 1;
			break;
		case CPPIE_d:
				idx = 2;
			break;

		case CPPIE_SPACE:
				idx = 3;
			break;

		case CPPIE_j:
				idx = 4;
			break;
		case CPPIE_k:
				idx = 5;
			break;
		case CPPIE_l:
				idx = 6;
			break;
		}

		if(idx == -1) return;

		pressed[idx] = 255;
		layerEffect->add(new EffectObject(22+idx*24,430, flare1));

	}
	virtual void onKeyUp(int key,bool repeated){
	}
};

int _tmain(int argc, _TCHAR* argv[])
{

	Cppie::initialize(840,600);
	Scene *scene = new TestScene;
	Cppie::scene->change(scene);

	Cppie::run();
	Cppie::quit();

	return 0;
}

