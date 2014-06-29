#include "BombObject.h"
#include "ObjectManager.h"

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
		//mSprite->getEventDispatcher()->dispatchCustomEvent("delete_sprite", (void*)this);
		ObjectManager::DeleteSprite(this);
	}
	mLastAccessTime = now;
}


