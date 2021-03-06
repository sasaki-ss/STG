#ifndef STG_TASK_H
#define STG_TASK_H

#include "GameSystem.h"

//タスククラス
class Task {
public:
	//初期化処理
	virtual void Init(){}
	//終了処理
	virtual void Final(){}
	//更新処理
	virtual void Update(GameSystem* _gameSystem) = 0;
	//描画処理
	virtual void Draw(GameSystem* _gameSystem) = 0;
};

#endif // !STG_TASK_H