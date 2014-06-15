#ifndef __PUZZLE_SCENE_H__
#define __PUZZLE_SCENE_H__

#include "cocos2d.h"
#include "Utility/TMXObject.h"

USING_NS_CC;

class PuzzleScene : public cocos2d::Layer
{
public:
	// タイル情報
	TMXObject* mTMXObject;

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
	
	void update(float delta);
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
	// 繧ｷ繝ｳ繧ｰ繝ｫ繧ｿ繝・メ
	bool onTouchBegan(Touch* touch, Event* event);
    void onTouchMoved(Touch* touch, Event* event);
    void onTouchEnded(Touch* touch, Event* event);
    void onTouchCancelled(Touch* touch, Event* event);
    
	// 繝槭Ν繝√ち繝・メ
	virtual void onTouchesBegan(const std::vector<Touch*>& touches, Event *pEvent);
    virtual void onTouchesMoved(const std::vector<Touch*>& touches,Event *pEvent);
    virtual void onTouchesEnded(const std::vector<Touch*>& touches, Event *pEvent);
    virtual void onTouchesCancelled(const std::vector<Touch*>& touches, Event *pEvent);
	// implement the "static create()" method manually
    CREATE_FUNC(PuzzleScene);
};

#endif // __HELLOWORLD_SCENE_H__
