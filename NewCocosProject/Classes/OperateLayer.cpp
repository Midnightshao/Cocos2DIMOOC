//
//  OperateLayer.cpp
//  NewCocosProject
//
//  Created by 广昊 邵 on 2017/4/11.
//
//

#include "OperateLayer.hpp"
#include "HRocker.hpp"
#include "BaseFSM.hpp"
#include "RoleCardController.hpp"
#include "BaseAi.hpp"
bool OperateLayer::init(){

    Button * button=Button::create();
    button->loadTextures("Default/Button_Press.png","");
    button->setPosition(Vec2(800,200));
    button->addTouchEventListener(CC_CALLBACK_2(OperateLayer::touchCallBack, this));
    this->addChild(button);
    return true;
}
void OperateLayer::touchCallBack(Ref * sender, Widget::TouchEventType controlEvent){
    if(controlEvent==Widget::TouchEventType::ENDED){
        CCLOG("%s","点击。。。。。。。。");

        RoleCardController::getInstance()->getHero()->getBaseFSM()->changeToAttack();
        RoleCardController::getInstance()->getHero()->state=ROLE_DEFAULT;
    }
}