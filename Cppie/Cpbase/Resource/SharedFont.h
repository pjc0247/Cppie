#pragma once

#include "../TTF/Font.h"

#include "SharedResource.h"

#include <map>
#include <string>

typedef std::pair<std::string, int> FontPair;

namespace Cppie{
	class SharedFont : public SharedResource{
	public:
		std::map<FontPair, Font*> map;

	public:
		SharedFont();
		virtual ~SharedFont();

		virtual int initialize();
		virtual void dispose();

		virtual void update();

		Font *get(const char *name, int size);
		void remove(const char *name, int size);
	};
};