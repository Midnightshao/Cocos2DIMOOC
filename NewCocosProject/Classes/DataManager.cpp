//
//  DataManager.cpp
//  NewCocosProject
//
//  Created by 广昊 邵 on 2017/4/30.
//
//
#include "DataManager.hpp"
//这里可以随便找
#include "json/rapidjson.h"
#include "json/document.h"
using namespace rapidjson;
static DataManager * dataManager = nullptr;
DataManager *DataManager::getInstance(){
    if(dataManager == nullptr){
        dataManager=new DataManager();
    }
    return dataManager;
};

void DataManager::initWithJsonFile(const char * filename){
    tollgateData = FileUtils::getInstance()->getStringFromFile(filename);
    log("打印json数据 %s",tollgateData.c_str());
}

std::vector<std::string> DataManager::getLevelDataArrayByIndex(int index){
//    CCLOG("+++++++++++++++++++++++++++++++++++++_________________________________________");
    Document doc;
    doc.Parse<kParseDefaultFlags>(tollgateData.c_str());
    _levelDataArray.clear();
    rapidjson::Value &array=doc["Tollgate"];
    if(array.IsArray()){
        int i = index;
        int j = 0;
        for(j=0;j<array[i]["RoleData"].Size();j++){
            rapidjson::Value & str=array[i]["RoleData"][j];
            log("test str is %s",str.GetString());
            _levelDataArray.push_back(str.GetString());
        }
    }
    CCLOG("+++++++++++++++++++++++++++++++++++++_________________________________________");
    
    
    return _levelDataArray;
};