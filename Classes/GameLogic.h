//
//  GameLogic.h
//  BlackWhiteRush
//
//  Created by 何遵祖 on 13-12-27.
//
//

#ifndef __BlackWhiteRush__GameLogic__
#define __BlackWhiteRush__GameLogic__

#include "cocos2d.h"
#include "GameObject.h"

class ProceedView;//关联的游戏显示

using namespace cocos2d;

#define LOG_GAMESTATE_ENABLED 0
#define UPDATE_INTERVAL 1.0f/60.0f
#define BACKGROUND_SPEED 100

//游戏模式(单人,多人)
enum GameModel {
    Model_Single,
    Model_Multiple
};

enum GameState {
    State_Playing, //进行
    State_Pause,   //暂停
    State_Start,   //开始(游戏开始倒数)
    State_End      //结束
};

class GameLogic : public CCObject{
public:
    static GameLogic* Singleton();//单例
    ~GameLogic();
    void end();
    void init();
    void update(float dt);
    
    /*队列*/
    void pushObject(GameObject* gameObject);
    void deleteObject(GameObject* gameObject);
    GameObject* popObjectFromType(ObjectType t);
    
    //输出游戏状态
    void logGameState(GameState s);
    //碰撞检测
    void collisionListener();
    //更新分数
    void updateScore();
    //移动对象
    void moveGameObject(float dt);
private:
    static GameLogic* _singletonObject;
    
    CCArray *_objects;
    CCScheduler *_pScheduler;

    CC_SYNTHESIZE(ProceedView*, _proceedview, PView);
    
    //游戏模式和状态
    CC_SYNTHESIZE(GameModel, _currentModel, Model);
    CC_SYNTHESIZE(GameState, _state, State);
    
    //分数以及分数的倍数
    CC_SYNTHESIZE(int, _score, Score);
    CC_SYNTHESIZE(int, _multiple, Multiple);
};

#endif /* defined(__BlackWhiteRush__GameLogic__) */
