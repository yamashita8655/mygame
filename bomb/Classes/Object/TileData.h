#ifndef __TILEDATA_H__
#define __TILEDATA_H__

#include "cocos2d.h"
#include "Object/DrawObject.h"

USING_NS_CC;

class TileData
{
public:
	TileData();
	virtual ~TileData(){};
	void SetPutObject(DrawObject* object){ mPutObject = object; }
	DrawObject* GetPutObject(){ return mPutObject; }

	int mPosx;
	int mPosy;

private:
	DrawObject* mPutObject;
};

#endif // __TILE_H__
