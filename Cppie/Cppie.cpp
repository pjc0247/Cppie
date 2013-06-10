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

#include "Cpbase\/Input/Keyboard.h"

#include "Cpbase/Task/AsyncTask.h"
#include "Cpbase/Task/DelayedTask.h"
#include "Cpbase/Task/RepeatedTask.h"

#include "Cpbase/Util/Random.h"
#include "Cpbase/GameObject/AnimatedObject.h"

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

public :
	virtual int initialize(){
		Scene::initialize();

		bgi = new Sprite("cat.png",2,2);
		layer = new Layer();

		for(int i=1;i<9;i++){
			char msg[128];
			sprintf_s(msg,"sakura%d.png", i);
			sakura[i] = new Sprite(msg);
		}
		
		spr = new Sprite("bomb1.png",4,4);
		aobj = new AnimatedObject(0,0,
			spr, 50);

		task = new RepeatedTask(
				CPPIE_TASK(	
					CPPIE_TOSS_EVENT(100/7, layer->add(new Sakura(181,16)));
					CPPIE_TOSS_EVENT(100/7, layer->add(new Sakura(94,96)));
					CPPIE_TOSS_EVENT(100/7, layer->add(new Sakura(330,13)));
					CPPIE_TOSS_EVENT(100/7, layer->add(new Sakura(460,128)));
					CPPIE_TOSS_EVENT(100/7, layer->add(new Sakura(616,37)));
					CPPIE_TOSS_EVENT(100/7, layer->add(new Sakura(560,0)));
					CPPIE_TOSS_EVENT(100/7, layer->add(new Sakura(0,0)));
				));
		
		task->run();

		font = new Font("c:\\windows\\fonts\\gulim.ttc");

		//font->color = Color::Red;
		font->alpha = 128;
		tex = font->render("hello");

		return 0;
	}
	virtual void dispose(){
		Scene::dispose();

		bgi->dispose();
		task->dispose();
	}
	virtual void update(){
		Scene::update();

		bgi->step = 1;
		
		//bgi->draw(0,0);
		//tex->draw(0,0);

		aobj->update();
		//spr->draw(0,0);
	}

	virtual void onLeftDown(int x,int y){
		printf("%d %d\n", x,y);
		
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

