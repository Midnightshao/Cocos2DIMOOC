//
//  SceneManager.cpp
//  NewCocosProject
//
//  Created by 广昊 邵 on 2017/4/10.
//
//
#include "cocos2d.h"
#include "ControlLayer.hpp"
#include "SceneManager.hpp"
#include "MenuLayer.hpp"
void SceneManager::createScene(){
    startScene=Scene::create();
    auto menuLayer=MenuLayer::create();
    menuLayer->tsm=this;
    startScene->addChild(menuLayer);
}
void SceneManager::toGameScene(){
    gameScene=Scene::create();
    ControlLayer *controlLayer = ControlLayer::create();
    controlLayer->tsm=this;
    gameScene->addChild(controlLayer);
    Director::getInstance()->replaceScene(gameScene);
}