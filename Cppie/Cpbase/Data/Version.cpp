#include "Version.h"

namespace Cppie{
	Version::Version(){
		initialize();
	}
	Version::Version(char major,char minor,char fix){
		initialize(major, minor, fix);
	}
	Version::~Version(){
		dispose();
	}

	int Version::initialize(char major,char minor,char fix){
		set(major, minor, fix);
			
		return 0;
	}
	void Version::dispose(){
	}

	void Version::set(char major,char minor,char fix){
		this->major = major;
		this->minor = minor;
		this->fix = fix;
	}

	int Version::compareWith(Version *v){
		if(major > v->major)	return 1;
		if(major < v->major)	return -1;

		if(minor > v->minor)	return 1;
		if(minor < v->minor)	return -1;

		if(fix > v->fix)	return 1;
		if(fix < v->fix)	return -1;

		return 0;
	}
};