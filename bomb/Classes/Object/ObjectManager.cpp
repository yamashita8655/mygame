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

Sprite* ObjectManager::CreateSprite(const char* filename)
{
	Sprite* sprite = Sprite::createWithSpriteFrameName(filename);
	return sprite;
}
