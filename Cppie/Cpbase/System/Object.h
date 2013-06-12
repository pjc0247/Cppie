#pragma once

#include "../Data/Color.h"
#include "../Graphic/BlendMode.h"	

#include "../Log/Log.h"

namespace Cppie{
	extern Log *logger;

	class Object{
	public:
		Object *parent;

	public:
		Object(){
			initialize();
		}
		virtual ~Object(){
			dispose();
		}

		virtual int initialize(){
			parent = nullptr;

			return 0;
		}
		virtual void dispose(){
		}

		virtual void update(){
		}

		virtual void dump(){
			logger->output("class : Object\n");
			logger->output("  memd : %x, (%db)", this, sizeof(Object));
			logger->output("");
			logger->output("  parent : %x", parent);
		}
	};
}