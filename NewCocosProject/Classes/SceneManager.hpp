//
//  SceneManager.hpp
//  NewCocosProject
//
//  Created by 广昊 邵 on 2017/4/10.
//
//

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;


class SceneManager{
    public :
    Scene * startScene;
    Scene * gameScene;
    Scene * ImageView;
    
    void createScene();
    void toGameScene();

};
#include "cocos2d.h"
#endif /* SceneManager_hpp */
