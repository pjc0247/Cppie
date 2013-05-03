#pragma once

#include "../System/Object.h"

#define CPPIE_MOUSEBUTTON_LEFT			0
#define CPPIE_MOUSEBUTTON_RIGHT			1
#define CPPIE_MOUSEBUTTON_WHEEL			2

#define CPPIE_MOUSESTATE_DOWN		true
#define CPPIE_MOUSESTATE_UP			false

#define CPPIE_MOUSEBUFFER_LENGTH	3
#define CPPIE_MOUSEBUFFER_SIZE		sizeof(int)*CPPIE_MOUSEBUFFER_LENGTH

namespace Cppie{
	class Mouse : public Object{
	public:
		int x,y;
	private:
		bool mousebuffer[CPPIE_MOUSEBUFFER_LENGTH];

	public:

		Mouse();
		virtual ~Mouse();

		virtual void update();

		void setState(int button,bool state);
		bool getState(int button);
	};
};