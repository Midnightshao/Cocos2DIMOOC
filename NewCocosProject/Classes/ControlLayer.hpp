//
//  ControlLayer.hpp
//  NewCocosProject
//
//  Created by 广昊 邵 on 2017/4/11.
//
//

#ifndef ControlLayer_hpp
#define ControlLayer_hpp

#include <iostream>
#include "cocos2d.h"
#include "BaseRole.hpp"
#include "BaseFSM.hpp"
#include "SceneManager.hpp"
#include "HRocker.hpp"
USING_NS_CC;


class ControlLayer:public Layer{
    public:
        virtual bool init();
        void update(float dt);
        void purge();
        CREATE_FUNC(ControlLayer);
    public:
        SceneManager *tsm;
        BaseFSM *baseFSM;
//这里是数据管理的阶段
//        BaseRole *hero;
//        BaseRole *monster;
        HRocker *rocker;
};
#endif /* ControlLayer_hpp */
