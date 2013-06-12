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


using namespace Cppie;

class TestScene2 : public Scene{
public:
	virtual int initialize(){
		return 0;
	}
	virtual void dispose(){
	}

	virtual void update(){
		printf("now in scene2!\n");
	}
};

Sprite *sakura[10];
	Layer *layer;

class Sakura : public DrawableObject{
	Sprite *sprite;
	float sx,sy,sa;
	float alpha;
	float x,y;
	float angle;

public:
	Sakura(int x,int y){
		initialize(x,y);
	}
	
	virtual int initialize(int x,int y){
		int n = rand()%8+1;

		this->x = x;
		this->y = y;
		sprite = sakura[n];
		
		sx = rand()%10 * 0.1 - 0.5;
		sy = rand()%10 * 0.1;
		sa = rand()%10 * 0.2;

		angle = 0;
		alpha = rand()%108;

		return 0;
	}

	virtual void update(){
		if (alpha <= 0) return;

		if(y < 460){
			x += sx;
			y += sy;
			angle += sa;
		}
		else{
			alpha -= 0.2;

		//	if (alpha <= 0)
			//	layer->remove(this);
				
		}

		sprite->alpha = alpha;
		sprite->angle = angle;
		sprite->stretch(x,y,24,24);
	}
};

class TestScene : public Scene{
	Sprite *bgi;
	SpriteNumber *num;
	GameObject *obj;

	Font *font;
	Texture *tex;

	Sound *sound;
	          
	RepeatedTask *task;

	Sprite *spr;
	AnimatedObject *aobj;
	int n;

	Window *w;

	ParticleGenerator *gen;

public :
	virtual int initialize(){
		Scene::initialize();

		bgi = new Sprite("cat.png",2,2);
		layer = new Layer();
		
		spr = new Sprite("orange.png",4,4);
		aobj = new AnimatedObject(100,100,
			spr, 50);

		w = new Window(0,0,50,50);

		font = new Font("c:\\windows\\fonts\\gulim.ttc");

		//font->color = Color::Red;
		font->alpha = 128;
		tex = new Texture("fire.png");

		
		spr->blend = CPPIE_BLENDMODE_ADD;
		gen = new FlowGenerator(220,400, spr);
		gen->activity = 80;
		

		return 0;
	}
	virtual void dispose(){
		Scene::dispose();
		printf("QWER");

		delete spr;
		delete tex;
		delete layer;
		delete aobj;
		delete font;
	}
	virtual void update(){
		Scene::update();

		graphic->color = Color::Black;
		graphic->clear();

		//bgi->step = 1;
		
		
		//bgi->draw(0,0);
		//tex->stretch(0,0,300,200);

		//spr->step = 3;

	spr->angle += 10;
		spr->draw(200,200);
		//spr->stretch(0,0,100,100);

		graphic->color = Color::Red;
		graphic->fillCircle(300,100,20);

		aobj->update();
		//spr->draw(0,0);
	}

	virtual void onLeftDown(int x,int y){
		printf("%d %d\n", x,y);

		Object o;

		o.dump();
		
	}
	virtual void onKeyDown(int key,bool repeated){
		printf(
			"qweqwe\n");
		aobj->repeat = false;
	}

	virtual void onKeyUp(int key,bool repeated){
		printf(
			"ertert\n");
		aobj->repeat = true;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{

	Cppie::initialize(840,640);
	Scene *scene = new TestScene;
	Cppie::scene->change(scene);

	Cppie::run();
	Cppie::quit();

	return 0;
}

