#include "DrawObject.h"

USING_NS_CC;

DrawObject::DrawObject()
	:mSprite(nullptr)
{
	
}

Sprite* DrawObject::CreateSprite(const char* filename)
{
	mSprite = Sprite::create(filename);
	return mSprite;
}

//TMXManager* TMXManager::getInstance() 
//{
//    static TMXManager instance;
//    return &instance;
//}

