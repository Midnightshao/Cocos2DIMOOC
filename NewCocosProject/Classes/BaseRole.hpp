//
//  BaseRole.hpp
//  NewCocosProject
//
//  Created by 广昊 邵 on 2017/4/14.
//
//

#ifndef BaseRole_hpp
#define BaseRole_hpp
#include "ui/CocosGUI.h"
#include "renderer/CCRenderer.h"
#include "renderer/CCCustomCommand.h"
#include "propertyManager.hpp"
#include <iostream>
#include "cocostudio/CocoStudio.h"
#include "cocos2d.h"
#include "FlyText.hpp"
using namespace cocostudio;

USING_NS_CC;
class BaseFSM;
class BaseAi;
    typedef enum {
        TYPE_HERO=1,
        TYPE_MONSTER=2
    }ROLE_TYPE;
    typedef enum {
        ROLE_DEFAULT=1,
        ROLE_ATTACK,
        ROLE_MOVE,
        Role_DEAD,
        Role_FREE
    }ROLE_STATE;
    typedef enum {
        FACE_LEFT=1,
        FACE_RIGHT=2,
}ROLE_FACE;

class BaseRole:public Node{
    public:
        static BaseRole * createWithPorperty(propertyManager *manager);
        bool init(propertyManager *manager);
    public:
        void changeFace(ROLE_FACE face);
        void animationEvent(Armature *pArmature,MovementEventType movementType,const std::string& movemontIDstr);
    
        void draw(cocos2d::Renderer* renderer, const cocos2d::Mat4& transform, uint32_t flags) override;
        void onDraw(const Mat4 &transform, uint32_t flags);
        cocos2d::CustomCommand _customCommand;
        Rect getRealRect(BaseRole *role,Rect rect);
        void fallHP(const char* hpCount);
        void purge();
    public:
//      锁定敌人
        BaseRole * lockRole;
    
        ROLE_TYPE type;
        ROLE_STATE state;
        ROLE_FACE face;
        propertyManager * property;
//        BaseFSM *baseFSM;
        CC_SYNTHESIZE(Armature *,armature, armature);
        CC_SYNTHESIZE(BaseFSM *, baseFSM, BaseFSM);
        CC_SYNTHESIZE(BaseAi *, baseAi,BaseAi);
};
#endif /* BaseRole_hpp */
