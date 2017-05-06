//
//  FlyText.hpp
//  NewCocosProject
//
//  Created by 广昊 邵 on 2017/4/30.
//
//

#ifndef FlyText_hpp
#define FlyText_hpp
USING_NS_CC;
#include <iostream>
#include "cocos2d.h"
class FlyText : public Node{
public:
    static FlyText * create(const char *str);
    bool init(const char *str);
    void startAnimation();
    void removeObject();
    
public:
       Label *label;
};
#endif /* FlyText_hpp */
