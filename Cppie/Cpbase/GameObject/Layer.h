#pragma once

#include "../System/Object.h"
#include "ZOrder.h"

#include <vector>

namespace Cppie{
	class Layer : public Object{
	public:
		float z;
		std::vector<Object *> o;

	protected:
		//std::list<Object *>::iterator itor;
		bool updating;

	public:
		Layer(float z = CPPIE_Z_OBJECT);
		virtual ~Layer();

		virtual void update();
		void add(Object *obj);
		void remove(Object *obj);
	};
};