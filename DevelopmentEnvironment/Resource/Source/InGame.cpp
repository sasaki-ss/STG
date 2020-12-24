#include <DxLib.h>
#include "InGame.h"

//コンストラクタ
InGame::InGame(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter,
	GameSystem* _gameSystem) :
	Scene(_sceneChanger, _shareParameter, _gameSystem) {
	//オブジェクトを生成
	player = new Player(500, 500, 32, 64, 10);
	bulletManager = new BulletManager();
	enemyManager = new EnemyManager(0);

	//各オブジェクトをオブジェクト構造体へ格納する
	gameSystem->SetObjectsPlayer(player);
	gameSystem->SetObjectsBulletManager(bulletManager);
	gameSystem->SetObjectsEnemyManager(enemyManager);
}

//更新処理
void InGame::Update() {
	player->Update(gameSystem);
	bulletManager->Update(gameSystem);
	enemyManager->Update(gameSystem);
}

//描画処理
void InGame::Draw() {
	player->Draw(gameSystem);
	bulletManager->Draw(gameSystem);
	enemyManager->Draw(gameSystem);

	//デバック用
	DrawFormatString(1000, 0, GetColor(255, 255, 255), "bulletsのアクティブ数 : %d",
		bulletManager->GetActiveCount());
	DrawFormatString(1000, 25, GetColor(255, 255, 255), "enemysのアクティブ数 : %d",
		enemyManager->GetActiveCount());
}