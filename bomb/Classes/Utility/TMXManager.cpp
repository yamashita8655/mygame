#include "TMXManager.h"

USING_NS_CC;

TMXManager* TMXManager::getInstance() 
{
    static TMXManager instance;
    return &instance;
}

// クリック座標から、そのタイルのIDを取得する
uint32_t TMXManager::GetTileId(TMXTiledMap* map, const char* layer_name, Touch* touch, int* tilex, int* tiley)
{
	TMXLayer* layer =  map->getLayer(layer_name);
	if(layer == nullptr)
	{
		return 0;
	}

	return GetTileId(map, layer, touch, tilex, tiley);
}

// クリック座標から、そのタイルのIDを取得する
uint32_t TMXManager::GetTileId(TMXTiledMap* map, TMXLayer* layer, Touch* touch, int* tilex, int* tiley)
{
	Size mapsize = map->getMapSize();// 横と縦のタイル数が返る
	Size tilesize = map->getTileSize();// 1マップのタイルサイズ

	int width = mapsize.width * tilesize.width;
	int height = mapsize.height * tilesize.height;

	if(touch->getLocation().x > width)
	{
		return 0;
	}
	
	if(touch->getLocation().y > height)
	{
		return 0;
	}

	int x = calcClickPoint(touch->getLocation().x, tilesize.width);
	int y = calcClickPoint(height - touch->getLocation().y, tilesize.height);// Y座標は左下原点だが、TMXは左上原点なので、座標変換する必要がある

	if(tilex != nullptr)
	{
		*tilex = x;
	}
	if(tiley != nullptr)
	{
		*tiley = y;
	}

	uint32_t gid = layer->getTileGIDAt(Point(x,y));
	return gid;
}

Point TMXManager::GetCenterPoint(TMXTiledMap* map, int tilex, int tiley)
{
	Size mapsize = map->getMapSize();// 横と縦のタイル数が返る
	Size tilesize = map->getTileSize();// 1マップのタイルサイズ

	float height = mapsize.height * tilesize.height;
	
	float x = tilesize.width*tilex + tilesize.width/2;
	float y = (height - tilesize.height*tiley) - tilesize.height/2;

	return Point(x, y);
}

int TMXManager::calcClickPoint(float touchpos, float tilesize)
{
	int surplus = (int)touchpos % (int)tilesize;
	int pos = touchpos / tilesize;
	//if(surplus > 0)
	//{
	//	pos++;
	//}

	return pos;
}
