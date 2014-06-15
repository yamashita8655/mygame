#include "ObjectManager.h"

USING_NS_CC;

ObjectManager* ObjectManager::getInstance() 
{
    static ObjectManager instance;
    return &instance;
}

void ObjectManager::CreateSpriteFrameCache(const char* filename)
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(filename);
}

DrawObject* ObjectManager::CreateDrawObject(const char* filename)
{
	Sprite* sprite = Sprite::createWithSpriteFrameName(filename);
	DrawObject* obj = new DrawObject();
	std::pair<const char*, DrawObject*> p(filename, obj);
	mDrawObjectMap.insert(p);
	
	obj->SetSprite(sprite);
	return obj;
}
