#include "SpriteCreator.h"

USING_NS_CC;

SpriteCreator* SpriteCreator::getInstance() 
{
    static SpriteCreator instance;
    return &instance;
}

void SpriteCreator::AddSpriteFrameCache(const char* filename)
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(filename);
}

Sprite* SpriteCreator::CreateSpriteFromFrameCache(const char* filename)
{
	Sprite* sprite = Sprite::createWithSpriteFrameName(filename);
	return sprite;
}

Sprite* SpriteCreator::CreateSprite(const char* filename)
{
	Sprite* sprite = Sprite::create(filename);
	return sprite;
}

