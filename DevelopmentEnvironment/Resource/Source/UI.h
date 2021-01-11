#ifndef STG_UI_H
#define STG_UI_H

#include "Task.h"

//ゲーム画面に表示するUIクラス
class UI final {
private:

public:
	//更新処理
	void Update(GameSystem* _gameSystem);
	//描画処理
	void Draw(GameSystem* _gameSystem);
};

#endif // !STG_UI_H