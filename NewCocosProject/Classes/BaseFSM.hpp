//
//  BaseFSM.hpp
//  NewCocosProject
//
//  Created by 广昊 邵 on 2017/4/16.
//
//

#ifndef BaseFSM_hpp
#define BaseFSM_hpp

#include <iostream>
#include "cocos2d.h"
#include "BaseRole.hpp"
USING_NS_CC;

class BaseFSM:public Ref{
public:
    static BaseFSM *createrFSM(BaseRole *baseRole);
    bool init(BaseRole * baseRole);
    void purge();
public:
    void swtichMoveState(int dir);
    void changeToDefault();
    void changeToAttack();
    void changeToLeft();
    void changeToRight();
    void changeToDead();
    void changeToEnmeny();
    public :
    BaseRole * role;
};

#endif /* BaseFSM_hpp */
