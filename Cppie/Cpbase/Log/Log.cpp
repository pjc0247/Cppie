#include "Log.h"

#include <stdarg.h>

namespace Cppie{
	Log::Log(const char *file){
		if(file == nullptr)
			fp = nullptr;
		else
			fopen_s(&fp,file,"a");
	}
	Log::~Log(){
		dispose();
	}

	void Log::dispose(){
		if(fp != nullptr){
			fclose(fp);
		}
	}


	void Log::warn(const char *format, ...){
		char buffer[1024];
		va_list ap;
		int len;

		va_start(ap, format);
		len = vsprintf_s(buffer, format, ap);
		va_end(ap);

		sprintf_s(buffer,"[WARN] %s\n", buffer);

		log(buffer);
	}
	void Log::error(const char *format, ...){
		char buffer[1024];
		va_list ap;
		int len;

		va_start(ap, format);
		len = vsprintf_s(buffer, format, ap);
		va_end(ap);

		sprintf_s(buffer,"[ERROR] %s\n", buffer);

		log(buffer);
	}
	void Log::output(const char *format, ...){
		char buffer[1024];
		va_list ap;
		int len;

		va_start(ap, format);
		len = vsprintf_s(buffer, format, ap);
		va_end(ap);

		sprintf_s(buffer,"[LOG] %s\n", buffer);

		log(buffer);
	}

	void Log::log(const char *msg){
		printf(msg);
		if(fp != nullptr)
			fprintf(fp, msg);
	}
};