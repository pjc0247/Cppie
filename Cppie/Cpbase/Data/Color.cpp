#pragma once

#include "Color.h"

namespace Cppie{
	const Color Color::White	= *(new Color(255,255,255));
	const Color Color::Black	= *(new Color(0,0,0));

	const Color Color::Red		= *(new Color(255,0,0));
	const Color Color::Blue		= *(new Color(0,255,0));
	const Color Color::Green	= *(new Color(0,0,255));
};