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
	GameSystem gameSystem;		//ゲームシステム
public:
	bool Init();
	//実行処理
	bool Run();
};

#endif // !STG_GAMERUNSYSTEM_H