#include "HelloWorldScene.h"
#include "SecondScreen.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

#define COCOS2D_DEBUG 1
using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("StartScreen.csb");
    addChild(rootNode);
	
	auto startButton = rootNode->getChildByName<cocos2d::ui::Button*>("btnStart");
	
	startButton->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
		auto secondScreen = new SecondScreen();
		switch (type)
		{

		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			log("Start Button clicked");
			
			CCDirector::getInstance()->replaceScene(secondScreen->GetScene());
			break;
		default:
			break;
		}
	});
    return true;
}

