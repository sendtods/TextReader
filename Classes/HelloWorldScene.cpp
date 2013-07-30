#include "HelloWorldScene.h"

using namespace cocos2d;



CCScene* HelloWorld::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        HelloWorld *layer = HelloWorld::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    bool bRet = false;
    do 
    {
        //////////////////////////////////////////////////////////////////////////
        // super init first
        //////////////////////////////////////////////////////////////////////////

        CC_BREAK_IF(! CCLayer::init());

        //////////////////////////////////////////////////////////////////////////
        // add your codes below...
        //////////////////////////////////////////////////////////////////////////

        // 1. Add a menu item with "X" image, which is clicked to quit the program.
		//Add a new line in Between
        // Create a "close" menu item with close icon, it's an auto release object.
        CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(HelloWorld::menuCloseCallback));
        CC_BREAK_IF(! pCloseItem);

        // Place the menu item bottom-right conner.
        pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));

        // Create a menu with the "close" menu item, it's an auto release object.
        CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
        pMenu->setPosition(CCPointZero);
        CC_BREAK_IF(! pMenu);

        // Add the menu to HelloWorld layer as a child layer.
        this->addChild(pMenu, 1);

        // 2. Add a label shows "Hello World".

        // Create a label and initialize with string "Hello World".
        CCLabelTTF* pLabel = CCLabelTTF::create("Hello World! I am Dushyant SHarma and this is text reader app by PM Apps", "Arial", 24);
        CC_BREAK_IF(! pLabel);

        // Get window size and place the label upper. 
        CCSize size = CCDirector::sharedDirector()->getWinSize();
		pLabel->setPosition(ccp(size.width + pLabel->getContentSize().width, size.height/2));
		float actualY = size.height / 2.0;
        // Add the label to HelloWorld layer as a child layer.
        this->addChild(pLabel, 1);
		pLabel->setTag(1);
		// Create the actions
		 CCFiniteTimeAction* actionMove = 
        CCMoveTo::create( 9.0,ccp(0 - pLabel->getContentSize().width/2, actualY) );
		 CCFiniteTimeAction* actionMoveDone = 
        CCCallFuncN::create( this, 
        callfuncN_selector(HelloWorld::LabelMoveFinished));
    pLabel->runAction( CCSequence::create(actionMove, 
        actionMoveDone, NULL) );
	
        bRet = true;
    } while (0);

    return bRet;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();
}

void HelloWorld::LabelMoveFinished(CCNode* sender)
{
  CCLabelTTF* bLabel = (CCLabelTTF *)sender;
  
  this->removeChild(bLabel, true);
  //bLabel->release();
  bLabel = NULL;
  
}