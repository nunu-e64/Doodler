//
//  DrawingCanvas.h
//  Doodler
//
//  Created by Fumiya Amano on 2016/04/28.
//
//

#ifndef __Doodler__DrawingCanvas__
#define __Doodler__DrawingCanvas__

#include "cocos2d.h"
#include "CocosGUI.h"

class DrawingCanvas : public cocos2d::Node
{
public:
    CREATE_FUNC(DrawingCanvas);

private:
    bool init() override;
    void onEnter() override;
    void onExit() override;
    
protected:
    cocos2d::DrawNode* drawNode;
    cocos2d::LayerColor* background;
    cocos2d::Sprite* check;
    cocos2d::Color4F selectedColor;
    
    void setupTouchHandling();
    void setupMenus();
    void clearPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void backPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void colorChangePressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
};

#endif /* defined(__Doodler__DrawingCanvas__) */
