#include "FilePath.h"

#include <string.h>

namespace Cppie{
	void makeLinuxPath(const char *src,char *dst){
		int srcLen;
		int srcCur, dstCur;

		srcLen = strlen(src);

		srcCur = 0;
		dstCur = 0;

		while(srcCur < srcLen){
			if(src[srcCur] == '\\')
				dst[dstCur] = '/';
			else
				dst[dstCur] = src[srcCur];

			dstCur ++;
			srcCur ++;
		}
	}
	void makeWindowsPath(const char *src,char *dst){
		int srcLen;
		int srcCur, dstCur;

		srcLen = strlen(src);

		srcCur = 0;
		dstCur = 0;

		while(srcCur < srcLen){
			if(src[srcCur] == '/')
				dst[dstCur] = '\\';
			else
				dst[dstCur] = src[srcCur];

			dstCur ++;
			srcCur ++;
		}
	}
};