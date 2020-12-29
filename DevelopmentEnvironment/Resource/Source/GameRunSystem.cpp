#include <DxLib.h>
#include "GameRunSystem.h"

bool GameRunSystem::Init(GameSystem* _gameSystem) {
	sceneManager = new SceneManager(_gameSystem);

	sceneManager->GetParameter()->SetData("IS_RUN_GAME", 1);

	return true;
}

//実行処理
bool GameRunSystem::Run(GameSystem* _gameSystem) {
	//どこかでエラーが発生した際終了させる
	if (sceneManager->GetParameter()->GetData("IS_RUN_GAME") ==
		static_cast<int>(GameRunState::Exit)) {
		return false;
	}

	_gameSystem->GetInputManager()->GetKeyboard()->Update();

	DrawFormatString(0, 0, GetColor(255, 255, 255), "ゲーム実行システムクラス実行処理");
	DrawFormatString(0, 25, GetColor(255, 255, 255), "%d", static_cast<int>(sceneManager->GetNowScene()));

	//シーンの更新処理
	sceneManager->Update(_gameSystem);
	//シーンの描画処理
	sceneManager->Draw(_gameSystem);

	return true;
}