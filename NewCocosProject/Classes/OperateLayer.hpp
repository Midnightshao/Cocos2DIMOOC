//
//  OperateLayer.hpp
//  NewCocosProject
//
//  Created by 广昊 邵 on 2017/4/11.
//
//

#ifndef OperateLayer_hpp
#define OperateLayer_hpp

#include <iostream>
#include "cocos2d.h"
#include "HRocker.hpp"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;
class OperateLayer:public Layer{
    public:
    CREATE_FUNC(OperateLayer);
    void touchCallBack(Ref *sender,Widget::TouchEventType controlEvent);
    virtual  bool init();

};
#endif /* OperateLayer_hpp */
