//
//  FlyText.cpp
//  NewCocosProject
//
//  Created by 广昊 邵 on 2017/4/30.
//
//

#include "FlyText.hpp"
FlyText * FlyText::create(const char * str){
    FlyText * flyText=new FlyText();
    if(flyText && flyText->init(str)){
        flyText->autorelease();
    }else{
        CC_SAFE_FREE(flyText);
    }
    return flyText;
};
bool FlyText::init(const char * str){
    label=Label::createWithSystemFont(str, "", 30);
    
    label->setColor(Color3B::BLUE);
    
    this->addChild(label);
    return true;
};
void FlyText::startAnimation(){
    auto easeIn=EaseExponentialIn::create(Spawn::create(MoveBy::create(.7f, Vec2(0,150)),FadeOut::create(.7), nullptr));
    auto sequence =Sequence::create(easeIn,CallFunc::create([&](){this->removeObject();}),nullptr);
    
    label->runAction(sequence);
};
void FlyText::removeObject(){
    stopAllActions();
    removeAllChildrenWithCleanup(true);
    this->removeFromParent();
}