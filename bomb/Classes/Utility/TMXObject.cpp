#include "TMXObject.h"
#include "TMXManager.h"

USING_NS_CC;

TMXTiledMap* TMXObject::Create(const char* filename)
{
	mTMXTiledMap = TMXTiledMap::create(filename);
	
	createTileMap();
	return mTMXTiledMap;
}

// クリック座標から、そのタイルのIDを取得する
int TMXObject::GetTileId(const char* layer_name, Touch* touch)
{
	TMXLayer* layer = mTMXTiledMap->getLayer(layer_name);
	if(layer == nullptr)
	{
		return -1;
	}

	Size mapsize = mTMXTiledMap->getMapSize();// 横と縦のタイル数が返る
	Size tilesize = mTMXTiledMap->getTileSize();// 1マップのタイルサイズ

	int width = mapsize.width * tilesize.width;
	int height = mapsize.height * tilesize.height;

	if(touch->getLocation().x > width)
	{
		return -1;
	}
	
	if(touch->getLocation().y > height)
	{
		return -1;
	}

	Point touchpos = GetTouchPoint(touch);

	int gid = layer->getTileGIDAt(touchpos);
	return gid;
}

Point TMXObject::GetTouchPoint(Touch* touch)
{
	Size mapsize = mTMXTiledMap->getMapSize();// 横と縦のタイル数が返る
	Size tilesize = mTMXTiledMap->getTileSize();// 1マップのタイルサイズ
	int height = mapsize.height * tilesize.height;
	
	int x = calcClickPoint(touch->getLocation().x, tilesize.width);
	int y = calcClickPoint(height - touch->getLocation().y, tilesize.height);// Y座標は左下原点だが、TMXは左上原点なので、座標変換する必要がある

	return Point(x, y);
}

Point TMXObject::GetTouchCenterPoint(Touch* touch)
{
	Point touchpos = GetTouchPoint(touch);

	Size mapsize = mTMXTiledMap->getMapSize();// 横と縦のタイル数が返る
	Size tilesize = mTMXTiledMap->getTileSize();// 1マップのタイルサイズ
	int height = mapsize.height * tilesize.height;
	
	float x = tilesize.width*touchpos.x + tilesize.width/2;
	float y = (height - tilesize.height*touchpos.y) - tilesize.height/2;

	return Point(x, y);
}

int TMXObject::calcClickPoint(float touchpos, float tilesize)
{
	int surplus = (int)touchpos % (int)tilesize;
	int pos = touchpos / tilesize;

	return pos;
}
	
TileData* TMXObject::GetTile(int x, int y)
{
	return mTileMap.at(y).at(x);
}

void TMXObject::SetTile(int x, int y, TileData* tile)
{
	mTileMap.at(y).at(x) = tile;
}

void TMXObject::createTileMap()
{
	Size mapsize = mTMXTiledMap->getMapSize();// 横と縦のタイル数が返る

	for(int i = 0; i < mapsize.height; i++)
	{
		std::vector<TileData*> vec;
		mTileMap.push_back(vec);

		for(int j = 0; j < mapsize.width; j++)
		{
			TileData* tile = new TileData();
			mTileMap.at(i).push_back(tile);
		}
	}
		
}


