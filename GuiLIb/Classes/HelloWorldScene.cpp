#include "HelloWorldScene.h"
using namespace cocos2d;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    COCOUISYSTEM->resetSystem(this);
    
    COCOUISYSTEM->replaceUISceneWithFile(this, "UIRES/CocoGUISample.json", 1, true,true,true);
    
    cs::CocoScrollView* sc = (cs::CocoScrollView*)(COCOUISYSTEM->getWidgetByName("scrollview"));
    sc->setUpdateEnable(true);
    cs::CocoTextButton* bt = (cs::CocoTextButton*)(COCOUISYSTEM->getWidgetByName("backtotopbutton"));
    bt->addReleaseEvent(this, coco_releaseselector(HelloWorld::backToTop));
    cs::CocoSlider* sld = (cs::CocoSlider*)(COCOUISYSTEM->getWidgetByName("slider"));
    sld->addPercentChangedEvent(this, coco_percentchangedselector(HelloWorld::sliderPercentChanged));
    cs::CocoButton* anib = (cs::CocoButton*)(COCOUISYSTEM->getWidgetByName("animationbutton"));
    anib->addReleaseEvent(this, coco_releaseselector(HelloWorld::playUIAnimation));
    cs::CocoButton* exit = (cs::CocoButton*)(COCOUISYSTEM->getWidgetByName("exitbutton"));
    exit->addReleaseEvent(this, coco_releaseselector(HelloWorld::menuCloseCallback));
    exit->addCancelEvent(this, coco_cancelselector(HelloWorld::cancelTouch));
    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::backToTop(cocos2d::CCObject *pSender)
{
    cs::CocoScrollView* sc = (cs::CocoScrollView*)(COCOUISYSTEM->getWidgetByName("scrollview"));
    sc->scrollToTop();
}

void HelloWorld::sliderPercentChanged(cocos2d::CCObject *pSender)
{
    cs::CocoLoadingBar* lb = (cs::CocoLoadingBar*)(COCOUISYSTEM->getWidgetByName("loadingbar"));
    cs::CocoSlider* sld = (cs::CocoSlider*)pSender;
    int percent = sld->getPercent();
    lb->setPercent(percent);
}

void HelloWorld::playUIAnimation(cocos2d::CCObject *pSender)
{
    cs::CocoWidget* widget = (cs::CocoWidget*)pSender;
    widget->stopAllActions();
    widget->setColor(0, 0, 255);
    CCTintTo* tt = CCTintTo::create(0.5f, 0, 255, 0);
    CCTintTo* tt2 = CCTintTo::create(0.5f, 255, 255, 255);
    CCFadeOut* fo = CCFadeOut::create(0.5f);
    CCFadeIn* fi = CCFadeIn::create(0.5f);
    CCSequence* seq = CCSequence::create(CCMoveTo::create(1.0, ccp(300, 300)),CCScaleTo::create(1, 0.5),CCMoveTo::create(1.0, ccp(127, 96)),CCScaleTo::create(1.0, 1.0),CCRotateTo::create(0.5, 720),CCRotateTo::create(0.5, 0),tt,tt2,fo,fi,NULL);
    widget->runAction(seq);
}

void HelloWorld::cancelTouch(cocos2d::CCObject *pSender)
{
    CCLOG("cancel touch");
}
