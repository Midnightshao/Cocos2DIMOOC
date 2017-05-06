//  BaseRole.cpp
//  NewCocosProject
//
//  Created by 广昊 邵 on 2017/4/14.
//
//

#include "BaseRole.hpp"
#include "propertyManager.hpp"
#include "cocostudio/CocoStudio.h"
#include "BaseAi.hpp"
#include "BaseFSM.hpp"
using namespace cocostudio;

BaseRole * BaseRole::createWithPorperty(propertyManager *manager){
    BaseRole * baseRole=new BaseRole();
    if(baseRole && baseRole ->init(manager)){
        baseRole->autorelease();
    }else{
        CC_SAFE_DELETE(baseRole);
        return nullptr;
    }
    return baseRole;
    
}
bool BaseRole::init(propertyManager *manager){

    property=manager;
    
    ArmatureDataManager::getInstance()->addArmatureFileInfo(property->getDataName());
    
    armature=Armature::create(property->getArmatureName());
    
    armature->getAnimation()->play("default");
    //动画
    this->addChild(armature);
    
    armature->getAnimation()->setMovementEventCallFunc(CC_CALLBACK_0(BaseRole::animationEvent,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3));
    
    property=manager;
    
    return true;
}

Rect BaseRole::getRealRect(BaseRole *role, Rect rect){
    Rect realRect =Rect (rect.origin.x+role->getPositionX(),rect.origin.y + role->getPositionY(),rect.size.width,rect.size.height);
    return realRect;
}
void BaseRole::fallHP(const char *hpCount){
    FlyText * flyText=FlyText::create(hpCount);
    flyText->startAnimation();
    this->addChild(flyText);
}
void BaseRole::animationEvent(Armature *pArmature, MovementEventType movementType,const std::string& movementIDstr){
    
    const char * moventID = movementIDstr.c_str();
    if(strcmp(moventID,"attack") == 0){
        if(movementType ==START){
            if(lockRole!=nullptr && state!=Role_DEAD){
                if(getRealRect(this, property->getHitRect()).intersectsRect(lockRole->getRealRect(lockRole,property->getGetHitRect()))){
                    
                    CCLOG("击中了");
                    int atk=property->getATK();
                    __String * hpStr = __String::createWithFormat("%d",atk);
                    lockRole->fallHP(hpStr->getCString());
                    
                    lockRole->property->setHP(lockRole->property->getHP()-atk);
                    
                    if(lockRole->property->getHP()<=0){
                        lockRole->getBaseAi()->stopRoleAI();
                        lockRole->getBaseFSM()->changeToDead();
                        }
                    }
                }
            }
        if(movementType == COMPLETE){
                baseFSM->changeToDefault();
            }
        }
    
    if(strcmp(moventID,"gethit")==0){
        if(movementType==COMPLETE){
            //Sequence动画
            armature->runAction(Sequence::create(FadeOut::create(0.5),CallFunc::create([=](){
                state = Role_FREE;}) ,NULL));
            }
        }
    };

void BaseRole::onDraw(const Mat4 &transform, uint32_t flags)
{
    Director* director = Director::getInstance();
    director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, transform);
    CHECK_GL_ERROR_DEBUG();
    
    Rect rect = property->getHitRect();
    DrawPrimitives::setDrawColor4B(0, 0,255,255);
    DrawPrimitives::drawRect(Vec2(rect.getMinX(),rect.getMinY()),Vec2(rect.getMaxX(),rect.getMaxY()));
    
    Rect rect1=property->getGetHitRect();
    DrawPrimitives::setDrawColor4B(0,255,0,255);
    DrawPrimitives::drawRect(Vec2(rect1.getMinX(),rect1.getMinY()),Vec2(rect1.getMaxX(),rect1.getMaxY()));
    
    CHECK_GL_ERROR_DEBUG();
    director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
}
void BaseRole::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{
    _customCommand.init(_globalZOrder);
    _customCommand.func = CC_CALLBACK_0(BaseRole::onDraw, this, transform, flags);
    renderer->addCommand(&_customCommand);
}

void BaseRole::changeFace(ROLE_FACE face){
    if(face==FACE_LEFT){
        armature->setScaleX(-1);
        property->setHitRect(Rect(-property->getHitPoint().x -property->getHitRect().size.width,property->getHitRect().origin.y,property->getHitRect().size.width,property->getHitRect().size.height));
        
    }else if (face==FACE_RIGHT){
        armature->setScaleX(1);
        property->setHitRect(Rect(property->getHitPoint().x,property->getHitRect().origin.y,property->getHitRect().size.width,property->getHitRect().size.height));
    }
}
void BaseRole::purge(){
    this->getBaseFSM()->purge();
    this->getBaseAi()->purge();
    removeFromParent();
};
