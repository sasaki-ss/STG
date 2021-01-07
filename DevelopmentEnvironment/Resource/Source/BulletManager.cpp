#include "BulletManager.h"

#include "BulletP.h"
#include "BulletE_Normal.h"

//コンストラクタ
BulletManager::BulletManager() {
	//初期化
	for (int i = 0; i < MAX_BULLET_NUM; i++) {
		bullets[i] = nullptr;
	}

	activeCount = 0;
}

//デストラクタ
BulletManager::~BulletManager() {
	delete[] bullets;
}

//更新処理
void BulletManager::Update(GameSystem* _gameSystem) {
	//削除処理
	BulletManager::Destroy();
	//整理処理
	BulletManager::Organize();

	//敵の弾の更新処理
	for (int i = 0; i < activeCount; i++) {
		//bullets[i]が空でない場合
		if (bullets[i] != nullptr) {
			//更新処理
			bullets[i]->Update(_gameSystem);
		}
	}
}

//描画処理
void BulletManager::Draw(GameSystem* _gameSystem) {
	for (int i = 0; i < activeCount; i++) {
		//bullets[i]が空でない場合
		if (bullets[i] != nullptr) {
			//描画処理
			bullets[i]->Draw(_gameSystem);
		}
	}
}

//弾生成処理
void BulletManager::CreateBullet(float _x, float _y, eBulletType _type) {
	for (int i = 0; i < MAX_BULLET_NUM; i++) {
		//弾が空の場合
		if (bullets[i] == nullptr) {
			switch (_type) {
			//プレイヤーの弾を生成
			case eBulletType::Player:
				bullets[i] = new BulletP(_x - (16 / 2), _y, 16, 16, 5, "Player");
				return;
			//エネミーの弾を生成
			case eBulletType::Enemy_Normal:
				bullets[i] = new BulletE_Normal(_x - (16 / 2), _y, 16, 16, 5, "Enemy");
				return;
			default:
				break;
			}
		}
	}
}

//整理処理
void BulletManager::Organize() {
	int organizeCount = 0;	//整理カウンタ
	activeCount = 0;

	//アクティブな弾の数を求める
	for (int i = 0; i < MAX_BULLET_NUM; i++) {
		//bullets[i]が空でない場合
		if (bullets[i] != nullptr) {
			//bullets[i]がアクティブな場合
			if (bullets[i]->GetIsActive()) {
				//アクティブカウンタを加算
				activeCount++;
			}
		}
	}

	//整理の処理
	for (int i = 0; i < MAX_BULLET_NUM - 1; i++) {
		//bullets[i]が空の場合
		if (bullets[i] == nullptr) {
			for (int j = i + 1; j < MAX_BULLET_NUM; j++) {
				//bullets[j]が空でない場合
				if (bullets[j] != nullptr) {
					//入れ替え処理
					Bullet* tmpBullet = bullets[i];
					bullets[i] = bullets[j];
					bullets[j] = tmpBullet;

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
void BulletManager::Destroy() {
	for (int i = 0; i < activeCount; i++) {
		//bullets[i]が空でない場合
		if (bullets[i] != nullptr) {
			//bullets[i]がアクティブでない場合
			if (!bullets[i]->GetIsActive()) {
				delete bullets[i];
				bullets[i] = nullptr;
			}
		}
	}
}

//座標を取得する
Pos BulletManager::GetPos(int _num) {
	//bullets[i]が空でない場合
	if (bullets[_num] != nullptr) {
		return bullets[_num]->GetPos();
	}
}

//横幅を取得
float BulletManager::GetWidth(int _num) {
	//bullets[i]が空でない場合
	if (bullets[_num] != nullptr) {
		return bullets[_num]->GetWidth();
	}
}

//高さを取得
float BulletManager::GetHeight(int _num) {
	//bullets[i]が空でない場合
	if (bullets[_num] != nullptr) {
		return bullets[_num]->GetHeight();
	}
}

//アクティブ状態を取得する
bool BulletManager::GetIsActive(int _num) {
	//bullets[i]が空でない場合
	if (bullets[_num] != nullptr) {
		return bullets[_num]->GetIsActive();
	}
}

//タグを取得する
string BulletManager::GetTag(int _num) {
	//bullets[i]が空でない場合
	if (bullets[_num] != nullptr) {
		return bullets[_num]->GetTag();
	}
}

//アクティブフラグをセットする
void BulletManager::SetIsActive(int _num, bool _isActive) {
	//bullets[i]が空でない場合
	if (bullets[_num] != nullptr) {
		bullets[_num]->SetIsActive(_isActive);
	}
}