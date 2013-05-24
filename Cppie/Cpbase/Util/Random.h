#pragma once

/*
	CPPIE_TOSS_100(p)
		p%의 확률로 true를 반환하고, 나머지의 경우에는 false를 반환한다.

		p : 확률


	CPPIE_TOSS_1000(p)
		p/10%의 확률로 true를 반환하고, 나머지의 경우에는 false를 반환한다.

		p : 확률
*/
#define CPPIE_TOSS_100(p)			rand()%100<p ? true : false
#define CPPIE_TOSS_1000(p)			rand()%100<p ? true : false
#define CPPIE_TOSS(p)				CPPIE_TOSS_100(p)

/*
	CPPIE_TOSS_EVENT_100(p,e)
		p%의 확률로 e의 코드를 실행시킨다.

		p : 확률
		e : 실행 할 코드


		CPPIE_TOSS_EVENT_1000(p,e)
		p/10%의 확률로 e의 코드를 실행시킨다.

		p : 확률
		e : 실행 할 코드
*/
#define CPPIE_TOSS_EVENT_100(p,e)	CPPIE_TOSS_100(100-p) ? false : e
#define CPPIE_TOSS_EVENT_1000(p,e)	CPPIE_TOSS_1000(1000-p) ? false : e
#define CPPIE_TOSS_EVENT(p,e)		CPPIE_TOSS(100-p) ? false : e

namespace Cppie{
	
};