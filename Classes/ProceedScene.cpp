//
//  ProceedScene.cpp
//  BlackWhiteRush
//
//  Created by 何遵祖 on 13-12-29.
//
//

#include "ProceedScene.h"
#include "ProceedView.h"
#include "ProceedController.h"

bool ProceedScene::init(){
    if (!CCScene::init()) {
        return false;
    }
    
    //将精灵表中的.plist文件加进缓冲区
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("gElement.plist");
    
    ProceedView *proView = ProceedView::create();
    this->addChild(proView,ViewZOrder);
    
    ProceedController *pController = ProceedController::create();
    this->addChild(pController,ControllerZOrder);
    
    //游戏逻辑关联主渲染场景
    GameLogic::Singleton()->setPView(proView);
    
    return true;
}
