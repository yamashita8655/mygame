#ifndef __SPRITE_CREATOR_H__
#define __SPRITE_CREATOR_H__

#include "cocos2d.h"
#include <map>

USING_NS_CC;

class SpriteCreator
{
public:
	static SpriteCreator* getInstance();

private:
	SpriteCreator(){}
	SpriteCreator(const SpriteCreator &other){}
	SpriteCreator &operator=(const SpriteCreator &other){}
	~SpriteCreator(){};

public:
	Sprite* CreateSprite(const char* filename);
	Sprite* CreateSpriteFromFrameCache(const char* filename);
	void AddSpriteFrameCache(const char* filename);

private:
};

#endif // __SPRITE_CREATOR_H__
