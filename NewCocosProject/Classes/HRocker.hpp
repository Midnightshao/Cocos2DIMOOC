//
//  HRocker.hpp
//  NewCocosProject
//
//  Created by 广昊 邵 on 2017/4/11.
//
//

#ifndef HRocker_hpp
#define HRocker_hpp
#include <iostream>
#include "cocos2d.h"
USING_NS_CC;
using namespace ui;
typedef enum {
    tag_rocker,
    tag_rockerBG
}tImageFormat;


typedef enum {
    rocker_stay=0,
    rocker_right=1,
    rocker_up,
    rocker_left,
    rocker_down
}tagDirection;

class HRocker :public Layer{
public:
    static HRocker * createHRocker(const char *rockerImageName,const char *rockerBGImageName,Vec2 position);
    
    void startRocker(bool _isStopOther);
    
    void stopRocker();
    
    int rockerDirection;
    
    Vec2 getAnglePosition(float r,float angle);
    
    bool rockerRun;
    
    CREATE_FUNC(HRocker);
private:
    void rockerInit(const char * rockerImageName,const char*rockerBGImageName,Vec2 position);
    bool isCanMove;
    float getRad(Vec2 pos1,Vec2 pos2);
    Vec2 rockerBGPosition;
    float rockerBGR;
    
    bool onTouchBegan(Touch * touch,Event * unused_event);
    void onTouchMoved(Touch * touch,Event * unused_event);
    void onTouchEnded(Touch * touch,Event * unused_event);
};

#endif /* HRocker_hpp */
