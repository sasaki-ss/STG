#include <DxLib.h>
#include "InGame.h"

//コンストラクタ
InGame::InGame(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter) :
	Scene(_sceneChanger, _shareParameter) {
	//オブジェクトを生成
	player = new Player(500, 500, 32, 64, 10);
	bulletManager = new BulletManager();
	enemyManager = new EnemyManager(0);
	gameManager = new GameManager();
}

//初期化処理
void InGame::Init(GameSystem* _gameSystem) {
	//各オブジェクトをゲームシステムに登録する
	_gameSystem->SetBulletManagerObj(bulletManager);
	_gameSystem->SetEnemyManagerObj(enemyManager);
	_gameSystem->SetPlayerObj(player);
}

//更新処理
void InGame::Update(GameSystem* _gameSystem) {
	//ゲーム実行中の処理
	if (!gameManager->GetIsGameOver()) {
		player->Update(_gameSystem);
		bulletManager->Update(_gameSystem);
		enemyManager->Update(_gameSystem);

		gameManager->Update(_gameSystem);
	}
	//ゲームオーバー時の処理
	else {
	}
}

//描画処理
void InGame::Draw(GameSystem* _gameSystem) {

	//ゲーム実行中の処理
	if (!gameManager->GetIsGameOver()) {
		bulletManager->Draw(_gameSystem);
		player->Draw(_gameSystem);
		enemyManager->Draw(_gameSystem);
	}
	//ゲームオーバー時の処理
	else {
		DrawString(500, 500, "GAME OVER", GetColor(255, 255, 255));
	}

	//デバック用
	DrawFormatString(1000, 0, GetColor(255, 255, 255), "playerの残基　　　　  : %d",
		player->GetResidue());
	DrawFormatString(1000, 25, GetColor(255, 255, 255), "bulletsのアクティブ数 : %d",
		bulletManager->GetActiveCount());
	DrawFormatString(1000, 50, GetColor(255, 255, 255), "enemysのアクティブ数　: %d",
		enemyManager->GetActiveCount());
}