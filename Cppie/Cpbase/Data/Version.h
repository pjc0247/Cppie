#pragma once

#include "../System/Object.h"

namespace Cppie{
	class Version : public Object{
	public:
		char major;
		char minor;
		char fix;

	public:
		Version();
		virtual ~Version();

		virtual int initialize(char major=1,char minor=0,char fix=0);
		virtual void dispose();

		void set(char major=1,char minor=1,char fix=1);

		int compareWith(Version *v);
	};
};