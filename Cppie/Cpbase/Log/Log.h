#pragma once

#include <stdio.h>

namespace Cppie{
	class Log{
	public:
		FILE *fp;
	public:
		Log(const char *file = nullptr);
		~Log();

		int initialize(){}
		void dispose();

		void output(const char *msg, ...);
	};
};