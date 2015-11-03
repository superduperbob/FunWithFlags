#ifndef __SECOND_SCREEN_H__
#define __SECOND_SCREEN_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
class SecondScreen
{
public:
	SecondScreen();
	cocos2d::Scene* GetScene();
	void CreateEventListeners();
	void AddLogo();
private:
	void AddFlags();
	cocos2d::Scene* _scene;
	cocos2d::Node* _rootNode;
	


};

#endif