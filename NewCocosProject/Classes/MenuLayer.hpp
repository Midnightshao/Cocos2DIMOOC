//
//  MenuLayer.hpp
//  NewCocosProject
//
//  Created by 广昊 邵 on 2017/4/10.
//
//

#ifndef MenuLayer_hpp
#define MenuLayer_hpp
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include <iostream>
#include "cocos2d.h"
#include "SceneManager.hpp"
using namespace ui;
using namespace cocostudio;
USING_NS_CC;

class MenuLayer:public Layer{
    public :
    CREATE_FUNC(MenuLayer);
    virtual bool init();
    
    void touchCallBack(Ref *sender,Widget::TouchEventType controlEvent);
public:
    SceneManager * tsm;
};


#endif /* MenuLayer_hpp */
