// Cppie.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
	Sprite *bgi, *src;
	GameObject *obj;
	Layer *layer;

	Sound *sound;

public :
	virtual int initialize(){
		Scene::initialize();

		bgi = new Sprite("out.png");
		obj = new GameObject(0,0,bgi);

		src = new Sprite("src.png");

		Rect rect;
		rect.set(0,0,src->w, src->h);
		printf("%d %d\n", src->w, src->h);
		graphic->setSize(rect);
		
	//	obj->color.set(255,128,2);

		layer = new Layer(Z_UI);
		//layer->add(obj);

		return 0;
	}
	virtual void dispose(){
		Scene::dispose();

		bgi->dispose();
	}
	virtual void update(){
		Scene::update();

		src->draw(0,0);
		bgi->draw(0,0);

		if(keyboard->triggered(CPPIE_ESCAPE)){
			logger->output("space bar triggered\n");
		}

	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	
	Cppie::initialize(40,40);
	Scene *scene = new TestScene;
	Cppie::scene->change(scene);
	Cppie::run();
	Cppie::quit();

	return 0;
}

