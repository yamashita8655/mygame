#ifndef __TMX_MANAGER_H__
#define __TMX_MANAGER_H__

#include "cocos2d.h"

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

public:
	uint32_t GetTileId(TMXTiledMap* map, const char* layer_name, Touch* touch);
	uint32_t GetTileId(TMXTiledMap* map, TMXLayer* layer, Touch* touch);

private:
	int calcClickPoint(float touchpos, float tilesize);
};

#endif // __TMX_MANAGER_H__
