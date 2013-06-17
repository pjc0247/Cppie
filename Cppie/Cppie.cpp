// Cppie.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#pragma once

#include <stdio.h>
#include <tchar.h>
#include <string.h>

#include <math.h>

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


#include "bmsparser.hpp"

using namespace Cppie;

class Flare : public AnimatedObject{
public:
	virtual void update(){
	}
};

struct MeasureData{
	int data[64];
	int len;
	int cursor;
	int tick;
};

class TestScene : public Scene {
protected:
	Texture *gearTex;

	Texture *gear, *inner_gear;
	Texture *hpbar;

	Texture *autoLine, *red, *blue;
	Texture *cd;

	Sprite *note_blue;
	Sprite *note_red;

	Texture *album;

	Sprite *flare1;

	Texture *glow;

	Texture *judgePanel;
	Texture *judge[5][3];
	Font *judgeFont;

	Layer *layerEffect;

	FireGenerator *gen;
	FlowGenerator *fgen;
	Sprite *par;


	Sound *keySound[2056];

	BMSHEADERSECTION bms_header;
	BMSDATASECTION bms_data;
	
	CHANNEL2QUEUE cq2;

	CHANNELQUEUE chBgs;
	CHANNELQUEUE chNote[50];

	CHANNELQUEUE::QueueNode *node;

	int hp;
	int hpbar_h;

	int pressed[7];
	int judgePanelType;
	int judgePanelAni;

	int measure;
	int measureTick;

	float measureDuration;
	
	MeasureData measureData[8];
public:

	virtual int initialize(){

		BmsParser::LoadFromFile("bms\\flower\\FLOWER [1N tricoro].bme", bms_header, bms_data);

		printf("%s \n", bms_header.artist);

		for(int i=0;i<2056;i++){
			if(strlen(bms_header.wav[i])){
				char path[256];
				sprintf_s(path, "bms\\flower\\%s", bms_header.wav[i]);
				keySound[i] = new Sound(path, false);

				if(keySound[i] == nullptr)
					abort();
			}
		}

		bms_data.GetChannelQueue(1,chBgs);

		for(int i=0;i<20;i++){
			bms_data.GetChannelQueue(11+i,chNote[i]);
			printf("%d\n", chNote[i].queue_count);
		}
		
		bms_data.GetChannel2Queue(cq2);

		
	

		CHANNEL2QUEUE::QueueNode2 *node2;

		parseMeasure();
		node2 = cq2.dequeue();
		

		printf("%s\n", bms_header.bmp[1]);

		gearTex = new Texture(200,580);

		album = new Texture("album.png");

		gear = new Texture("gear.png");
		inner_gear = new Texture("gear_inner.png");
		inner_gear->alpha = 128;

		hpbar = new Texture("hpbar.png");

		autoLine = new Texture("auto.png");
		autoLine->blend = CPPIE_BLENDMODE_ADD;

		red = new Texture("red.png");
		blue = new Texture("blue.png");
		red->blend = CPPIE_BLENDMODE_ADD;
		blue->blend = CPPIE_BLENDMODE_ADD;

		note_blue = new Sprite("note_silver.png", 1,4);
		note_red = new Sprite("note_blue.png", 1,4);

		cd = new Texture("Cd.png");
		cd->blend = CPPIE_BLENDMODE_ADD;

		flare1 = new Sprite("flare1.png", 6,1);
		flare1->blend = CPPIE_BLENDMODE_ADD;

		glow = new Texture("bigglow3.bmp");
		glow->blend = CPPIE_BLENDMODE_MOD;

		judgePanel = new Texture(200,150);

		judgeFont = new Font("CooperBlackStd-Italic.otf", 30);
		
		judgeFont->color = cpColor(255,255,255);
		judge[4][2] = judgeFont->render("Miss");
		judgeFont->color = cpColor(255,0,0);
		judge[4][0] = judgeFont->render("Miss");
		judgeFont->color = cpColor(64,64,64);
		judge[4][1] = judgeFont->render("Miss");
		judge[4][1]->alpha = 128;

		par = new Sprite("orange.png", 4,4);
		par->blend = CPPIE_BLENDMODE_ADD;

		layerEffect = new Layer(CPPIE_Z_OBJECT);

		for(int i=0;i<860/70;i++){
			gen = new FireGenerator(i*70,590, par);
			gen->activity = 10;
		}

		memset(pressed, 0, sizeof(int) * 7);
		judgePanelType = 0;
		judgePanelAni = 0;
		measure = 0;
		measureTick = getTicks();
		measureDuration = 240.0f/ bms_header.bpm * 1000;

		printf("duration : %f\n", measureDuration);	
		//abort();

		for(int i=0;i<20;i++){
			measureData[i+1].cursor = 0;
			measureData[i+1].tick = getTicks();
			measureData[i+1].len = 0;
		}

		hp = 100;

		

		return 0;
	}
	virtual void dispose(){
		delete judgePanel;
	}

	void draw(){
		//album->stretch(0,0,860,600);
		graphic->color = Color::Black;
		graphic->clear();

		inner_gear->draw(26,0);

		gear->draw(0,0);
		cd->draw(8,483);

		hpbar->stretch(
			231,118+hpbar_h, 12, 359-hpbar_h,
			0,hpbar_h,12,359);

		autoLine->color.r = cos(getTicks()/60) * 123+122;
		autoLine->color.g = cos(getTicks()/60) * 123+122;
		autoLine->draw(30,0);
		for(int i=0;i<7;i++){
			if(pressed[i]){
				Texture *target;
				if(i % 2 == 0) target = red;
				else target = blue;

				target->alpha = pressed[i];
				target->draw(60+i*24,0);
				target->draw(60+i*24,0);

				pressed[i] -= 5;
			}
		}

		graphic->setRenderTarget(judgePanel);
		SDL_SetRenderDrawColor(renderer, 0,0,0,0);
		SDL_RenderClear(renderer);

		int wSize;
		int hSize;

		
		wSize = judge[4][1]->w * 0.1 * (judgePanelAni < 10 ? judgePanelAni : 10);
		hSize = judge[4][1]->h * 0.1 * (judgePanelAni < 10 ? judgePanelAni : 10);

		judge[4][1]->stretch(
			-wSize/2+100+3, hSize/2+30+2,
			wSize,hSize);
		judge[4][0]->stretch(
			-wSize/2+100, hSize/2+30,
			wSize,hSize);
		glow->blend = CPPIE_BLENDMODE_MOD;
		glow->draw(100-judgePanelAni*3,20);

		graphic->setRenderTarget(CPPIE_RENDERTARGET_WINDOW);

		judgePanel->draw(20,300);

		note_blue->draw(100,200);
		note_red->draw(100,300);

		

		album->stretch(280,50,520,450);

		graphic->color = Color::Red;
		graphic->line(50,470,225,470);

	}
	virtual void update(){
		cd->angle += 10;

		if(judgePanelAni > 0){
			judgePanelAni ++;
			if(judgePanelAni >= 20){
				judgePanelAni = 0;
			}
		}

		inner_gear->alpha = cos(getTicks()/60) * 30+128;
		hpbar_h = cos(getTicks()/60) * 10+128;

		if(getTicks() - measureTick >= measureDuration){
			measure ++;	
			measureTick = getTicks();

			parseMeasure();

			printf("Measure ++ ( current :%d )\n\n", measure);
		}

		for(int i=0;i<21;i++){
			if(measureData[i].len > 0){
				if(getTicks() - measureData[i].tick >= measureDuration / measureData[i].len){
					printf("  - tick %d\n", i);

					measureData[i].tick = getTicks();
					measureData[i].cursor ++;

					if(measureData[i].data[measureData[i].cursor] != 0){
						printf("play wav %d, %s\n", 
							measureData[i].data[measureData[i].cursor],
							bms_header.wav[measureData[i].data[measureData[i].cursor]]);
						keySound[
							measureData[i].data[measureData[i].cursor]]->play();
					}
				}
			}
		}

		//keySound[1]->setVolume(10);
		//keySound[1]->pause();
		draw();
	}

	void parseChannel(int idx){
		CHANNELQUEUE::QueueNode *node;
		CHANNELQUEUE *q;

		if(idx == 0) q = &chBgs;
		else q = &chNote[idx-1];

		node = q->dequeue();

		measureData[idx].cursor = 0;
		measureData[idx].tick = getTicks();

		if(node == nullptr){
			printf("node is null\n");
			return;
		}

		printf("Parse %d\n", idx);

		measureData[idx].len = node->data_ary.size();
		printf("length : %d\n", measureData[idx].len);

		printf("data : ");
		for(int i=0;i<measureData[idx].len;i++){
			measureData[idx].data[i] = node->data_ary[i];
			printf("%d ", node->data_ary[i]);
		}
		printf("\n");

		if(measureData[idx].len > 0 && measureData[idx].data[0] != 0){
			printf("play %s\n",bms_header.wav[measureData[idx].data[0]]);
			keySound[measureData[idx].data[0]]->play();
		}
	}
	void parseMeasure(){

		parseChannel(0);
		for(int i=0;i<20;i++)
			parseChannel(i+1);
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

		judgePanelAni = 1;
		//layerEffect->add(new EffectObject(200,230, judge[4]));

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

