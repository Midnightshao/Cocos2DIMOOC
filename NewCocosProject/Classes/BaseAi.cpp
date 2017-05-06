//
//  BaseAi.cpp
//  NewCocosProject
//
//  Created by 广昊 邵 on 2017/4/17.
//
//

#include "BaseAi.hpp"
#include "BaseFSM.hpp"
#include "RoleCardController.hpp"


BaseAi * BaseAi::createAI(BaseRole * role){
    BaseAi *ai=new BaseAi();
    if(ai && ai->init(role)){
        ai->autorelease();
    }else{
        CC_SAFE_FREE(ai);
    }
    return  ai;
}
bool BaseAi::init(BaseRole * role){
     BaseAi::baseRole=role;
    return true;
};
void BaseAi::startRoleAI(){
    Director::getInstance()->getScheduler()->schedule(CC_SCHEDULE_SELECTOR(BaseAi::updateFunc),this, (float)1/60, false);
}
void BaseAi::stopRoleAI(){
    Director::getInstance()->getScheduler()->unschedule(CC_SCHEDULE_SELECTOR(BaseAi::updateFunc), this);
}
void BaseAi::updateFunc(float dt){

    std::vector<BaseRole *> roleVec;
    if(baseRole->type == TYPE_HERO){
         roleVec=RoleCardController::getInstance()->monsterVec;
    }else if(baseRole->type == TYPE_MONSTER){
         roleVec =RoleCardController::getInstance()->heroVec;
    }
//  -----------------------------------------------------------------------------------
    int roleID=0;
//    -------------------------------------------------------------------------------------------
    if(roleVec.size()!=0){
        float distance =Director::getInstance()->getVisibleSize().width;
        for(int i=0;i<roleVec.size();i++){
            
            float newDis=abs(baseRole->getPosition().distance(roleVec[i]->getPosition()));
            if(newDis <distance){
                roleID=i;
                distance=newDis;
            }
        }
        if(roleVec[roleID]->getPositionX()>baseRole->getPositionX()){
            baseRole->changeFace(FACE_RIGHT);
            baseRole->face=FACE_RIGHT;
        }else{
            baseRole->changeFace(FACE_LEFT);
            baseRole->face=FACE_LEFT;
        }
    }
    else{
            baseRole->lockRole=nullptr;
            return;
    }
//    -------------------------------------------------------------------------------------
    baseRole->lockRole=roleVec[roleID];
//    &------------------------------------------------------------
    if(baseRole->type ==TYPE_MONSTER){
//
        Vec2 enemyPos= roleVec[roleID]->getPosition();
//--------------------------------------------------------------------------------------------------
        if(baseRole->getPosition().distance(enemyPos)<baseRole->property->getLockmit()){

            CCLOG("判断是否重叠");
            
            if(baseRole->getPosition().distance(enemyPos)<baseRole->property->getATKLimit()){
                baseRole->getBaseFSM()->changeToAttack();
            }
            else{
                if (baseRole->face == FACE_LEFT && baseRole->state!=ROLE_ATTACK) {
                    CCLOG("向左向左向左向左向左向左向左向左向左向左向左向左向左向左向左向左");
                    baseRole->getBaseFSM()->changeToLeft();
                }
                else if(baseRole->face == FACE_RIGHT && baseRole->state!=ROLE_ATTACK){
                    CCLOG("向右向右向右向右向右向右向右向右向右向右向右向右向右向右向右向右向右向右向右向右");
                    baseRole->getBaseFSM()->changeToRight();
                }
            }
//          ----------------------------------------------------------------------------------
        }else{
            baseRole->getBaseFSM()->changeToDefault();
        }
// &------------------------------------------------------------------------------------------------------
    }
    
}
void BaseAi::purge(){
    stopRoleAI();
    baseRole=nullptr;
    CC_SAFE_RELEASE(this);
}