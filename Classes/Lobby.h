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

class Lobby : public cocos2d::Node
{
public:
    CREATE_FUNC(Lobby);

private:
    bool init() override;
    void onEnter() override;
    void onExit() override;
    void setupUI();
};

#endif /* defined(__Doodler__Lobby__) */
