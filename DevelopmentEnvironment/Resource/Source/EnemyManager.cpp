#include <DxLib.h>
#include "EnemyManager.h"

#include "Brainwasher.h"

//コンストラクタ
EnemyManager::EnemyManager(int _difficulty) {
	//初期化
	for (int i = 0; i < MAX_ENEMY_NUM; i++) {
		enemys[i] = nullptr;
	}

	activeCount = 0;

	//enemys[0] = new Enemy(500, 0, 32, 32, 3, 100);
	enemys[0] = new Brainwasher(64, 0, 32, 32, 2.0f, 100, 120);
	enemys[1] = new Brainwasher(164, 0, 32, 32, 2.0f, 100, 120);
	enemys[2] = new Brainwasher(264, 0, 32, 32, 2.0f, 100, 120);
	enemys[3] = new Brainwasher(364, 0, 32, 32, 2.0f, 100, 120);
	enemys[4] = new Brainwasher(464, 0, 32, 32, 2.0f, 100, 120);
	enemys[5] = new Brainwasher(564, 0, 32, 32, 2.0f, 100, 120);
	enemys[6] = new Brainwasher(664, 0, 32, 32, 2.0f, 100, 120);
	enemys[7] = new Brainwasher(764, 0, 32, 32, 2.0f, 100, 120);

	activeCount++;
}

//デストラクタ
EnemyManager::~EnemyManager() {
	delete[] enemys;
}

//更新処理
void EnemyManager::Update(GameSystem* _gameSystem) {
	//削除処理
	EnemyManager::Destroy();
	//整理処理
	EnemyManager::Organize();

	//更新処理
	for (int i = 0; i < activeCount; i++) {
		//enemys[i]が空でない場合
		if (enemys[i] != nullptr) {
			//更新処理
			enemys[i]->Update(_gameSystem);
		}
	}
}

//描画処理
void EnemyManager::Draw(GameSystem* _gameSystem) {
	for (int i = 0; i < activeCount; i++) {
		//enemys[i]が空でない場合
		if (enemys[i] != nullptr) {
			//描画処理
			enemys[i]->Draw(_gameSystem);
		}
	}
}

//整理処理
void EnemyManager::Organize() {
	int organizeCount = 0;	//整理カウンタ
	activeCount = 0;

	//アクティブな弾の数を求める
	for (int i = 0; i < MAX_ENEMY_NUM; i++) {
		//enemys[i]が空でない場合
		if (enemys[i] != nullptr) {
			//enemys[i]がアクティブな場合
			if (enemys[i]->GetIsActive()) {
				//アクティブカウンタを加算
				activeCount++;
			}
		}
	}

	//整理の処理
	for (int i = 0; i < MAX_ENEMY_NUM - 1; i++) {
		//enemys[i]が空の場合
		if (enemys[i] == nullptr) {
			for (int j = i + 1; j < MAX_ENEMY_NUM; j++) {
				//enemys[j]が空でない場合
				if (enemys[j] != nullptr) {
					//入れ替え処理
					Enemy* tmpEnemy = enemys[i];
					enemys[i] = enemys[j];
					enemys[j] = tmpEnemy;

					//整理カウンタを加算
					organizeCount++;
					break;
				}
			}

			//アクティブカウンタの数まで整理したらループを抜ける
			if (organizeCount == activeCount)break;
		}
	}
}

//削除処理
void EnemyManager::Destroy() {
	for (int i = 0; i < activeCount; i++) {
		//enemys[i]が空でない場合
		if (enemys[i] != nullptr) {
			//enemys[i]がアクティブでない場合
			if (!enemys[i]->GetIsActive()) {
				delete enemys[i];
				enemys[i] = nullptr;
			}
		}
	}
}

//ダメージ処理
void EnemyManager::Damage(int _num, int _damageAmount) {
	//enemys[_num]が空でない場合
	if (enemys[_num] != nullptr) {
		enemys[_num]->Damage(_damageAmount);
	}
}

//座標を取得する
Pos EnemyManager::GetPos(int _num) {
	//enemys[_num]が空でない場合
	if (enemys[_num] != nullptr) {
		return enemys[_num]->GetPos();
	}
}

//横幅を取得
float EnemyManager::GetWidth(int _num) {
	//enemys[_num]が空でない場合
	if (enemys[_num] != nullptr) {
		return enemys[_num]->GetWidth();
	}
}

//高さを取得
float EnemyManager::GetHeight(int _num) {
	//enemys[_num]が空でない場合
	if (enemys[_num] != nullptr) {
		return enemys[_num]->GetHeight();
	}
}

//アクティブ状態を取得する
bool EnemyManager::GetIsActive(int _num) {
	//enemys[_num]が空でない場合
	if (enemys[_num] != nullptr) {
		return enemys[_num]->GetIsActive();
	}
}