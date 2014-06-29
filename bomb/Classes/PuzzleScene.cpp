#include "PuzzleScene.h"
#include "Utility/TMXManager.h"
#include "Utility/SpriteCreator.h"
#include "Object/ObjectManager.h"
#include "Object/BombObject.h"

USING_NS_CC;

Scene* PuzzleScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = PuzzleScene::create();

    // add layer as a child to scene
    scene->addChild(layer, 0, 100);

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
	SpriteCreator::getInstance()->AddSpriteFrameCache("putobject/sample_texturepacker.plist");
	
	return true;
}

void PuzzleScene::update(float delta)
{
	ObjectManager::getInstance()->Update();
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
	Point point = mTMXObject->GetTouchPoint(touch);
/*	if(mTMXObject->GetTile(point.x, point.y) != nullptr)
	{
		return false;
	}*/
	if(ObjectManager::getInstance()->GetDrawObject(point.x, point.y) != nullptr)
	{
		return false;
	}
	
	Point tileCoord = Point(touch->getLocation().x, touch->getLocation().y);
	//uint32_t gid = mLayer->getTileGIDAt(Point(0,0));
	int tilex = 0;
	int tiley = 0;
	int gid = mTMXObject->GetTileId("layer1", touch);

	log("%d\n", gid);

	BombObject* bomb = ObjectManager::getInstance()->CreateBombObject("bomb01.png", point.x, point.y);


	for(int i = 0; i < 4; i++)
	{
		auto str = __String::createWithFormat("bomb0%i.png", i);
		SpriteFrame* spframe = SpriteCreator::getInstance()->CreateSpriteFrame(str->getCString());
		bomb->AnimationAddSprite(spframe);
	}
	bomb->SetAnimationFrame(1.0f);
	bomb->PlayAnimation();

	Point drawpos = mTMXObject->GetTouchCenterPoint(touch);
    bomb->GetSprite()->setPosition(drawpos);
    this->addChild(bomb->GetSprite(), 0);

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

/*void PuzzleScene::RemoveBomb(EventCustom* event)
{
	BombObject* bomb = (BombObject*)event->getUserData();
	bomb->DeleteEventDispatcher();
	auto director = Director::getInstance();
	Sprite* delsprite = bomb->GetSprite();
	Scene* scene = director->getRunningScene();
	Layer* layer = (Layer*)scene->getChildByTag(100);
	layer->removeChild(delsprite);
	ObjectManager::getInstance()->DeleteObjectList(bomb->GetKey());
}*/


