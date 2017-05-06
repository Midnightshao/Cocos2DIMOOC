//
//  DataManager.hpp
//  NewCocosProject
//
//  Created by 广昊 邵 on 2017/4/30.
//
//

#ifndef DataManager_hpp
#define DataManager_hpp

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;
class DataManager{

public:
    static DataManager *getInstance();
    
    void initWithJsonFile(const char * filename);
    
    std::vector<std::string> getLevelDataArrayByIndex(int index);
    
public:
    std::string tollgateData;
    std::vector<std::string> _levelDataArray;
    CC_SYNTHESIZE(int,levelIndex,LevelIndex);
    
};

#endif /* DataManager_hpp */
