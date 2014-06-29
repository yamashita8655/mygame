#ifndef __OBJECT_MANAGER_H__
#define __OBJECT_MANAGER_H__

#include "cocos2d.h"
#include "DrawObject.h"
#include "BombObject.h"
#include "TileData.h"

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

	std::map<std::string, DrawObject*> mDrawObjectMap;
	std::list<std::string> mDeleteObjectList;
	
	
public:
	BombObject* CreateBombObject(const char* filename, int x, int y);
	//void DeleteObject(int x, int y);
	void Update();
	
	void DeleteObjectList(std::string key);
	DrawObject* GetDrawObject(int x, int y);

	static void DeleteSprite(BombObject* bomb);

private:
};

#endif // __OBJECT_MANAGER_H__
