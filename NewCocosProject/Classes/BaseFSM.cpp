//
//  BaseFSM.cpp
//  NewCocosProject
//
//  Created by 广昊 邵 on 2017/4/16.
//
//

#include "BaseFSM.hpp"
BaseFSM *BaseFSM::createrFSM(BaseRole *baseRole){
    BaseFSM *baseFSM=new BaseFSM();
    
    if(baseFSM && baseFSM->init(baseRole)){
        baseFSM->autorelease();
    }else{
        CC_SAFE_DELETE(baseFSM);
    }
    return baseFSM;
};
bool BaseFSM::init(BaseRole * baseRole){
    role=baseRole;
    return true;
}

void BaseFSM::swtichMoveState(int dir){
    if(role->state ==ROLE_ATTACK){
        retain();
    }
    switch (dir) {
        case 0:
            this->changeToDefault();
            break;
        case 1:
            this->changeToRight();
            CCLOG("Right,122223333333333333332");
            break;
        case 3:
            this->changeToLeft();
            CCLOG("Right,122223333333333333332");
            break;
        default:
            
            role->getarmature()->stopAllActions();
            break;
    }

}
void BaseFSM::changeToDefault(){
    //是不是默认状态
    if(role->state!=ROLE_DEFAULT&&role ->state!=Role_DEAD){
        role->state=ROLE_DEFAULT;
        role->getarmature()->getAnimation()->play("default");
    }
}
void BaseFSM::changeToAttack(){
//    CCLog("攻击");
    //是不是默认状态
    if(role->state!=ROLE_ATTACK&&role ->state!=Role_DEAD){
        role->state=ROLE_ATTACK;
        role->getarmature()->getAnimation()->play("attack",-1,0);
    }
}
//向左
void BaseFSM::changeToLeft(){
    if(role->state!=ROLE_MOVE && role->state!=Role_DEAD){
        role->state=ROLE_MOVE;
    }
    /* 人朝左， 脸朝右 播放的应该是前进动画if */
    if(role ->face ==FACE_LEFT){
        std::string movent= role->getarmature()->getAnimation()->getCurrentMovementID();
        char * nowMovent =const_cast<char *>(movent.c_str());
        if(strcmp(nowMovent, "run_back")!=0){
            role->getarmature()->getAnimation()->play("run_back");
        }
    }
    else{
        std::string movent= role->getarmature()->getAnimation()->getCurrentMovementID();
        char * nowMovent =const_cast<char *>(movent.c_str());
        if(strcmp(nowMovent, "")!=0){
            role->getarmature()->getAnimation()->play("run_back");
        }
    }

    role->setPosition(Vec2(role->getPositionX()-role->property->getSpeed(),role->getPositionY()));
}
void BaseFSM::changeToRight(){
    if(role->state!=ROLE_MOVE && role->state!=Role_DEAD){
        role->state=ROLE_MOVE;
    }
    /* 人朝右， 脸朝右 播放的应该是前进动画if */
    if(role->face == FACE_RIGHT){
        std::string movent= role->getarmature()->getAnimation()->getCurrentMovementID();
        char * nowMovent =const_cast<char *>(movent.c_str());
        if(strcmp(nowMovent, "run_front")!=0){
            CCLOG("Right,faceRight,faceRight,faceRight");
            role->getarmature()->getAnimation()->play("run_front");
        }
    }
    else{
        std::string movent= role->getarmature()->getAnimation()->getCurrentMovementID();
        char * nowMovent =const_cast<char *>(movent.c_str());
        if(strcmp(nowMovent, "run_back")!=0){
            role->getarmature()->getAnimation()->play("run_front");
        }
    }
    role->setPosition(Vec2(role->getPositionX()+role->property->getSpeed(),role->getPositionY()));
}
void BaseFSM::changeToDead(){
    //是不是默认状态
    if(role->state!=Role_DEAD){
        role->state=Role_DEAD;
        role->getarmature()->getAnimation()->play("gethit",-1,0);
    }
}

void BaseFSM::changeToEnmeny(){

}
void BaseFSM::purge(){
    role=nullptr;
    CC_SAFE_RELEASE(this);
}