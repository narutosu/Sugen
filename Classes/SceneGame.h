#ifndef _SceneGame_H_
#define _SceneGame_H_

#include "cocos2d.h"
USING_NS_CC;

class SceneGame : public Layer
{
public:
	static Scene* scene();

	bool init();

	CREATE_FUNC(SceneGame);
};

#endif