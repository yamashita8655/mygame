#ifndef __DRAWOBJECT_H__
#define __DRAWOBJECT_H__

#include "cocos2d.h"

USING_NS_CC;

class DrawObject
{
public:
	DrawObject();
	virtual ~DrawObject(){};
	Sprite* CreateSprite(const char* filename);

private:
	Sprite* mSprite;
};

#endif // __DRAWOBJECT_H__
