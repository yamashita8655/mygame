#ifndef __OBJECT_MANAGER_H__
#define __OBJECT_MANAGER_H__

#include "cocos2d.h"

USING_NS_CC;

class ObjectManager
{
public:
	static ObjectManager* getInstance();

private:
	ObjectManager(){}
	ObjectManager(const ObjectManager &other){}
	ObjectManager &operator=(const ObjectManager &other){}
	~ObjectManager(){};

public:
	void CreateSpriteFrameCache(const char* filename);
	Sprite* CreateSprite(const char* filename);

private:
};

#endif // __OBJECT_MANAGER_H__
