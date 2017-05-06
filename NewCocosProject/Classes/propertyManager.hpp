//
//  propertyManager.hpp
//  NewCocosProject
//
//  Created by 广昊 邵 on 2017/4/14.
//
//

#ifndef propertyManager_hpp
#define propertyManager_hpp

#include <iostream>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
using namespace cocostudio;
USING_NS_CC;
class propertyManager:public Ref{
public:
    CREATE_FUNC(propertyManager);
    virtual bool init();
public:
    
    CC_SYNTHESIZE(int, ID, ID);
    CC_SYNTHESIZE(int, HP, HP);
    CC_SYNTHESIZE(int, ATK, ATK);
    CC_SYNTHESIZE(int, Speed,Speed);
    
    CC_SYNTHESIZE(int, LockLimit,Lockmit);
    CC_SYNTHESIZE(int, ATKLimit ,ATKLimit);
    
    CC_SYNTHESIZE(std::string, ArmatureName, ArmatureName);
    CC_SYNTHESIZE(std::string, DataName, DataName);
    CC_SYNTHESIZE(std::string, PlayerName, PlayerName);
    
    CC_SYNTHESIZE(Rect,GetHitRect, GetHitRect);
    CC_SYNTHESIZE(Point, HitPoint, HitPoint);
    CC_SYNTHESIZE(Point, GetHitPoint,GetHitPoint);
    CC_SYNTHESIZE(Rect, HitRect, HitRect);

};
#endif /* propertyManager_hpp */
