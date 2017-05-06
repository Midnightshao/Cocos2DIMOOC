//
//  BaseAi.hpp
//  NewCocosProject
//
//  Created by 广昊 邵 on 2017/4/17.
//
//

#ifndef BaseAi_hpp
#define BaseAi_hpp

#include <iostream>
#include "cocos2d.h"
#include "BaseRole.hpp"
#include "BaseFSM.hpp"
USING_NS_CC;
class BaseAi:public Ref{
public:
    static BaseAi * createAI(BaseRole * role);
    bool init(BaseRole * role);
    void startRoleAI();
    void stopRoleAI();
    void updateFunc(float dt);
    void purge();
    public :
        
        BaseRole * baseRole;
};
#endif /* BaseAi_hpp */
