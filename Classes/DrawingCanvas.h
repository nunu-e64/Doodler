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
    
    void setupTouchHandling();
};

#endif /* defined(__Doodler__DrawingCanvas__) */
