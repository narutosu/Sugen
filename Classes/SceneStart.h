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
	int stone_r;//���Ӱ뾶
	void StoneRun(bool);
	void update(float);

	//����Ƿ�ѡ���˺�ɫ����
	bool _selected;
};

#endif