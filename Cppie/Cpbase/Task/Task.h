#pragma once

#include "../System/Object.h"


#define CPPIE_TASK(code)		[&](){code}
#define CPPIE_SAFE_TASK(code)	[=](){code}
typedef function<void()>		Task;

#define CPPIE_TASK_IMMEDIATE	0
#define CPPIE_TASK_NEXT_LOOP	0

namespace Cppie{

	void Delay(int ms);
};