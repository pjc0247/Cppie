#include "SharedFont.h"

namespace Cppie{
	SharedFont::SharedFont(){
	}
	SharedFont::~SharedFont(){
	}

	int SharedFont::initialize(){
		return 0;
	}
	void SharedFont::dispose(){
		std::map<FontPair, Font*>::iterator itor;

		for(itor=map.begin();itor!=map.end();++itor){
			remove( 
				itor->first.first.c_str(), itor->first.second );
		}
	}

	void SharedFont::update(){
	}

	Font *SharedFont::get(const char *name, int size){
		Font *font;
		FontPair pair;
		std::string str;
		std::map<FontPair, Font*>::iterator itor;

		str = std::string(name);

		for(itor=map.begin();itor!=map.end();++itor){
			if(itor->first.first == str && 
				itor->first.second == size){
					return itor->second;
			}
		}

		font = new Font(name, size);

		return font;
	}
	void SharedFont::remove(const char *name, int size){
		FontPair pair;

		pair.first = std::string(name);
		pair.second = size;

		map.erase( map.find( pair ));
	}
};