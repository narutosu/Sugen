#ifndef _SceneStart_H_
#define _SceneStart_H_

#include "cocos2d.h"
USING_NS_CC;

class SceneStart : public Layer
{
public:
	static CCScene* scene();

	bool init();

	CREATE_FUNC(SceneStart);

	CCSprite* _red;
	CCSprite* _black;
	int stone_r;//棋子半径
	void StoneRun(bool);
	void update(float);

	//标记是否选中了红色棋子
	bool _selected;
};

#endif