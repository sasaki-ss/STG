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
	//背景の描画
	buckground.Draw(_gameSystem);

	//UIの描画
	ui.Draw(_gameSystem);

	//ゲーム実行中の処理
	if (!gameManager->GetIsGameOver()) {
		bulletManager->Draw(_gameSystem);
		player->Draw(_gameSystem);
		enemyManager->Draw(_gameSystem);
	}
	//ゲームオーバー時の処理
	else {
		DrawString(300, 300, "GAME OVER", GetColor(255, 255, 255));
	}

	//ゲーム画面の枠組みを表示
	DrawGraph(0, 0, _gameSystem->GetImage()->GetGraph("InGame_Front_BG.png"), TRUE);


	//デバック用
	DrawFormatString(1000, 0, GetColor(255, 255, 255), "playerの残基　　　　  : %d",
		player->GetResidue());
	DrawFormatString(1000, 25, GetColor(255, 255, 255), "bulletsのアクティブ数 : %d",
		bulletManager->GetActiveCount());
	DrawFormatString(1000, 50, GetColor(255, 255, 255), "enemysのアクティブ数　: %d",
		enemyManager->GetActiveCount());
}