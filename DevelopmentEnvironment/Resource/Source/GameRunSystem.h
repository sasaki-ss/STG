#ifndef STG_GAMERUNSYSTEM_H
#define STG_GAMERUNSYSTEM_H

#include "SceneManager.h"
#include "CloseSystem.h"
#include "GameSystem.h"

//ゲーム実行システムクラス
class GameRunSystem final :public CloseSystem {
private:
	//ゲーム実行の状態
	enum class GameRunState {
		Exit,	//終了
		Run		//実行中
	};

	SceneManager* sceneManager;	//シーンマネージャー
public:
	//初期化処理
	bool Init(GameSystem* _gameSystem);
	//実行処理
	bool Run(GameSystem* _gameSystem);
};

#endif // !STG_GAMERUNSYSTEM_H