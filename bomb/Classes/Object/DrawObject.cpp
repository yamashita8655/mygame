#include "DrawObject.h"

USING_NS_CC;

DrawObject::DrawObject()
	:mSprite(nullptr)
{
	mSpriteAnimation = Animation::create();
}

void DrawObject::AnimationAddSprite(SpriteFrame* sprite)
{
	mSpriteAnimation->addSpriteFrame(sprite);
}

void DrawObject::SetAnimationFrame(float frame)
{
	mSpriteAnimation->setDelayPerUnit(frame);
	mSpriteAnimation->setRestoreOriginalFrame(true);
}

void DrawObject::PlayAnimation()
{
	auto animate = Animate::create(mSpriteAnimation);
	auto anime  = RepeatForever::create(animate);
	mSprite->runAction(anime);
}


