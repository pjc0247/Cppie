#pragma once

namespace Cppie{
	struct Event{
		unsigned int type;

		int key;
		int x,y;

		bool repeated;

		void *data1;
		void *data2;
	};
};