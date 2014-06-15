#include "PuzzleScene.h"
#include "Utility/TMXManager.h"
#include "Object/ObjectManager.h"

USING_NS_CC;

Scene* PuzzleScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = PuzzleScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool PuzzleScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(PuzzleScene::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "PuzzleScene" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
	
	// タイルエディターで作った画像の作成
	mTMXObject = TMXManager::getInstance()->CreateTMXObject("mapdata/map1.tmx");
	this->addChild(mTMXObject->GetTMXTiledMap(), 0);
	
	this->scheduleUpdate();

	// タッチイベント登録らしい
    EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
    EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(PuzzleScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(PuzzleScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(PuzzleScene::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(PuzzleScene::onTouchCancelled, this);
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);


	// マルチタッチ。忘れないように書いておくだけ
	//EventDispatcher* dispatcher2 = Director::getInstance()->getEventDispatcher();
    //EventListenerTouchAllAtOnce* listener2 = EventListenerTouchAllAtOnce::create();
    //listener2->onTouchesBegan = CC_CALLBACK_2(PuzzleScene::onTouchesBegan, this);
    //listener2->onTouchesMoved = CC_CALLBACK_2(PuzzleScene::onTouchesMoved, this);
    //listener2->onTouchesCancelled = CC_CALLBACK_2(PuzzleScene::onTouchesCancelled, this);
    //listener2->onTouchesEnded = CC_CALLBACK_2(PuzzleScene::onTouchesEnded, this);

    //dispatcher2->addEventListenerWithSceneGraphPriority(listener2, this);

	ObjectManager::getInstance()->CreateSpriteFrameCache("putobject/sample_texturepacker.plist");
	return true;
}

void PuzzleScene::update(float delta)
{
}


void PuzzleScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
	

bool PuzzleScene::onTouchBegan(Touch* touch, Event* event)
{
	//EventMouse* mouse = (EventMouse*)event;

	Point tileCoord = Point(touch->getLocation().x, touch->getLocation().y);
	//uint32_t gid = mLayer->getTileGIDAt(Point(0,0));
	int tilex = 0;
	int tiley = 0;
	int gid = mTMXObject->GetTileId("layer1", touch);

	log("%d\n", gid);

	Sprite* bomb = ObjectManager::getInstance()->CreateSprite("bomb01.png");
	Point drawpos = mTMXObject->GetTouchCenterPoint(touch);
    bomb->setPosition(drawpos);
    this->addChild(bomb, 0);
	
	return true;
}
   
void PuzzleScene::onTouchMoved(Touch* touch, Event* event)
{
}
   
void PuzzleScene::onTouchEnded(Touch* touch, Event* event)
{
}
   
void PuzzleScene::onTouchCancelled(Touch* touch, Event* event)
{
	OutputDebugString(L"cancell\n");
}

	
void PuzzleScene::onTouchesBegan(const std::vector<Touch*>& touches, Event *pEvent)
{
	
}
void PuzzleScene::onTouchesMoved(const std::vector<Touch*>& touches,Event *pEvent)
{
	
}
void PuzzleScene::onTouchesEnded(const std::vector<Touch*>& touches, Event *pEvent)
{
	
}
void PuzzleScene::onTouchesCancelled(const std::vector<Touch*>& touches, Event *pEvent)
{
	
}

