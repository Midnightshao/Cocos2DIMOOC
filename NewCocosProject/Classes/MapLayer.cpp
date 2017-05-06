//
//  MapLayer.cpp
//  NewCocosProject
//
//  Created by 广昊 邵 on 2017/4/11.
//
//

#include "MapLayer.hpp"
bool MapLayer::init(){
    return true;
}
void MapLayer::setBackGround(const char*filename){

    if( bgImageView == nullptr){
        
        bgImageView=ImageView::create();
        
        bgImageView->setScale(2.0, 2.5);
        
        bgImageView->setAnchorPoint(Point::ZERO);
        
        bgImageView->setPosition(Point::ZERO);
        
        this->addChild(bgImageView);
    }
    bgImageView->loadTexture(filename);
}