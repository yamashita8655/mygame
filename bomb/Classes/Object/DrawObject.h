#ifndef __DRAWOBJECT_H__
#define __DRAWOBJECT_H__

#include "cocos2d.h"

USING_NS_CC;

class DrawObject
{
public:
	DrawObject();
	virtual ~DrawObject(){};
	
	void SetSprite(Sprite* sprite){ mSprite = sprite; }
	Sprite* GetSprite(){ return mSprite; }

	void SetKey(std::string key){ mKey = key; }
	std::string GetKey(){ return mKey; }
protected:
	std::string mKey;
	Sprite* mSprite;
};

#endif // __DRAWOBJECT_H__
