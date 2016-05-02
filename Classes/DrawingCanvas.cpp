//
//  DrawingCanvas.cpp
//  Doodler
//
//  Created by Fumiya Amano on 2016/04/28.
//
//

#include "DrawingCanvas.h"
#include "Constants.h"

USING_NS_CC;

bool DrawingCanvas::init()
{
    if (!Node::init())
    {
        return false;
    }

    drawNode = DrawNode::create();
    this->addChild(drawNode);
    
    return true;
}

#pragma mark - View lifecycle

void DrawingCanvas::onEnter()
{
    Node::onEnter();

    Size visibleSize = CCDirector::getInstance()->getVisibleSize();
    
    background = LayerColor::create(Color4B(COLOR_WHITE));
    this->addChild(background);

    this->setContentSize(visibleSize);
    drawNode->setContentSize(visibleSize);
    this->addChild(drawNode);
    
    this->setupTouchHandling();
    this->setupMenus();
}

void DrawingCanvas::onExit()
{
    Node::onExit();
}

void DrawingCanvas::setupTouchHandling()
{
    static Vec2 lastTouchPos;
    
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = [&](Touch* touch, Event* event)
    {
        lastTouchPos = drawNode->convertTouchToNodeSpace(touch);
        return true;
    };

    touchListener->onTouchMoved = [&](Touch* touch, Event* event)
    {
        Vec2 touchPos = drawNode->convertTouchToNodeSpace(touch);
        CCLOG("Touch Moved! x:%f y:%f", touchPos.x, touchPos.y);
        drawNode->drawSegment(lastTouchPos, touchPos, INITIAL_RADIUS, Color4F(0.0f, 0.0f, 0.0f, 1.0f));
        lastTouchPos = touchPos;
    };
    
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}

void DrawingCanvas::setupMenus()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    ui::Button* clearButton = ui::Button::create();
    clearButton->setAnchorPoint(Vec2(1.0f, 1.0f));
    clearButton->setPosition(Vec2(visibleSize.width, visibleSize.height));
    clearButton->loadTextures("clearButton.png", "clearButtonPressed.png");
    clearButton->addTouchEventListener(CC_CALLBACK_2(DrawingCanvas::clearPressed, this));
    this->addChild(clearButton);
    
    ui::Button* backButton = ui::Button::create();
    backButton->setAnchorPoint(Vec2(0.0f, 1.0f));
    backButton->setPosition(Vec2(0.0f, visibleSize.height));
    backButton->loadTextures("backButton.png", "backButtonPressed.png");
    backButton->addTouchEventListener(CC_CALLBACK_2(DrawingCanvas::backPressed, this));
    this->addChild(backButton);
    
    check = Sprite::create("checkMark.png");
    check->setAnchorPoint(Vec2(0.5f, 0.5f));
    check->setNormalizedPosition(Vec2(0.5f, 0.5f));
    
    Node* colorButtonLayout = Node::create();
    colorButtonLayout->setContentSize(Size(visibleSize.width, visibleSize.height * 0.2f));
    colorButtonLayout->setAnchorPoint(Vec2(0.5f, 0.0f));
    colorButtonLayout->setPosition(Vec2(visibleSize.width / 2.0f, 0.0f));
    this->addChild(colorButtonLayout);
    
    for (int i = 1; i <= 5; ++i)
    {
        ui::Button* colorButton = ui::Button::create();
        colorButton->setAnchorPoint(Vec2(0.5f, 0.0f));
        colorButton->loadTextures("colorSwatch.png", "colorSwatch.png");
        colorButton->addTouchEventListener(CC_CALLBACK_2(DrawingCanvas::colorChangePressed, this));
        colorButton->setColor(Color3B(COLOR_BLUE));
        colorButton->setNormalizedPosition(Vec2((i - 3) * 0.5f, 0.5f));
        colorButtonLayout->addChild(colorButton);
    }
}

void DrawingCanvas::clearPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED)
    {
        drawNode->clear();
    }
}

void DrawingCanvas::backPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED)
    {
        Director::getInstance()->popScene();
    }
}

void DrawingCanvas::colorChangePressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    
}