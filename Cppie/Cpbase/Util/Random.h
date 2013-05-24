#pragma once

/*
	CPPIE_TOSS_100(p)
		p%�� Ȯ���� true�� ��ȯ�ϰ�, �������� ��쿡�� false�� ��ȯ�Ѵ�.

		p : Ȯ��


	CPPIE_TOSS_1000(p)
		p/10%�� Ȯ���� true�� ��ȯ�ϰ�, �������� ��쿡�� false�� ��ȯ�Ѵ�.

		p : Ȯ��
*/
#define CPPIE_TOSS_100(p)			rand()%100<p ? true : false
#define CPPIE_TOSS_1000(p)			rand()%100<p ? true : false
#define CPPIE_TOSS(p)				CPPIE_TOSS_100(p)

/*
	CPPIE_TOSS_EVENT_100(p,e)
		p%�� Ȯ���� e�� �ڵ带 �����Ų��.

		p : Ȯ��
		e : ���� �� �ڵ�


		CPPIE_TOSS_EVENT_1000(p,e)
		p/10%�� Ȯ���� e�� �ڵ带 �����Ų��.

		p : Ȯ��
		e : ���� �� �ڵ�
*/
#define CPPIE_TOSS_EVENT_100(p,e)	CPPIE_TOSS_100(100-p) ? false : e
#define CPPIE_TOSS_EVENT_1000(p,e)	CPPIE_TOSS_1000(1000-p) ? false : e
#define CPPIE_TOSS_EVENT(p,e)		CPPIE_TOSS(100-p) ? false : e

namespace Cppie{
	
};