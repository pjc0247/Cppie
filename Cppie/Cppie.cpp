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
#pragma comment (lib,"opengl32")

#include "Cpbase/CpBase.h"

using namespace Cppie;

class TestScene : public Scene{
	Sprite *bgi;
	GameObject *obj;
	Layer *layer;
public :
	virtual int initialize(){
		Scene::initialize();

		bgi = new Sprite("cat.png");
		obj = new GameObject(0,0,bgi);
		
		layer = new Layer(Z_UI);
		layer->add(obj);

		objmgr->add(layer);

		return 0;
	}
	virtual void dispose(){
		Scene::dispose();

		bgi->dispose();
	}
	virtual void update(){
		Scene::update();

		//bgi->draw(0,0);
		objmgr->update();

		graphic->line(0,0,100,100);
		
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Cppie::initialize();
	Scene *scene = new TestScene;
	Cppie::scene->change(scene);
	Cppie::run();
	Cppie::quit();

	return 0;
}

