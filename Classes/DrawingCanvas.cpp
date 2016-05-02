//
//  DrawingCanvas.cpp
//  Doodler
//
//  Created by Fumiya Amano on 2016/04/28.
//
//

#include "DrawingCanvas.h"

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
    
    this->setContentSize(visibleSize);
    drawNode->setContentSize(visibleSize);
    
    background = LayerColor::create(Color4B(255, 255, 255, 255));
    this->addChild(background);

    this->addChild(drawNode);
    
    this->setupTouchHandling();
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
        drawNode->drawSegment(lastTouchPos, touchPos, 4.0f, Color4F(0.0f, 0.0f, 0.0f, 1.0f));
        lastTouchPos = touchPos;
    };
    
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
    
}