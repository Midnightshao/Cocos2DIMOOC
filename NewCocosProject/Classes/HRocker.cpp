//
//  HRocker.cpp
//  NewCocosProject
//
//  Created by 广昊 邵 on 2017/4/11.
//
//

#include "HRocker.hpp"
#define PI 3.141592654
HRocker * HRocker::createHRocker(const char * rockerImageName,const char * rockerBGImageName,Vec2 position){
    
    HRocker * layer=HRocker::create();
    if(layer){
        layer->rockerInit(rockerImageName, rockerBGImageName, position);
    }else{
        CC_SAFE_DELETE(layer);
        return nullptr;
    }
    return layer;
}

void HRocker::rockerInit(const char * rockerImageName, const char * rockerBGImageName, Vec2 position){
    
    auto spRockerBG=Sprite::create(rockerBGImageName);
    spRockerBG->setPosition(position);
    spRockerBG->setVisible(false);
    this->addChild(spRockerBG,0,tag_rockerBG);
    
    auto spRocker=Sprite::create(rockerImageName);
    spRocker->setPosition(position);
    spRocker->setVisible(false);
    this->addChild(spRocker,0,tag_rocker);
    
    rockerBGPosition=position;
    rockerBGR=spRockerBG->getContentSize().width/2;
    rockerDirection =-1;
    isCanMove=false;
}

void HRocker::startRocker(bool _isStopOther){
    
    auto rocker=(Sprite *)this->getChildByTag(tag_rockerBG);
    rocker->setVisible(true);
    
    auto rockerBG=(Sprite *)this->getChildByTag(tag_rocker);
    rockerBG->setVisible(true);
    
    
    auto touchListener=EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(false);
    
    touchListener->onTouchBegan=CC_CALLBACK_2(HRocker::onTouchBegan,this);
    touchListener->onTouchMoved=CC_CALLBACK_2(HRocker::onTouchMoved,this);
    touchListener->onTouchEnded=CC_CALLBACK_2(HRocker::onTouchEnded,this);
    
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

}
void HRocker::stopRocker(){
    
    auto rocker=(Sprite *)this->getChildByTag(tag_rocker);
    rocker->setVisible(true);
    
    auto rockerBG=(Sprite *)this->getChildByTag(tag_rockerBG);
    rockerBG->setVisible(false);
    
    _eventDispatcher->removeEventListenersForTarget(this);
}
bool HRocker::onTouchBegan(Touch * touch,Event * unused_event){
    
    
    Vec2 point=touch->getLocation();
    auto rocker=(Sprite *)this->getChildByTag(tag_rocker);
    if(rocker->getBoundingBox().containsPoint(point)){
        isCanMove = true;
        log("begin");
    }
    
    return true;
}

Vec2 HRocker::getAnglePosition(float r,float angle){
    return Vec2(r*cos(angle),r*sin(angle));
}

float HRocker::getRad(Vec2 pos1, Vec2 pos2){
    float px1 =pos1.x;
    float py1 =pos1.y;
    float px2 =pos2.x;
    float py2 =pos2.y;
    
    float x=px2-px1;
    float y=py2-py1;
    
    float xie=sqrt(pow(x,2)+pow(y,2));
    float cosAngle=x/xie;
    float rad=acos(cosAngle);
    
    
    if(py2<py1){
        rad=-rad;
    }
    return rad;
}
void HRocker::onTouchMoved(Touch * touch,Event * unused_event){
    if(!isCanMove){
        return;
    }
    Vec2 point=touch->getLocation();
    
    auto rocker=(Sprite *)this->getChildByTag(tag_rocker);

    float angle=getRad(rockerBGPosition, point);
    
    if(sqrt(pow(rockerBGPosition.x-point.x,2)+pow(rockerBGPosition.y-point.y,2)) >= rockerBGR){
        rocker->setPosition(ccpAdd(getAnglePosition(rockerBGR, angle),rockerBGPosition));
    }else{
        rocker->setPosition(point);
    }
    if(angle>= -PI/4 && angle <PI/4){
        rockerDirection=rocker_right;
        CCLOG("Right,Right,Right,Right,Right,Right,Right6666666666");
    }
    else if(angle >= PI/4 && angle<3*PI/4){
        rockerDirection=rocker_up;
        CCLOG("Right,Right,Right,Right,Right,Right,Right7777777777777");
    }
    else if((angle >= 3*PI/4 && angle<PI)||(angle>=-PI && angle<-3*PI/4)){
        rockerDirection=rocker_left;
    }
    else if(angle >= -3*PI/4 && angle<-PI/4){
        rockerDirection=rocker_down;
    }
}
void HRocker::onTouchEnded(Touch * touch,Event * unused_event){
    if(!isCanMove){
        return;
    }
    auto rocker=(Sprite *)this ->getChildByTag(tag_rocker);
    auto rockerBG=(Sprite *)this->getChildByTag(tag_rockerBG);
    
    rocker->stopAllActions();
    rocker->runAction(MoveTo::create(0.08f, rockerBGPosition));
    isCanMove = false;
    rockerDirection = rocker_stay;
}






























