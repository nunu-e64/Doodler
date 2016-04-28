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
}

void DrawingCanvas::onExit()
{
    Node::onExit();
}
