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
#pragma comment (lib,"fmodex_vc")
#pragma comment (lib,"opengl32")

#include "Cpbase/CpBase.h"

#include "Cpbase\/Input/Keyboard.h"

#include "Cpbase/Task/AsyncTask.h"
#include "Cpbase/Task/DelayedTask.h"

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

class TestScene : public Scene{
	Sprite *bgi;
	SpriteNumber *num;
	GameObject *obj;
	Layer *layer;

	Sound *sound;

	DelayedTask *task;

public :
	virtual int initialize(){
		Scene::initialize();

		bgi = new Sprite("cat.png");
		obj = new GameObject(0,0,bgi);

		num = new SpriteNumber("num.png");

		layer = new Layer(Z_UI);
		//layer->add(obj);

		Task t;
		t = CPPIE_TASK(
				while(1)
				printf("hello world\n");
			);

		task = new DelayedTask(
			CPPIE_TASK(
				while(1)
				printf("hello world\n");
			));

		task->run(3000);

		return 0;
	}
	virtual void dispose(){
		Scene::dispose();

		bgi->dispose();
	}
	virtual void update(){
		Scene::update();

	//	bgi->draw(0,0);

		num->draw(0,0,109123);

		if(keyboard->triggered(CPPIE_ESCAPE)){
			logger->output("space bar triggered\n");

			TestScene2 *new_scene = new TestScene2;
			scene->change(new_scene);
		}

	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	
	Cppie::initialize(480,320);
	Scene *scene = new TestScene;
	Cppie::scene->change(scene);
	Cppie::run();
	Cppie::quit();

	return 0;
}

