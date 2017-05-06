//
//  MapLayer.hpp
//  NewCocosProject
//
//  Created by 广昊 邵 on 2017/4/11.
//
//

#ifndef MapLayer_hpp
#define MapLayer_hpp

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
using namespace ui;
class MapLayer:public Layer{
public:
    CREATE_FUNC(MapLayer);
    virtual bool init();
    void setBackGround(const char * filename);
    private :
    ImageView * bgImageView;
};
#endif /* MapLayer_hpp */
