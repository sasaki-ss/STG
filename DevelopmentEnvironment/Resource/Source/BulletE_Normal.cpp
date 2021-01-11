#include <DxLib.h>
#include "BulletE_Normal.h"

//コンストラクタ
BulletE_Normal::BulletE_Normal(float _x, float _y, float _width, float _height,
	float _moveSpeed, string _tag) :
	Bullet(_x, _y, _width, _height, _moveSpeed, _tag) {

}

//更新処理
void BulletE_Normal::Update(GameSystem* _gameSystem) {
	//画面外に弾が出た場合
	if (pos.y >= _gameSystem->GetGameArea().down) {
		isActive = false;
		return;
	}

	pos.y += moveSpeed;
}

//描画処理
void BulletE_Normal::Draw(GameSystem* _gameSystem) {
	DrawGraph(pos.x, pos.y, _gameSystem->GetImage()->GetGraph("Bullet_02.png"), TRUE);
}