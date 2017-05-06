//
//  DialogLayer.cpp
//  NewCocosProject
//
//  Created by 广昊 邵 on 2017/5/5.
//
//
#include "DialogLayer.hpp"
void  DialogLayer::pushChinseStr(std::string str,std::vector<std::string> &strVector){
    
    int sum=strlen(str.c_str());
    
    for(int cur=0;cur<sum;){
    
        std::string lines;
        char t=str[cur];
        
        if((t & 0xE0) == 0xE0){
            lines=lines + t + str[cur+1] +str[cur+2];
            cur+=3;
        }
        else if((t & 0xC0) == 0xC0){
            lines=lines+t+str[cur+1] +str[cur+2];
            cur+=2;
        }else{
            lines = lines+t;
            cur ++;
        }
        log("steaming text : %s",lines.c_str());
        strVector.push_back(lines);
    }
    
}

DialogLayer * DialogLayer::createWithJionFile( const char *filename){
    DialogLayer * dialogLayer= new DialogLayer();
    
    if(dialogLayer && dialogLayer->init(filename)){
        dialogLayer->autorelease();
    }else{
        CC_SAFE_DELETE(dialogLayer);
    };
    return dialogLayer;
}

bool DialogLayer::init(std::string str){
    
    initStudioScene("Layer.csb");
    
    conversation = FileUtils::getInstance()->getStringFromFile(str);
    
    index = 0 ;
    
    getDataByIndex(index);
    
    
    return true;
};
void  DialogLayer::MultUpate(float dt){
    
    if(vecLength<(int)strVector.size()){
        tempStr=tempStr+strVector[vecLength].c_str();
        speetch->setString(tempStr.c_str());
        vecLength++;
    }else{
        _isOver=true;
        unschedule(schedule_selector(DialogLayer::MultUpate));
    }
    
}
void DialogLayer::getDataByIndex(int idx){
    Document doc;
    log("x-------------11111112222222223333333344444");
    doc.Parse<kParseDefaultFlags>(conversation.c_str());
    
    _conVector.clear();
    _isOver=false;
    rapidjson::Value & array = doc["Conversation"];
    
    if(array.IsArray()){
        int i=idx;
        int j=0;
        strVector.clear();
        
        if(i>=array.Size()){
            this->removeFromParent();
            return;
        }
        for(j=0;j<array[i]["content"].Size();j++){
            rapidjson::Value & str = array[i]["content"][j];
            mStr = str.GetString();
            log("test str %s",mStr.c_str());
            _conVector.push_back(str.GetString());
            if(j==2){
                pushChinseStr(mStr,strVector);
            }
        }
        name->setString(_conVector[0]);
        icon->loadTexture(_conVector[1]);
    }
    tempStr="";
    schedule(CC_SCHEDULE_SELECTOR(DialogLayer::MultUpate),.1f );
}
void DialogLayer::showAllContent(){
    _isOver=true;
    schedule(schedule_selector(DialogLayer::MultUpate),.1f);
    speetch->setString(mStr.c_str());
}
void DialogLayer::initStudioScene(const char * csbFile){
    
    Node *node =CSLoader::createNode(csbFile);
    
    Layout *layout = static_cast<Layout *>(node->getChildByTag(9));
    name = static_cast<Text *>(layout->getChildByTag(11));
    speetch=static_cast<Text *>(layout->getChildByTag(12));
    icon=static_cast<ImageView *>(layout->getChildByTag(10));
    icon->ignoreContentAdaptWithSize(true);
    layout->addTouchEventListener(CC_CALLBACK_2(DialogLayer::touchDownAction,this));


    this->addChild(node);
    
}
void DialogLayer::touchDownAction(Ref *sender,Widget::TouchEventType controlEvent){
    log("log++++++++++++++++++");
    if(controlEvent==Widget::TouchEventType::ENDED){
        if(_isOver==true){
            index++;
            getDataByIndex(index);
        }else{
            this->showAllContent();
        }
    }
}
