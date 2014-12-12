#include "SceneGame.h"

Scene* SceneGame::scene()
{
	Scene* sc = Scene::create();
	SceneGame* scGame = SceneGame::create();
	sc->addChild(scGame);
	return sc;
}

bool SceneGame::init()
{
	Size winSize = Director::getInstance()->getWinSize();
	//创建桌子
	Sprite* desk = Sprite::create("floor.jpg");
	this->addChild(desk);
	desk->setPosition(ccp(winSize.width / 2, winSize.height/2));
	desk->setScaleX(winSize.width/desk->getContentSize().width);
	desk->setScaleY(winSize.height / desk->getContentSize().height);

	//创建棋盘
	Sprite* plate = Sprite::create("background.png");
	this->addChild(plate);
	plate->setAnchorPoint(ccp(0,0.5));
	plate->setScale(winSize.width / plate->getContentSize().width*2/3);
	plate->setPosition(ccp(20, winSize.height / 2));
	return true;
}