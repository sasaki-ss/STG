#include <DxLib.h>
#include "InGame.h"

//コンストラクタ
InGame::InGame(ISceneChanger* _sceneChanger, ShareParameter* _shareParameter) :
	Scene(_sceneChanger, _shareParameter) {
	//オブジェクトを生成
	player = new Player(500, 500, 32, 64, 10);
	bulletManager = new BulletManager();
	enemyManager = new EnemyManager(0);
}

//初期化処理
void InGame::Init(GameSystem* _gameSystem) {
	//各オブジェクトをオブジェクト構造体へ格納する
	_gameSystem->SetObjectsPlayer(player);
	_gameSystem->SetObjectsBulletManager(bulletManager);
	_gameSystem->SetObjectsEnemyManager(enemyManager);
}

//更新処理
void InGame::Update(GameSystem* _gameSystem) {
	player->Update(_gameSystem);
	bulletManager->Update(_gameSystem);
	enemyManager->Update(_gameSystem);
}

//描画処理
void InGame::Draw(GameSystem* _gameSystem) {
	player->Draw(_gameSystem);
	bulletManager->Draw(_gameSystem);
	enemyManager->Draw(_gameSystem);

	//デバック用
	DrawFormatString(1000, 0, GetColor(255, 255, 255), "bulletsのアクティブ数 : %d",
		bulletManager->GetActiveCount());
	DrawFormatString(1000, 25, GetColor(255, 255, 255), "enemysのアクティブ数 : %d",
		enemyManager->GetActiveCount());
}