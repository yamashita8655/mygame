#include "TMXManager.h"
#include "TMXObject.h"

USING_NS_CC;

TMXManager* TMXManager::getInstance() 
{
    static TMXManager instance;
    return &instance;
}

TMXObject* TMXManager::CreateTMXObject(const char* filename)
{
	TMXObject* obj = new TMXObject();
	obj->Create(filename);
	std::pair<const char*, TMXObject*> p(filename, obj);
	mTMXObjectMap.insert(p);

	return obj;
}

