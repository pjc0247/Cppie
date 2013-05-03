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

		log("WARN", buffer);
	}
	void Log::error(const char *format, ...){
		char buffer[1024];
		va_list ap;
		int len;

		va_start(ap, format);
		len = vsprintf_s(buffer, format, ap);
		va_end(ap);

		log("ERROR", buffer);
	}
	void Log::output(const char *format, ...){
		char buffer[1024];
		va_list ap;
		int len;

		va_start(ap, format);
		len = vsprintf_s(buffer, format, ap);
		va_end(ap);

		log("LOG", buffer);
	}

	void Log::log(const char *caption, const char *msg){
		char buffer[1024];

		sprintf_s(buffer, "[%s] %s\n", caption, msg);

		printf(buffer);
		if(fp != nullptr)
			fprintf(fp, buffer);
	}
};