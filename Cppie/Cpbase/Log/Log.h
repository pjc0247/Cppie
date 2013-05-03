#pragma once

#include <stdio.h>

namespace Cppie{
	class Log{
	public:
		FILE *fp;
	public:
		Log(const char *file = nullptr);
		virtual ~Log();

		int initialize(){}
		void dispose();

		void warn(const char *msg, ...);
		void error(const char *msg, ...);
		void output(const char *msg, ...);

	private:
		void log(const char *caption,const char *format);
	};
};