#include <DxLib.h>
#include "Bullet.h"

//コンストラクタ
Bullet::Bullet(float _x, float _y, float _width, float _height,
	float _moveSpeed, string _tag) {
	pos.x = _x;
	pos.y = _y;
	width = _width;
	height = _height;
	pos.cx = pos.x + (width / 2);
	pos.cy = pos.y + (height / 2);
	moveSpeed = _moveSpeed;
	isActive = true;
	tag = _tag;
}

//更新処理
void Bullet::Update(GameSystem* _gameSystem) {
	//画面外に弾が出た場合
	if (pos.y + height <= 0) {
		isActive = false;
		return;
	}

	pos.y -= moveSpeed;
}

//描画処理
void Bullet::Draw(GameSystem* _gameSystem) {
	DrawGraph(pos.x, pos.y, _gameSystem->GetImage()->GetGraph("Bullet_01.png"), TRUE);
}