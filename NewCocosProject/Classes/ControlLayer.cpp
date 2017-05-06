//
//  ControlLayer.cpp
//  NewCocosProject
//
//  Created by 广昊 邵 on 2017/4/11.
//
//
#include "MapLayer.hpp"
#include "ControlLayer.hpp"
#include "OperateLayer.hpp"
#include "HRocker.hpp"
#include "BaseFSM.hpp"
#include "propertyManager.hpp"
#include "BaseRole.hpp"
#include "BaseAi.hpp"
#include "DataManager.hpp"
#include "DialogLayer.hpp"
#include "RoleCardController.hpp"
bool ControlLayer::init(){
    
    for(int i=0;i<DataManager::getInstance()->getLevelDataArrayByIndex(DataManager::getInstance()->getLevelIndex()).size();i++){

        auto roleMap=FileUtils::getInstance()->getValueMapFromFile(DataManager::getInstance()->_levelDataArray[i]);
        propertyManager *pManager=propertyManager::create();
        pManager->setArmatureName((roleMap["ArmatureName"].asString()));
        pManager->setDataName(roleMap["DataName"].asString());
        pManager->setATK(roleMap["ATK"].asInt());
        pManager->setHP(roleMap["HP"].asInt());
        pManager->setID(roleMap["ID"].asInt());
        pManager->setSpeed(roleMap["Speed"].asInt());
        pManager->setLockmit(roleMap["LockLimit"].asInt());
        pManager->setATKLimit(roleMap["ATKLimit"].asInt());
        pManager->setPlayerName(roleMap["PlayerName"].asString());
        pManager->setHitRect(RectFromString(roleMap["HitRect"].asString()));
        pManager->setHitPoint(pManager->getHitRect().origin);
        pManager->setGetHitRect(RectFromString(roleMap["GetHitRect"].asString()));
        pManager->setGetHitPoint(pManager->getGetHitRect().origin);
        pManager->retain();
        
        BaseRole * hero = BaseRole::createWithPorperty(pManager);
        hero ->setPosition(Vec2(200,200));
        hero->type=static_cast<ROLE_TYPE>(roleMap["Type"].asInt());
        this->addChild(hero,1,1);
        
        if(hero->type==TYPE_MONSTER){
            RoleCardController::getInstance()->monsterVec.push_back(hero);
            hero->setPosition(Vec2(Director::getInstance()->getVisibleSize().width*0.8,Director::getInstance()->getVisibleSize().width*0.4));
        }else if(hero->type==TYPE_HERO){
            RoleCardController::getInstance()->heroVec.push_back(hero);
            hero->setPosition(Vec2(Director::getInstance()->getVisibleSize().width*0.2,Director::getInstance()->getVisibleSize().width*0.4));
        }
        
        log("xxxxxx---------------------------");
        
        BaseAi * ai = BaseAi::createAI(hero);
        ai->retain();
        hero->setBaseAi(ai);
        ai->startRoleAI();

        BaseFSM * baseFSM = BaseFSM::createrFSM(hero);
        baseFSM->retain();
        hero->setBaseFSM(baseFSM);
        
        RoleCardController::getInstance()->setHeroID(1);

        
    }
    //        BaseFSM * baseFSM_2 = BaseFSM::createrFSM(monster);
    //        baseFSM_2->retain();
    //        monster->setBaseFSM(baseFSM_2);
    //        //  --------------------------------------------------------------------------
    //        BaseAi *ai = BaseAi::createAI(hero);
    //        ai->retain();
    //        hero->setBaseAi(ai);
    //
    //        BaseAi *ai_2 = BaseAi::createAI(monster);
    //        ai_2->retain();
    //        monster->setBaseAi(ai_2);

    //    auto roleMap=FileUtils::getInstance()->getValueMapFromFile("rodeData/hero.plist");
//    propertyManager *pManager=propertyManager::create();
//    pManager->setArmatureName((roleMap["ArmatureName"].asString()));
//    pManager->setDataName(roleMap["DataName"].asString());
//    pManager->setATK(roleMap["ATK"].asInt());
//    pManager->setHP(roleMap["HP"].asInt());
//    pManager->setID(roleMap["ID"].asInt());
//    pManager->setSpeed(roleMap["Speed"].asInt());
//    pManager->setLockmit(roleMap["LockLimit"].asInt());
//    pManager->setATKLimit(roleMap["ATKLimit"].asInt());
//    pManager->setPlayerName(roleMap["PlayerName"].asString());
//    pManager->setHitRect(RectFromString(roleMap["HitRect"].asString()));
//    pManager->setHitPoint(pManager->getHitRect().origin);
//    pManager->setGetHitRect(RectFromString(roleMap["GetHitRect"].asString()));
//    pManager->setGetHitPoint(pManager->getGetHitRect().origin);
//    pManager->retain();
//    
//    hero = BaseRole::createWithPorperty(pManager);
//    hero ->setPosition(Vec2(200,200));
//    hero->type=static_cast<ROLE_TYPE>(roleMap["Type"].asInt());
//    this->addChild(hero,1,1);
//    RoleCardController::getInstance()->heroVec.push_back(hero);
    
    
    
    
//    auto mousterMap=FileUtils::getInstance()->getValueMapFromFile("rodeData/mouster1.plist");
//    propertyManager *pManager1=propertyManager::create();
//    pManager1->setArmatureName((mousterMap["ArmatureName"].asString()));
//    pManager1->setDataName(mousterMap["DataName"].asString());
//    pManager1->setATK(mousterMap["ATK"].asInt());
//    pManager1->setHP(mousterMap["HP"].asInt());
//    pManager1->setID(mousterMap["ID"].asInt());
//    pManager1->setSpeed(mousterMap["Speed"].asInt());
//    pManager1->setLockmit(mousterMap["LockLimit"].asInt());
//    pManager1->setATKLimit(mousterMap["ATKLimit"].asInt());
//    pManager1->setPlayerName(mousterMap["PlayerName"].asString());
//    pManager1->setHitRect(RectFromString(mousterMap["HitRect"].asString()));
//    pManager1->setHitPoint(pManager1->getHitRect().origin);
//    pManager1->setGetHitRect(RectFromString(mousterMap["GetHitRect"].asString()));
//    pManager1->setGetHitPoint(pManager1->getGetHitRect().origin);
//    pManager1->retain();
//    
//    monster=BaseRole::createWithPorperty(pManager1);
//    monster ->setPosition(Vec2(700,200));
//    monster->type=static_cast<ROLE_TYPE>(mousterMap["Type"].asInt());
//    this->addChild(monster,2,1);
//    RoleCardController::getInstance()->monsterVec.push_back(monster);

    
//  -------------------------------------------------------------------------
//    BaseFSM * baseFSM = BaseFSM::createrFSM(hero);
//        baseFSM->retain();
//    hero->setBaseFSM(baseFSM);
//    
//    BaseFSM * baseFSM_2 = BaseFSM::createrFSM(monster);
//        baseFSM_2->retain();
//    monster->setBaseFSM(baseFSM_2);
////  --------------------------------------------------------------------------
//    BaseAi *ai = BaseAi::createAI(hero);
//        ai->retain();
//    hero->setBaseAi(ai);
//    
//    BaseAi *ai_2 = BaseAi::createAI(monster);
//        ai_2->retain();
//    monster->setBaseAi(ai_2);
//    --------------------------------------------------------------------
    //打开Ai
//        ai->startRoleAI();
//        ai_2->startRoleAI();
    
    MapLayer * mapLayer=MapLayer::create();
    mapLayer->setBackGround("changjing.jpg");
    this->addChild(mapLayer);
    
//    RoleCardController::getInstance()->setHeroID(1);
    
    
    OperateLayer * operateLayer=OperateLayer::create();
    this->addChild(operateLayer);
    rocker=HRocker::createHRocker("center.png","direction.png",Vec2(100,100));
    rocker->startRocker(true);
    
    this->addChild(rocker);
    
    Director::getInstance()->getScheduler()->schedule(schedule_selector(ControlLayer::update),this,(float)1/60,false);
    
    DialogLayer * dialog=DialogLayer::createWithJionFile("1.json");
   
    this->addChild(dialog,10);
    
    
    return true;
}
void ControlLayer::update(float dt){
    
    if(RoleCardController::getInstance()->getHero() !=nullptr){
        RoleCardController::getInstance()->getHero()->getBaseFSM()->swtichMoveState(rocker->rockerDirection);
    }
    
    
    std::vector<BaseRole *>::iterator itr1=RoleCardController::getInstance()->heroVec.begin();
    
    while (itr1!=RoleCardController::getInstance()->heroVec.end()) {
        if((*itr1)->state==Role_FREE){
            (*itr1)->purge();
            RoleCardController::getInstance()->heroVec.erase(itr1);
            break;
        }
        ++itr1;
    }
    
    if(RoleCardController::getInstance()->heroVec.size()==0){
        CCLOG("输了。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。");
        this->purge();
    }

    std::vector<BaseRole *>::iterator itr=RoleCardController::getInstance()->monsterVec.begin();

    while (itr!=RoleCardController::getInstance()->monsterVec.end()) {
        if((*itr)->state==Role_FREE){
            (*itr)->purge();
            RoleCardController::getInstance()->monsterVec.erase(itr);
            break;
        }
        ++itr;
    }
    if(RoleCardController::getInstance()->monsterVec.size()==0){
        if(DataManager::getInstance()->getLevelIndex()==2){
            return;
        }
        this->purge();
        CCLOG("赢了。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。");
        DataManager::getInstance()->setLevelIndex(DataManager::getInstance()->getLevelIndex()+1);
        
        this->tsm->toGameScene();
    }
}
    void ControlLayer::purge(){
        Director::getInstance()->getScheduler()->unschedule(schedule_selector(ControlLayer::update),this);
        RoleCardController::getInstance()->purge();
        this->removeFromParent();
    }