#ifndef __OBJECT_MANAGER_H__
#define __OBJECT_MANAGER_H__

#include "cocos2d.h"
#include "DrawObject.h"

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

	std::map<const char*, DrawObject*> mDrawObjectMap;
public:
	void CreateSpriteFrameCache(const char* filename);
	DrawObject* CreateDrawObject(const char* filename);

private:
};

#endif // __OBJECT_MANAGER_H__
