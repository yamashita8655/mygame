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

private:
	float mLastAccessTime;
	float mRemainTime;
};

#endif // __DRAWOBJECT_H__
