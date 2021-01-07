#include <DxLib.h>
#include "BulletP.h"

//コンストラクタ
BulletP::BulletP(float _x, float _y, float _width, float _height,
	float _moveSpeed, string _tag) :
	Bullet(_x, _y, _width, _height, _moveSpeed, _tag) {

}

//更新処理
void BulletP::Update(GameSystem* _gameSystem) {
	//画面外に弾が出た場合
	if (pos.y + height <= 0) {
		isActive = false;
		return;
	}

	pos.y -= moveSpeed;
}

//描画処理
void BulletP::Draw(GameSystem* _gameSystem) {
	DrawGraph(pos.x, pos.y, _gameSystem->GetImage()->GetGraph("Bullet_01.png"), TRUE);
}