#include "SecondScreen.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

SecondScreen::SecondScreen()
{
	_scene = cocos2d::Scene::create();
	_rootNode = CSLoader::createNode("SecondScreen.csb");
	_scene->addChild(_rootNode);
	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	audio->preloadBackgroundMusic("intro.mp3");
	
	

	// Create Event Listeners
	CreateEventListeners();
}

cocos2d::Scene * SecondScreen::GetScene()
{
	if (_scene != nullptr)
	{
		return _scene;
	}
	return nullptr;
}

void SecondScreen::CreateEventListeners()
{
	/////////////////////// EXIT BUTTON ////////////////////////////////////
	auto exitButton = _rootNode->getChildByName<cocos2d::ui::Button*>("btnExit");
	exitButton->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type)
	{
		auto secondScreen = new SecondScreen();
		switch (type)
		{

		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			CCDirector::getInstance()->end();
			break;
		default:
			break;
		}
	});
	/////////////////////////////////////////////////////////////////////

	/////////////////////// START BUTTON ////////////////////////////////////
	auto startButton = _rootNode->getChildByName<cocos2d::ui::Button*>("btnStart");
	startButton->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type)
	{
		auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
		auto scheduler = Director::getInstance()->getScheduler();
		switch (type)
		{

		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			audio->playBackgroundMusic("intro.mp3");
			
			// Schedule task - show logo
			scheduler->schedule([&](float dt)
			{
				AddLogo();
			}, this, 1.0f, 0, 8.0f, false, "AddLogo");

			// Schedule task - show flags
			scheduler->schedule([&](float dt)
			{
				AddFlags();
			}, this, 1.0f, 0, 17.0f, false, "AddFlags");

			break;
		default:
			break;
		}
	});

	///////////////////// VOLUME SLIDER //////////////////////////////////
	
	

}

void SecondScreen::AddLogo()
{
	auto logo = cocos2d::ui::ImageView::create("fun-with-flags.png");
	logo->setPosition(cocos2d::Vec2(200, 200));
	_rootNode->addChild(logo);
}

void SecondScreen::AddFlags()
{
	
	auto englandFlag = cocos2d::ui::Button::create("england.png", "england.png", "england.png", cocos2d::ui::Widget::TextureResType::LOCAL);
	englandFlag->setPosition(cocos2d::Vec2(125, 550));
	englandFlag->setName("btnEngland");
	_rootNode->addChild(englandFlag);

	auto walesFlag = cocos2d::ui::Button::create("wales.png", "wales.png", "wales.png", cocos2d::ui::Widget::TextureResType::LOCAL);
	walesFlag->setPosition(cocos2d::Vec2(350, 550));
	walesFlag->setName("btnWales");
	_rootNode->addChild(walesFlag);

	auto irelandFlag = cocos2d::ui::Button::create("ireland.png", "ireland.png", "ireland.png", cocos2d::ui::Widget::TextureResType::LOCAL);
	irelandFlag->setPosition(cocos2d::Vec2(600, 550));
	irelandFlag->setName("btnIreland");
	_rootNode->addChild(irelandFlag);

	auto scotlandFlag = cocos2d::ui::Button::create("scotland.png", "scotland.png", "scotland.png", cocos2d::ui::Widget::TextureResType::LOCAL);
	scotlandFlag->setPosition(cocos2d::Vec2(850, 550));
	scotlandFlag->setName("btnScotland");
	_rootNode->addChild(scotlandFlag);


	
	/* Add Event listeners - England flag */
	
	
	englandFlag->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type)
	{
		auto selectedButton = _rootNode->getChildByName("btnEngland");
		auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			audio->playBackgroundMusic("england.mp3");
			_rootNode->removeChild(selectedButton, true);
		default:
			break;
		}
	});

	/* Add Event listeners - Ireland flag */
	irelandFlag->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type)
	{
		auto selectedButton = _rootNode->getChildByName("btnIreland");
		auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			audio->playBackgroundMusic("ireland.mp3");
			_rootNode->removeChild(selectedButton, true);
		default:
			break;
		}
	});

	/* Add Event listeners - England flag */
	walesFlag->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type)
	{
		auto selectedButton = _rootNode->getChildByName("btnWales");
		auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			audio->playBackgroundMusic("wales.mp3");
			_rootNode->removeChild(selectedButton, true);
		default:
			break;
		}
	});

	/* Add Event listeners - Scotland flag */
	scotlandFlag->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type)
	{
		auto selectedButton = _rootNode->getChildByName("btnScotland");
		auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			audio->playBackgroundMusic("scotland.mp3");
			_rootNode->removeChild(selectedButton, true);
		default:
			break;
		}
	});

}