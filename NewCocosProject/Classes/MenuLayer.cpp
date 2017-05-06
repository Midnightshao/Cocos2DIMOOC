//
//  MenuLayer.cpp
//  NewCocosProject
//
//  Created by 广昊 邵 on 2017/4/10.
//
//

#include "MenuLayer.hpp"
bool MenuLayer::init(){
    
    Node * node =CSLoader::createNode("res/MenuScene.csb");
    
//    Layout *layout=static_cast<Layout *>(node ->getChildByTag(1));
    
    Button *button=static_cast<Button *>(node->getChildByTag(8));
    
    button->addTouchEventListener(CC_CALLBACK_2(MenuLayer::touchCallBack, this));
    
    this->addChild(node);
    
    return true;
}

void MenuLayer::touchCallBack(Ref * sender, Widget::TouchEventType controlEvent){
    if(controlEvent==Widget::TouchEventType::ENDED){
        auto button=static_cast<Button *>(sender);
        if(button->getTag()==8){
            tsm->toGameScene();
        }
    }
}
