#ifndef STG_BACKGROUND_H
#define STG_BACKGROUND_H

#include "Task.h"

//ゲーム画面に表示するBackgroundクラス
class Background final {
private:

public:
	//更新処理
	void Update(GameSystem* _gameSystem);
	//描画処理
	void Draw(GameSystem* _gameSystem);
};

#endif // !STG_BACKGROUND_H
