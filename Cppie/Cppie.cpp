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

using namespace Cppie;

class TestScene : public Scene{
	Sprite *bgi;
	GameObject *obj;
	Layer *layer;

	Sound *sound;

public :
	virtual int initialize(){
		Scene::initialize();

		bgi = new Sprite("cat.png");
		obj = new GameObject(0,0,bgi);

		
	//	obj->color.set(255,128,2);

		layer = new Layer(Z_UI);
		layer->add(obj);

		return 0;
	}
	virtual void dispose(){
		Scene::dispose();

		bgi->dispose();
	}
	virtual void update(){
		Scene::update();

		bgi->draw(0,0);

		if(keyboard->triggered(CPPIE_ESCAPE)){
			logger->output("space bar triggered\n");
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

