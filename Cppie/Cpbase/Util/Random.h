#pragma once

#define CPPIE_TOSS_100(p)			rand()%100<p ? true : false
#define CPPIE_TOSS_1000(p)			rand()%100<p ? true : false
#define CPPIE_TOSS(p)				CPPIE_TOSS_100(p)

#define CPPIE_TOSS_EVENT_100(p,e)	CPPIE_TOSS_100(100-p) ? false : e
#define CPPIE_TOSS_EVENT_1000(p,e)	CPPIE_TOSS_1000(1000-p) ? false : e
#define CPPIE_TOSS_EVENT(p,e)		CPPIE_TOSS(100-p) ? false : e

namespace Cppie{
	
};