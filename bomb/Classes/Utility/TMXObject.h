#ifndef __TMX_OBJECT_H__
#define __TMX_OBJECT_H__

#include "cocos2d.h"
#include "Object/TileData.h"


USING_NS_CC;

class TMXObject
{
public:
	TMXObject(){};
	~TMXObject(){};

	TMXTiledMap* Create(const char* filename);
	TMXTiledMap* GetTMXTiledMap(){ return mTMXTiledMap; }

	int GetTileId(const char* layer_name, Touch* touch);
	Point GetTouchPoint(Touch* touch);
	Point GetTouchCenterPoint(Touch* touch);

	TileData* GetTile(int x, int y);
	void SetTile(int x, int y, TileData* tile);

private:
	TMXTiledMap* mTMXTiledMap;
	int calcClickPoint(float touchpos, float tilesize);
	void createTileMap();

	std::vector<std::vector<TileData*>> mTileMap;
};

#endif // __TMX_OBJECT_H__
