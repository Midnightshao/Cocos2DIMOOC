//
//  DialogLayer.hpp
//  NewCocosProject
//
//  Created by 广昊 邵 on 2017/5/5.
//
//

#ifndef DialogLayer_hpp
#define DialogLayer_hpp
#include "iostream"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace cocostudio;
using namespace ui;
using namespace rapidjson;
class DialogLayer : public Layer{
public:
    static DialogLayer * createWithJionFile(const char *filename);
    bool init(std::string str);
    void  MultUpate(float dt);
    void getDataByIndex(int idx);
    void showAllContent();
    void initStudioScene(const char * csbFile);
    void pushChinseStr(std::string str,std::vector<std::string> &strVector);
    void touchDownAction(Ref *sender,Widget::TouchEventType controlEvent);
    
private:
    bool _isOver;
    int index;
    
    
    std::string conversation;
    std::vector<std::string> _conVector;
    
    Text * speetch;
    Text * name;
    ImageView *icon;
    
    std::string mStr;
    std::string tempStr;
    std::vector<std::string>strVector;
    int vecLength;
};

#endif /* DialogLayer_hpp */
