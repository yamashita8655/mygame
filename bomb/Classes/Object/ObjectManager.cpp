#include "ObjectManager.h"


USING_NS_CC;

int uid = 0;

ObjectManager* ObjectManager::getInstance() 
{
    static ObjectManager instance;
    return &instance;
}

//DrawObject* ObjectManager::CreateDrawObject(const char* filename)
//{
//	Sprite* sprite = Sprite::createWithSpriteFrameName(filename);
//	DrawObject* obj = new DrawObject();
//	std::pair<const char*, DrawObject*> p(filename, obj);
//	mDrawObjectMap.insert(p);
//	
//	obj->SetSprite(sprite);
//	obj->SetName(filename);
//	return obj;
//}

BombObject* ObjectManager::CreateBombObject(const char* filename, int x, int y)
{
	Sprite* sprite = Sprite::createWithSpriteFrameName(filename);
	BombObject* obj = new BombObject();
	obj->SetSprite(sprite);
	std::string xstr = std::to_string(x);
	std::string ystr = std::to_string(y);
	std::string key = xstr + ystr;
	obj->SetKey(key);
	
	std::pair<std::string, DrawObject*> p(key, obj);
	mDrawObjectMap.insert(p);
	
	return obj;
}

//void ObjectManager::DeleteObject(int x, int y)
//{
//	std::string xstr = std::to_string(x);
//	std::string ystr = std::to_string(y);
//	std::string key = xstr + ystr;
//	mDrawObjectMap.erase(key);
//}

void ObjectManager::Update()
{
	std::map<std::string, DrawObject*>::iterator it;
	for(it = mDrawObjectMap.begin(); it != mDrawObjectMap.end(); it++)
	{
		BombObject* bomb = (BombObject*)it->second;
		bomb->UpdateTime();
	}
	
	std::list<std::string>::iterator listit;
	for(listit = mDeleteObjectList.begin(); listit != mDeleteObjectList.end(); listit++)
	{
		std::string key = *listit;
		mDrawObjectMap.erase(key);
	}

	mDeleteObjectList.clear();
}

void ObjectManager::DeleteObjectList(std::string key)
{
	mDeleteObjectList.push_back(key);
}

DrawObject* ObjectManager::GetDrawObject(int x, int y)
{
	std::string xstr = std::to_string(x);
	std::string ystr = std::to_string(y);
	std::string key = xstr + ystr;

	std::map<std::string, DrawObject*>::iterator it = mDrawObjectMap.find(key);

	// マップが end では無い場合（つまりキーにヒットする値が存在した場合）
	if (it != mDrawObjectMap.end()) 
	{
		return it->second;
	}
	else
	{
		return nullptr;
	}
}
