//
//  Lobby.h
//  Doodler
//
//  Created by Fumiya Amano on 2016/05/02.
//
//

#ifndef __Doodler__Lobby__
#define __Doodler__Lobby__

#include "cocos2d.h"
#include "CocosGUI.h"

class Lobby : public cocos2d::Node
{
public:
    CREATE_FUNC(Lobby);

private:
    bool init() override;
    void onEnter() override;
    void onExit() override;
    void setupUI();
    void soloPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void duoPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
};

#endif /* defined(__Doodler__Lobby__) */
