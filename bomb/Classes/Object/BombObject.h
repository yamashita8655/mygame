#ifndef __BOMBOBJECT_H__
#define __BOMBOBJECT_H__

#include "cocos2d.h"
#include "DrawObject.h"

USING_NS_CC;

class  BombObject : public DrawObject
{
public:
	BombObject();
	void UpdateTime();
	void SetEventDispatcher(EventDispatcher* dispatcher);
	void DeleteEventDispatcher();

private:
	float mLastAccessTime;
	float mRemainTime;
    EventDispatcher* mDispatcher;
};

#endif // __DRAWOBJECT_H__
