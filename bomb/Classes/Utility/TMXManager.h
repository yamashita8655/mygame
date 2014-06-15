#ifndef __TMX_MANAGER_H__
#define __TMX_MANAGER_H__

#include "cocos2d.h"
#include "TMXObject.h"
#include <map>

USING_NS_CC;

class TMXManager
{
public:
	static TMXManager* getInstance();

private:
	TMXManager(){}
	TMXManager(const TMXManager &other){}
	TMXManager &operator=(const TMXManager &other){}
	~TMXManager(){};

	std::map<const char*, TMXObject*> mTMXObjectMap;

public:
	TMXObject* CreateTMXObject(const char* filename);

private:
};

#endif // __TMX_MANAGER_H__
