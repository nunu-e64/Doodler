//
//  Lobby.cpp
//  Doodler
//
//  Created by Fumiya Amano on 2016/05/02.
//
//

#include "Lobby.h"
#include "DrawingCanvas.h"

USING_NS_CC;

bool Lobby::init()
{
    if (!Node::init())
    {
        return false;
    }

    LayerColor* background = LayerColor::create(Color4B(255, 255, 255, 255));
    this->addChild(background);
    this->setupUI();
    
    return true;
}

#pragma mark - View lifecycle

void Lobby::onEnter()
{
    Node::onEnter();
}

void Lobby::onExit()
{
    Node::onExit();
}

void Lobby::setupUI()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Sprite* logo = Sprite::create("doodlerLogo.png");
    logo->setAnchorPoint(Vec2(0.5f, 0.5f));
    logo->setPosition(Vec2(visibleSize.width * 0.5f, visibleSize.height * 0.75f));
    this->addChild(logo);
    
    ui::Button* soloButton = ui::Button::create();
    soloButton->setAnchorPoint(Vec2(0.5f, 0.5f));
    soloButton->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height * 0.4f));
    soloButton->loadTextures("soloButton.png", "soloButtonPressed.png");
    soloButton->addTouchEventListener(CC_CALLBACK_2(Lobby::soloPressed, this));
    this->addChild(soloButton);

    ui::Button* duoButton = ui::Button::create();
    duoButton->setAnchorPoint(Vec2(0.5f, 0.5f));
    duoButton->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height * 0.25f));
    duoButton->loadTextures("duoButton.png", "duoButtonPressed.png");
    duoButton->addTouchEventListener(CC_CALLBACK_2(Lobby::duoPressed, this));
    this->addChild(duoButton);
}

void Lobby::soloPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED)
    {
        Scene* scene = Scene::create();
        
        DrawingCanvas* drawingCanvas = DrawingCanvas::create();
        scene->addChild(drawingCanvas);
        
        Director::getInstance()->pushScene(scene);
    }
}

void Lobby::duoPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED)
    {

    }
}