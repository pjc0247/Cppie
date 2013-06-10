#pragma once

namespace Cppie{
	struct Event{
		unsigned char type;

		int key;
		int x,y;

		bool repeated;

		void *data1;
		void *data2;
	};
};