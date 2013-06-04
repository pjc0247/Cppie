#pragma once

#include "Color.h"
#include "Point.h"
#include "Rect.h"
#include "Size.h"
#include "Version.h"

namespace Cppie{
	Size cpSize(int w,int h);
	Rect cpRect(int x,int y,int w=1,int h=1);
	Point cpPoint(int x,int y);
	Color cpColor(int r,int g,int b,int a=255);
	Version cpVersion(char major=1,char minor=0,char fix=0);
};