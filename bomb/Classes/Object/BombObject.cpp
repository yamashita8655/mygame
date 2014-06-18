#include "BombObject.h"

USING_NS_CC;

BombObject::BombObject()
{
	timeval tv;
	gettimeofday(&tv, nullptr);
	mLastAccessTime = (tv.tv_sec) + (tv.tv_usec) * 1e-6;
	mRemainTime = 3.0f;
}

void BombObject::UpdateTime()
{
	timeval tv;
	gettimeofday(&tv, nullptr);
	float now = (tv.tv_sec) + (tv.tv_usec) * 1e-6;
	float diff = now - mLastAccessTime;

	mRemainTime -= diff;
	if(mRemainTime < 0)
	{
		mDispatcher->dispatchCustomEvent("removeBomb", (void*)this);
	}
	mLastAccessTime = now;
}

void BombObject::SetEventDispatcher(EventDispatcher* dispatcher)
{
     mDispatcher = dispatcher;
}

void BombObject::DeleteEventDispatcher()
{
	//mDispatcher->removeAllEventListeners();
}


