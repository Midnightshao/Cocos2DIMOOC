//
//  RoleCardController.hpp
//  NewCocosProject
//
//  Created by 广昊 邵 on 2017/4/16.
//
//

#ifndef RoleCardController_hpp
#define RoleCardController_hpp

#include <iostream>
#include "cocos2d.h"
#include "BaseRole.hpp"
USING_NS_CC;


class RoleCardController:public Ref{
    public :
    static  RoleCardController * getInstance();
    virtual bool init();
    void purge();
    public :
            std::vector<BaseRole *>heroVec;
            std::vector<BaseRole *>monsterVec;
    
            BaseRole * getHero();
    public :
            CC_SYNTHESIZE(int, HeroID,HeroID);
};
#endif /* RoleCardController_hpp */
