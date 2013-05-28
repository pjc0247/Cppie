#pragma once

namespace Cppie{
	struct Event{
		unsigned char type;

		int key;
		int x,y;

		void *data1;
		void *data2;
	};
};