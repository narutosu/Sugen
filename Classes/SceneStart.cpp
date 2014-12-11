#include "SceneStart.h"


CCScene* SceneStart::scene()
{
	CCScene* scene = CCScene::create();

	SceneStart* layer = SceneStart::create();

	scene->addChild(layer);

	return scene;
}

bool SceneStart::init()
{
	Layer::init();
	Size winSize = Director::getInstance()->getWinSize();
	Sprite* bkr = Sprite::create("bkg2.png");
	stone_r = bkr->getContentSize().height/2;
	addChild(bkr);
	Sprite* bkb = Sprite::create("bkg1.png");
	addChild(bkb);
	bkr->setPosition(ccp(winSize.width/2-100,winSize.height/2));
	bkb->setPosition(ccp(winSize.width/2+100,winSize.height/2));

	_red = bkr;
	_black = bkb;

	//setTouchMode(kCCTouchesOneByOne);
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan=[](Touch* touch,Event* event)
	{
		log("TouchBegan");
		return true;
	};

	listener->onTouchMoved = [](Touch* touch, Event* event)
	{
	};

	listener->onTouchEnded = [=](Touch* touch, Event* event)
	{
		Point pClick = touch->getLocation();
		if (_red->boundingBox().containsPoint(pClick))
		{
			_selected = true;
			StoneRun(true);
		}
		if (_black->boundingBox().containsPoint(pClick))
		{
			_selected = false;
			//StoneRun(true);
		}

	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, bkr);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), bkb);
	return true;
}

void SceneStart::StoneRun(bool x)
{
	Size winSize = Director::getInstance()->getWinSize();
	MoveTo* mo1 = MoveTo::create(1, ccp(winSize.width/2, winSize.height/2));
	MoveTo* mo2 = MoveTo::create(1, ccp(winSize.width/2, winSize.height/2));

	RotateBy* rotate1 = RotateBy::create(1, 360);
	RotateBy* rotate2 = RotateBy::create(1, -360);

	Spawn* sp1 = Spawn::create(mo1,rotate1,NULL);
	Spawn* sp2 = Spawn::create(mo2,rotate2,NULL);
	_red->runAction(sp1);
	_black->runAction(sp2);
	scheduleUpdate();
}

void SceneStart::update(float)
{
	if (_black->getPositionX() - _red->getPositionX() <= 2 * stone_r)
	{
		log("Stone was boom,了解contentsize跟boundingbox的差别");
		Director::getInstance()->pause();
	}
}